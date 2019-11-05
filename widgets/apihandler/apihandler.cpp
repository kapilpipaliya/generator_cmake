// Todo api helper
#include "./apihandler.h"
#include <QApplication>
#include <QClipboard>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
namespace widgets {
ApiHandler::ApiHandler(QWidget *parent) : QWidget(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  auto *widget = new QWidget;
  QHBoxLayout *horizontalLayout = new QHBoxLayout(widget);
  horizontalLayout->setSpacing(6);
  horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
  horizontalLayout->setContentsMargins(0, 0, 0, 0);
  auto *nameLabel = new QLabel(widget);
  nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
  auto *nameEdit = new QLineEdit(widget);
  nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
  auto *prefixTextEdit = new QLineEdit(widget);
  prefixTextEdit->setObjectName(QString::fromUtf8("prefixTextEdit"));
  auto *numberLabel = new QLabel(widget);
  numberLabel->setObjectName(QString::fromUtf8("numberLabel"));
  auto *numberEdit = new QSpinBox(widget);
  numberEdit->setObjectName(QString::fromUtf8("numberEdit"));
  auto *suffixTextEdit = new QLineEdit(widget);
  suffixTextEdit->setObjectName(QString::fromUtf8("suffixTextEdit"));
  auto *resultTextEdit = new QLineEdit(widget);
  resultTextEdit->setObjectName(QString::fromUtf8("resultTextEdit"));
  auto *copyButton = new QToolButton(widget);
  copyButton->setObjectName(QString::fromUtf8("copyButton"));
  copyButton->setText("copy");
  horizontalLayout->addWidget(nameLabel);
  horizontalLayout->addWidget(prefixTextEdit);
  horizontalLayout->addWidget(nameEdit);
  horizontalLayout->addWidget(numberLabel);
  horizontalLayout->addWidget(numberEdit);
  horizontalLayout->addWidget(suffixTextEdit);
  horizontalLayout->addWidget(resultTextEdit);
  horizontalLayout->addWidget(copyButton);

  auto slot = [nameEdit, numberEdit, prefixTextEdit, suffixTextEdit,
               resultTextEdit]() {
    auto name = nameEdit->text();
    auto number = numberEdit->value();
    auto prefixtext = prefixTextEdit->text();
    auto suffixtext = suffixTextEdit->text();
    auto result = prefixtext + name + QString::number(number) + suffixtext;
    resultTextEdit->setText(result);
  };
  connect(nameEdit, &QLineEdit::textChanged, slot);
  connect(numberEdit, QOverload<int>::of(&QSpinBox::valueChanged), slot);
  connect(prefixTextEdit, &QLineEdit::textChanged, slot);
  connect(suffixTextEdit, &QLineEdit::textChanged, slot);
  //  cofnnect(textEdit, &QLineEdit::textChanged, slot);
  connect(copyButton, &QToolButton::clicked, [numberEdit, resultTextEdit]() {
    auto number = numberEdit->value();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(resultTextEdit->text());
    numberEdit->setValue(number + 1);
  });

  widget->show();
}
}  // namespace widgets
