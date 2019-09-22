#include "namespacegenerator.h"
#include "ui_namespacegenerator.h"
namespace widgets {
NameSpaceGenerator::NameSpaceGenerator(QWidget *parent)
    : QWidget(parent), ui(new Ui::NameSpaceGenerator) {
  ui->setupUi(this);
}

NameSpaceGenerator::~NameSpaceGenerator() { delete ui; }
}  // namespace widgets
