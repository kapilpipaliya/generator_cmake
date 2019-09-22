#include "jsongenerator.h"
#include "ui_jsongenerator.h"
namespace widgets {

JsonGenerator::JsonGenerator(QWidget *parent)
    : QWidget(parent), ui(new Ui::JsonGenerator) {
  ui->setupUi(this);
}

JsonGenerator::~JsonGenerator() { delete ui; }

}  // namespace widgets
