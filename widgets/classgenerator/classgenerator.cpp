#include "./classgenerator.h"
// https://api.kde.org/frameworks/kwidgetsaddons/html/classKEditListWidget.html
#include <KEditListWidget>
#include <QtWidgets>
namespace widgets {
ClassGenerator::ClassGenerator(QWidget *parent) : QWidget(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);

  auto vLayout = new QVBoxLayout(this);
  auto editlist = new KEditListWidget();
  vLayout->addWidget(editlist);
}

}  // namespace widgets
