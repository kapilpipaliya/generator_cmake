#include "wstest.h"
#include <QtDebug>
#include "../json.hpp"
#include "ui_wstest.h"
WsTest::WsTest(QWidget* parent) : QWidget(parent), ui(new Ui::WsTest) {
  ui->setupUi(this);
  QString url_ = ui->lineEdit_protocol->text() + ui->lineEdit_host->text() +
                 ":" + ui->lineEdit_port->text() +
                 ui->lineEdit_endpoint->text();
  m_url = QUrl(url_);
  qDebug() << url_;
  connect(&m_webSocket, &QWebSocket::connected, this, &WsTest::onConnected);
  connect(&m_webSocket, &QWebSocket::disconnected, this, &WsTest::closed);

  connect(&m_webSocket,
          QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
          [=, this](QAbstractSocket::SocketError error) {
            ui->label_status->setText(m_webSocket.errorString());
            qDebug() << m_webSocket.errorString();
          });

  m_webSocket.open(m_url);

  connect(ui->toolButton_connect, &QToolButton::clicked,
          [this]() { m_webSocket.open(m_url); });
  connect(ui->toolButton_send, &QToolButton::clicked,
          [this]() { m_webSocket.sendTextMessage(parseJson()); });
}

WsTest::~WsTest() { delete ui; }

void WsTest::onConnected() {
  qDebug() << "WebSocket connected";
  ui->label_status->setText("connected");
  connect(&m_webSocket, &QWebSocket::textMessageReceived, this,
          &WsTest::onTextMessageReceived);
  m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void WsTest::onTextMessageReceived(QString message) {
  qDebug() << "Message received:" << message;
  // m_webSocket.close();
  printReply(message);
}

QString WsTest::parseJson() {
  auto text = ui->plainTextEdit_input->toPlainText().toStdString();

  nlohmann::json input;
  try {
    // parsing input with a syntax error
    input = nlohmann::json::parse(
        ui->plainTextEdit_input->toPlainText().toStdString());
  } catch (nlohmann::json::parse_error& e) {
    // output exception information
    qDebug() << "message: " << e.what() << '\n'
             << "exception id: " << e.id << '\n'
             << "byte position of error: " << e.byte << "\n";
  }

  return QString::fromStdString(input.dump());
}

void WsTest::sendJsonMessage() {}

void WsTest::printReply(QString jsondump) {
  ui->plainTextEdit_output->setPlainText(jsondump);
}
