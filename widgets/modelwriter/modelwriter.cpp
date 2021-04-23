// Note using id of table is a bug here.
#include "./modelwriter.h"
#include "ui_modelwriter.h"
#include <QCXXHighlighter>
#include <QCodeEditor>
#include <QGLSLCompleter>
#include <QGLSLHighlighter>
#include <QJSONHighlighter>
#include <QSyntaxStyle>
#include <QXMLHighlighter>
#include <QLabel>
#include <QSortFilterProxyModel>
#include <QtDebug>
#include "data.h"
#include "sqlite/orm.h"
#include "treeitem.h"
namespace widgets
{
ModelWriter::ModelWriter(QWidget *parent) : QWidget(parent), ui(new Ui::ModelWriter)
{
  ui->setupUi(this);
  this->setAttribute(Qt::WA_DeleteOnClose);
  // Create a QSortFilterProxyModel and setModel() of the QTableView to it.
  sourceModel = new Data(this);
  proxyModel = new QSortFilterProxyModel(this);
  proxyModel->setSourceModel(sourceModel);
  ui->treeView->setModel(proxyModel);
  //  ui->treeView->setModel(sourceModel);
  //  ui->treeView->setColumnWidth(0, 500);
  ui->treeView->resizeColumnToContents(0);
  //  ui->treeView->resizeColumnToContents(1);
  //  ui->treeView->resizeColumnToContents(2);
  /*auto settings = storage.get_all<DrogonModelSetting>();
  auto *verticalLayout1 = new QVBoxLayout();
  for (auto &setting : settings) {
    auto key = QString::fromStdString(setting.key);
    auto value = QString::fromStdString(setting.template_string);
    auto groupbox = groupboxCreate(key, value);

    verticalLayout1->addWidget(groupbox);
  }*/
  auto *verticalLayout2 = new QVBoxLayout();
  auto keyvalHbox = new QHBoxLayout();
  auto keylabel = new QLabel(this);
  keylabel->setText("Key:");
  auto valuelabel = new QLabel(this);
  valuelabel->setText("Value:");
  auto key = new QLineEdit(this);
  auto value = new QLineEdit(this);
  auto addbutton = new QToolButton(this);
  addbutton->setText("Add");
  keyvalHbox->addWidget(keylabel);
  keyvalHbox->addWidget(key);
  keyvalHbox->addWidget(valuelabel);
  keyvalHbox->addWidget(value);
  keyvalHbox->addWidget(addbutton);
  verticalLayout2->addLayout(keyvalHbox);
  auto *verticalLayout = new QVBoxLayout();
  /*verticalLayout->addLayout(verticalLayout1);
  verticalLayout->addLayout(verticalLayout2);
  ui->widget->setLayout(verticalLayout);
  connect(addbutton, &QToolButton::clicked, [this, verticalLayout1, key, value]() {
    auto groupbox = groupboxCreate(key->text(), value->text());
    verticalLayout1->addWidget(groupbox);
    key->setText("");
    value->setText("");
  });*/
  //------
  connect(ui->toolButton_filter_clear, &QToolButton::clicked, [this]() {
    // Set the string you want to filter on using setFilterFixedString()
    // or setFilterRegExp() in your QSortFilterProxyModel
    proxyModel->setFilterRegExp("");
    ui->lineEdit_filter->setText("");
  });
  connect(ui->toolButton_all, &QToolButton::clicked, [this]() {
    for (int i = 0; i < proxyModel->rowCount(); ++i)
    {
      // on_treeView_doubleClicked(proxyModel->index(i, 0));
    }
  });
}
ModelWriter::~ModelWriter() { delete ui; }
QString ModelWriter::toCamelCase(QString &s)
{
  // https://wiki.qt.io/Converting_Strings_from_and_to_Camel_Case
  s.replace(0, 1, s[0].toUpper());
  QStringList parts = s.split('_', QString::SkipEmptyParts);
  for (int i = 1; i < parts.size(); ++i) parts[i].replace(0, 1, parts[i][0].toUpper());
  return parts.join("");
}
void ModelWriter::setGoSaveTemplate(
    QString key, QString default_value, QToolButton *go, QToolButton *save, QToolButton *delete_button, QGroupBox *box, QCodeEditor *templ, QCodeEditor *result, std::function<void()> slot)
{
  auto template_text = load(key, default_value);
  templ->setPlainText(template_text);
  connect(templ, &QTextEdit::textChanged, slot);
  connect(go, &QToolButton::clicked, slot);
  connect(save, &QToolButton::clicked, [key, templ, this]() { set(key, templ->toPlainText()); });
  auto tree = connect(ui->treeView, &QTreeView::clicked, slot);
  connect(delete_button, &QToolButton::clicked, [key, box, &templ, &result, tree]() {
    Orm::drogonModelRemoveValue(key.toStdString());
    box->deleteLater();
    result = nullptr;
    templ = nullptr;
    disconnect(tree);
  });
}
void ModelWriter::setTemplResult(QCodeEditor *templ, QCodeEditor *result)
{
  auto index = ui->treeView->currentIndex();
  auto text = index.data().toString();
  auto table = index.data().toString();
  auto rows = 0;
  if (index.model()) { rows = index.model()->rowCount(index); }
  QString columns;
  for (int i = 0; i < rows; ++i)
  {
    auto column = proxyModel->index(i, 0, index).data().toString();
    auto type = proxyModel->index(i, 1, index).data().toString();
    auto default_ = proxyModel->index(i, 2, index).data().toString();
    auto isnull = proxyModel->index(i, 3, index).data().toString();
    auto value = "";
    if (type == "timestamp_without_time_zone") { value = "trantor::Date::now()"; }
    columns += text.toLower() + ".set" + toCamelCase(column) + "(" + value + "); //" + type + " " + default_ + " " + isnull + ";\n";
  }
  QString new_result;
  if (templ) { new_result = QString(templ->toPlainText()).arg(toCamelCase(text)).arg(text.toLower()).arg(columns); }
  if (result) { result->setPlainText(new_result); }
}
QString ModelWriter::load(QString key, QString default_value)
{
  auto value = get(key);
  if (value.isEmpty())
  {
    set(key, default_value);
    return default_value;
  }
  else
  {
    return value;
  }
}
void ModelWriter::set(QString key, QString value) { Orm::drogonModelSaveSetting(key.toStdString(), value.toStdString()); }
QString ModelWriter::get(QString key) { return QString::fromStdString(Orm::drogonModelGetValue(key.toStdString())); }
void ModelWriter::cppeditor(QCodeEditor *editor)
{
  // https://github.com/Megaxela/QCodeEditor/
  editor->setHighlighter(new QCXXHighlighter);
  ui->textEdit_final->setHighlighter(new QCXXHighlighter);
  editor->setTabReplaceSize(2);
  ui->textEdit_final->setTabReplaceSize(2);
  editor->setWordWrapMode(QTextOption::NoWrap);
  ui->textEdit_final->setWordWrapMode(QTextOption::NoWrap);
}
QGroupBox *ModelWriter::groupboxCreate(QString key, QString value)
{
  auto groupbox = new QGroupBox(this);
  groupbox->setTitle(key);
  auto groupVBox = new QVBoxLayout(groupbox);
  auto buttonHLayout = new QHBoxLayout();
  auto clearButton = new QToolButton(this);
  clearButton->setText("*");
  auto goButton = new QToolButton(this);
  goButton->setText("Go");
  auto saveButton = new QToolButton(this);
  saveButton->setText("save");
  auto deleteButton = new QToolButton(this);
  deleteButton->setText("delete");
  auto horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  buttonHLayout->addItem(horizontalSpacer);
  buttonHLayout->addWidget(clearButton);
  buttonHLayout->addWidget(goButton);
  buttonHLayout->addWidget(saveButton);
  buttonHLayout->addWidget(deleteButton);
  groupVBox->addLayout(buttonHLayout);
  QHBoxLayout *horizontalLayout = new QHBoxLayout();
  auto templ = new QCodeEditor(this);
  auto result = new QCodeEditor(this);
  result->setObjectName(QString::fromUtf8("result"));
  horizontalLayout->addWidget(templ);
  horizontalLayout->addWidget(result);
  cppeditor(templ);
  cppeditor(result);
  groupVBox->addLayout(horizontalLayout);
  auto slot = [this, templ, result]() { setTemplResult(templ, result); };
  setGoSaveTemplate(key, value, goButton, saveButton, deleteButton, groupbox, templ, result, slot);
  return groupbox;
}
void ModelWriter::on_lineEdit_filter_textEdited(const QString &arg1)
{
  // Set the string you want to filter on using setFilterFixedString() or
  // setFilterRegExp() in your QSortFilterProxyModel
  proxyModel->setFilterRegExp(arg1);
}
}  // namespace widgets
