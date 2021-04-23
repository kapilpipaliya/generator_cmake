// TODO: on number change not change payload, but make seperate button for it
#include "./wstest.h"
#include <QtDebug>
#include <json.hpp>
#include "ui_wstest.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "sqlite/orm.h"
WsTest::WsTest(QWidget *parent) : QWidget(parent), ui(new Ui::WsTest)
{
  ui->setupUi(this);
  this->setAttribute(Qt::WA_DeleteOnClose);
  connectWs();
  //  setUrl();
  //  m_webSocket.open(m_url);
  auto connectPressed = [this]() {
    switch (m_webSocket.state())
    {
      case QAbstractSocket::SocketState::UnconnectedState:
      case QAbstractSocket::SocketState::HostLookupState:
      case QAbstractSocket::SocketState::ConnectingState:
        setUrl();
        m_webSocket.open(m_url);
        break;
      case QAbstractSocket::SocketState::ConnectedState:
      case QAbstractSocket::SocketState::BoundState:
      case QAbstractSocket::SocketState::ListeningState:
      case QAbstractSocket::SocketState::ClosingState: m_webSocket.close(); break;
    }
  };
  connect(ui->toolButton_connect, &QToolButton::clicked, connectPressed);
  connectPressed();
  /*auto settings = storage.get_all<WsTestSettingSetting>();
  auto *verticalLayout1 = new QVBoxLayout();
  for (auto &setting : settings) {
    auto number = setting.number;
    auto event_name = QString::fromStdString(setting.event_name);
    auto arg = QString::fromStdString(setting.arg);
    auto payload = QString::fromStdString(setting.payload);
    auto result = QString::fromStdString(setting.result);
    auto groupbox =
        addTest(setting.id, number, event_name, arg, payload, result);

    verticalLayout1->addWidget(groupbox);
  }*/
  auto *verticalLayout2 = new QVBoxLayout();
  auto keyvalHbox = new QHBoxLayout();
  auto spinboxlabel = new QLabel(this);
  spinboxlabel->setText("Number:");
  auto spinboxEdit = new QSpinBox(this);
  auto eventLabel = new QLabel(this);
  eventLabel->setText("Event");
  auto event_nameEdit = new QLineEdit();
  auto argLabel = new QLabel(this);
  argLabel->setText("Args:");
  auto argEdit = new QPlainTextEdit();
  auto payloadlabel = new QLabel(this);
  payloadlabel->setText("Payload:");
  auto payloadEdit = new QPlainTextEdit(this);
  auto valuelabel = new QLabel(this);
  valuelabel->setText("Result:");
  auto valueEdit = new QPlainTextEdit(this);
  auto addbutton = new QToolButton(this);
  addbutton->setText("Add");
  keyvalHbox->addWidget(spinboxlabel);
  keyvalHbox->addWidget(spinboxEdit);
  keyvalHbox->addWidget(eventLabel);
  keyvalHbox->addWidget(event_nameEdit);
  keyvalHbox->addWidget(argLabel);
  keyvalHbox->addWidget(argEdit);
  keyvalHbox->addWidget(payloadlabel);
  keyvalHbox->addWidget(payloadEdit);
  keyvalHbox->addWidget(valuelabel);
  keyvalHbox->addWidget(valueEdit);
  keyvalHbox->addWidget(addbutton);
  verticalLayout2->addLayout(keyvalHbox);
  auto *verticalLayout = new QVBoxLayout();
  /*verticalLayout->addLayout(verticalLayout1);
  verticalLayout->addLayout(verticalLayout2);
  ui->widget->setLayout(verticalLayout);
  connect(addbutton, &QToolButton::clicked, [this, verticalLayout1, spinboxEdit, event_nameEdit, argEdit, payloadEdit, valueEdit]() {
    auto number = spinboxEdit->value();
    auto event_name = event_nameEdit->text();
    auto arg = argEdit->toPlainText();
    auto payload = payloadEdit->toPlainText();
    auto value = valueEdit->toPlainText();
    auto w = Orm::wstestSaveSetting(number, event_name.toStdString(), arg.toStdString(), payload.toStdString(), value.toStdString());
    auto groupbox = addTest(w.id, number, event_name, arg, payload, value);
    verticalLayout1->addWidget(groupbox);
    event_nameEdit->setText("");
    valueEdit->setPlainText("");
  });*/
}
void WsTest::setUrl()
{
  QString url_ = ui->lineEdit_protocol->text() + ui->lineEdit_host->text() + ":" + ui->lineEdit_port->text() + ui->lineEdit_endpoint->text();
  m_url = QUrl(url_);
  qDebug() << url_;
}
void WsTest::connectWs()
{
  connect(&m_webSocket, &QWebSocket::connected, this, &WsTest::onConnected);
  connect(&m_webSocket, &QWebSocket::disconnected, this, &WsTest::onclosed);
  connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &WsTest::onTextMessageReceived);
  connect(&m_webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), [=, this](QAbstractSocket::SocketError error) {
    ui->label_status->setText(m_webSocket.errorString());
    qDebug() << m_webSocket.errorString();
  });
}
WsTest::~WsTest()
{
  delete ui;
  ui = nullptr;
}
void WsTest::onConnected()
{
  ui->label_status->setText("connected");
  ui->toolButton_connect->setText("disconnect");
}
void WsTest::onclosed()
{
  if (ui)
  {
    ui->label_status->setText("disconnected");
    ui->toolButton_connect->setText("connect");
  }
}
void WsTest::reConnect()
{
  switch (m_webSocket.state())
  {
    case QAbstractSocket::SocketState::UnconnectedState:
    case QAbstractSocket::SocketState::ClosingState:
      setUrl();
      m_webSocket.open(m_url);
      break;
    default: break;
  }
}
QGroupBox *WsTest::addTest(int id, int number, QString event_name, QString arg, QString payload, QString result)
{
  auto groupbox = new QGroupBox(this);
  auto horizontalLayout1 = new QHBoxLayout(groupbox);
  horizontalLayout1->setObjectName(QString::fromUtf8("horizontalLayout1"));
  horizontalLayout1->setContentsMargins(0, 0, 0, 0);
  auto groupBox_send = new QGroupBox(this);
  groupBox_send->setTitle("Send");
  groupBox_send->setObjectName(QString::fromUtf8("groupBox_send"));
  auto verticalLayout_1 = new QVBoxLayout(groupBox_send);
  verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout"));
  auto horizontalLayout_sendbuttons = new QHBoxLayout();
  horizontalLayout_sendbuttons->setObjectName(QString::fromUtf8("horizontalLayout_send"));
  auto toolButton_input_clear = new QToolButton(groupBox_send);
  toolButton_input_clear->setText("*");
  toolButton_input_clear->setObjectName(QString::fromUtf8("toolButton_input_clear"));
  auto spinbox_id = new QSpinBox();
  spinbox_id->setValue(id);
  spinbox_id->setDisabled(true);
  auto goButton = new QToolButton(this);
  goButton->setText("Go");
  auto saveButton = new QToolButton(this);
  saveButton->setText("save");
  auto deleteButton = new QToolButton(this);
  deleteButton->setText("delete");
  auto horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout_sendbuttons->addItem(horizontalSpacer);
  horizontalLayout_sendbuttons->addWidget(spinbox_id);
  horizontalLayout_sendbuttons->addWidget(toolButton_input_clear);
  horizontalLayout_sendbuttons->addWidget(goButton);
  horizontalLayout_sendbuttons->addWidget(saveButton);
  horizontalLayout_sendbuttons->addWidget(deleteButton);
  verticalLayout_1->addLayout(horizontalLayout_sendbuttons);
  auto keyvalHbox = new QHBoxLayout();
  auto spinboxlabel = new QLabel(groupBox_send);
  spinboxlabel->setText("Number:");
  auto spinboxEdit = new QSpinBox(groupBox_send);
  spinboxEdit->setValue(number);
  auto eventLabel = new QLabel(groupBox_send);
  eventLabel->setText("Event");
  auto event_nameEdit = new QLineEdit(groupBox_send);
  event_nameEdit->setText(event_name);
  auto argLabel = new QLabel(groupBox_send);
  argLabel->setText("Args:");
  auto argEdit = new QPlainTextEdit(groupBox_send);
  argEdit->setPlainText(arg);
  auto payloadlabel = new QLabel(groupBox_send);
  payloadlabel->setText("Payload:");
  auto payloadEdit = new QPlainTextEdit(groupBox_send);
  payloadEdit->setPlainText(payload);
  keyvalHbox->addWidget(spinboxlabel);
  keyvalHbox->addWidget(spinboxEdit);
  keyvalHbox->addWidget(eventLabel);
  keyvalHbox->addWidget(event_nameEdit);
  keyvalHbox->addWidget(argLabel);
  keyvalHbox->addWidget(argEdit);
  keyvalHbox->addWidget(payloadlabel);
  keyvalHbox->addWidget(payloadEdit);
  verticalLayout_1->addItem(keyvalHbox);
  QLabel *validJson = new QLabel();
  verticalLayout_1->addWidget(validJson);
  auto payloadSlot = [spinboxEdit, argEdit, payloadEdit, this, validJson]() {
    QString out;
    out += "[[[" + QString::number(spinboxEdit->value()) + ", 0]," + argEdit->toPlainText() + "]]";
    payloadEdit->setPlainText(out);
    parseJson(payloadEdit->toPlainText(), validJson);
  };
  connect(spinboxEdit, QOverload<int>::of(&QSpinBox::valueChanged), payloadSlot);
  connect(argEdit, &QPlainTextEdit::textChanged, payloadSlot);
  horizontalLayout1->addWidget(groupBox_send);
  auto groupBox_result = new QGroupBox(this);
  groupBox_result->setTitle("Output");
  groupBox_result->setObjectName(QString::fromUtf8("groupBox_result"));
  auto verticalLayout_2 = new QVBoxLayout(groupBox_result);
  verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
  auto horizontalLayout_result = new QHBoxLayout();
  horizontalLayout_result->setObjectName(QString::fromUtf8("horizontalLayout_result"));
  auto toolButton_output_clear = new QToolButton(groupBox_result);
  toolButton_output_clear->setText("*");
  toolButton_output_clear->setObjectName(QString::fromUtf8("toolButton_output_clear"));
  horizontalLayout_result->addWidget(toolButton_output_clear);
  verticalLayout_2->addLayout(horizontalLayout_result);
  auto plainTextEdit_output = new QPlainTextEdit(groupBox_result);
  plainTextEdit_output->setObjectName(QString::fromUtf8("plainTextEdit_output"));
  plainTextEdit_output->setPlainText(result);
  verticalLayout_2->addWidget(plainTextEdit_output);
  horizontalLayout1->addWidget(groupBox_result);
  auto slot = [plainTextEdit_output, this]() { replyedit = plainTextEdit_output; };
  setGoSaveTemplate(id, goButton, saveButton, deleteButton, groupbox, spinboxEdit, event_nameEdit, argEdit, payloadEdit, plainTextEdit_output, slot);
  connect(goButton, &QToolButton::clicked, [this, payloadEdit, plainTextEdit_output, validJson]() {
    replyedit = plainTextEdit_output;
    reConnect();
    m_webSocket.sendTextMessage(parseJson(payloadEdit->toPlainText(), validJson));
  });
  connect(toolButton_input_clear, &QToolButton::clicked, [payloadEdit]() { payloadEdit->clear(); });
  connect(toolButton_output_clear, &QToolButton::clicked, [plainTextEdit_output]() { plainTextEdit_output->clear(); });
  return groupbox;
}
void WsTest::onTextMessageReceived(QString message) { printReply(message); }
void WsTest::setGoSaveTemplate(int id,
                               QToolButton *go,
                               QToolButton *save,
                               QToolButton *delete_button,
                               QGroupBox *box,
                               QSpinBox *spinbox,
                               QLineEdit *event_nameEdit,
                               QPlainTextEdit *argEdit,
                               QPlainTextEdit *payload,
                               QPlainTextEdit *templ,
                               std::function<void()> slot)
{
  connect(go, &QToolButton::clicked, slot);
  connect(save, &QToolButton::clicked, [id, spinbox, event_nameEdit, argEdit, payload, templ]() {
    Orm::wstestUpdateSetting(
        id, spinbox->value(), event_nameEdit->text().toStdString(), argEdit->toPlainText().toStdString(), payload->toPlainText().toStdString(), templ->toPlainText().toStdString());
  });
  connect(delete_button, &QToolButton::clicked, [id, box]() {
    Orm::wstestRemoveValue(id);
    box->deleteLater();
  });
}
QString WsTest::parseJson(QString text, QLabel *validateJson)
{
  nlohmann::json input;
  try
  {
    // parsing input with a syntax error
    input = nlohmann::json::parse(text.toStdString());
    validateJson->setText("Valid Json");
  }
  catch (nlohmann::json::parse_error &e)
  {
    // output exception information
    validateJson->setText("Invalid Json");
    qDebug() << "message: " << e.what() << '\n' << "exception id: " << e.id << '\n' << "byte position of error: " << e.byte << "\n";
  }
  return QString::fromStdString(input.dump());
}
void WsTest::sendJsonMessage() {}
void WsTest::printReply(QString jsondump)
{
  if (replyedit) { replyedit->setPlainText(jsondump); }
}
