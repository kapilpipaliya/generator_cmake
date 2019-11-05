#include "./yamlgenerator.h"
#include <QDesktopServices>
#include <QtDebug>
#include "sqlite/orm.h"
#include "ui_yamlgenerator.h"
namespace widgets {
YamlGenerator::YamlGenerator(QWidget *parent)
    : QWidget(parent), ui(new Ui::YamlGenerator) {
  ui->setupUi(this);
  this->setAttribute(Qt::WA_DeleteOnClose);

  fileloadset();
  parseset();
  queryset();
  buildset();
  convertofrom();
  connect(ui->toolButton_inter_clear, &QToolButton::clicked,
          [this]() { ui->textEdit_inter->setText(""); });
}

YamlGenerator::~YamlGenerator() { delete ui; }

void YamlGenerator::fileloadset() {
  auto key = "loadfile";
  auto go = ui->toolButton_go_1;
  auto save = ui->toolButton_save_1;
  auto templ = ui->plainTextEdit_templ_1;

  auto var1 = ui->lineEdit_variable0;
  auto filename = ui->lineEdit_filename;

  auto slot = [this, var1, filename, templ]() {
    auto text = templ->toPlainText();
    auto newText = QString(text).arg(var1->text()).arg(filename->text());
    ui->textEdit_inter->setText(newText);
  };
  setGoSaveTemplate(key, templ->toPlainText(), go, save, templ, slot);
  connect(ui->lineEdit_filename, &QLineEdit::textChanged, this, slot);
}

void YamlGenerator::parseset() {
  auto key = "parse";
  auto go = ui->toolButton_go_2;
  auto save = ui->toolButton_save_2;
  auto templ = ui->plainTextEdit_templ_2;

  auto var1 = ui->lineEdit_variable;
  auto yamltext = ui->lineEdit_yamltext;

  auto slot = [this, var1, yamltext, templ]() {
    auto text = templ->toPlainText();
    auto newText = QString(text).arg(var1->text()).arg(yamltext->text());
    ui->textEdit_inter->setText(newText);
  };
  setGoSaveTemplate(key, templ->toPlainText(), go, save, templ, slot);
  //  connect(var1, &QLineEdit::textChanged, this, slot);
  //  connect(yamltext, &QLineEdit::textChanged, this, slot);
}

void YamlGenerator::queryset() {
  auto key = "query";
  auto go = ui->toolButton_go_3;
  auto save = ui->toolButton_save_3;
  auto templ = ui->plainTextEdit_templ_3;

  auto var1 = ui->lineEdit_variable;
  auto yamltext = ui->lineEdit_yamltext;

  auto slot = [this, var1, yamltext, templ]() {
    auto text = templ->toPlainText();
    auto newText = QString(text).arg(var1->text().arg(yamltext->text()));
    ui->textEdit_inter->setText(newText);
  };
  setGoSaveTemplate(key, templ->toPlainText(), go, save, templ, slot);
  //  connect(var1, &QLineEdit::textChanged, this, slot);
  //  connect(yamltext, &QLineEdit::textChanged, this, slot);
}

void YamlGenerator::buildset() {
  auto key = "build";
  auto go = ui->toolButton_go_4;
  auto save = ui->toolButton_save_4;
  auto templ = ui->plainTextEdit_templ_4;

  auto var1 = ui->lineEdit_variable;
  auto yamltext = ui->lineEdit_yamltext;

  auto slot = [this, var1, yamltext, templ]() {
    auto text = templ->toPlainText();
    auto newText = QString(text).arg(var1->text().arg(yamltext->text()));
    ui->textEdit_inter->setText(newText);
  };
  setGoSaveTemplate(key, templ->toPlainText(), go, save, templ, slot);
  //  connect(var1, &QLineEdit::textChanged, this, slot);
  //  connect(yamltext, &QLineEdit::textChanged, this, slot);
}

void YamlGenerator::convertofrom() {
  auto key = "convert";
  auto go = ui->toolButton_go_5;
  auto save = ui->toolButton_save_5;
  auto templ = ui->plainTextEdit_templ_5;

  auto var1 = ui->lineEdit_variable;
  auto yamltext = ui->lineEdit_yamltext;

  auto slot = [this, var1, yamltext, templ]() {
    auto text = templ->toPlainText();
    auto newText = QString(text).arg(var1->text().arg(yamltext->text()));
    ui->textEdit_inter->setText(newText);
  };
  setGoSaveTemplate(key, templ->toPlainText(), go, save, templ, slot);
  //  connect(var1, &QLineEdit::textChanged, this, slot);
  //  connect(yamltext, &QLineEdit::textChanged, this, slot);
}

void YamlGenerator::setGoSaveTemplate(QString key, QString default_value,
                                      QToolButton *go, QToolButton *save,
                                      QPlainTextEdit *templ,
                                      std::function<void()> slot) {
  auto template_text = load(key, default_value);
  templ->setPlainText(template_text);
  connect(templ, &QPlainTextEdit::textChanged, slot);
  connect(go, &QToolButton::clicked, slot);
  connect(save, &QToolButton::clicked,
          [key, templ, this]() { set(key, templ->toPlainText()); });
}

QString YamlGenerator::load(QString key, QString default_value) {
  auto value = get(key);
  if (value.isEmpty()) {
    set(key, default_value);
    return default_value;
  } else {
    return value;
  }
}

void YamlGenerator::set(QString key, QString value) {
  Orm::yamlSaveSetting(key.toStdString(), value.toStdString());
}

QString YamlGenerator::get(QString key) {
  return QString::fromStdString(Orm::yamlGetValue(key.toStdString()));
}

void YamlGenerator::on_pushButton_clicked() {
  QDesktopServices::openUrl(QUrl(
      "https://github.com/jbeder/yaml-cpp/wiki/Tutorial", QUrl::TolerantMode));
}
}  // namespace widgets
