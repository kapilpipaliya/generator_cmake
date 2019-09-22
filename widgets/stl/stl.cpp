#include "stl.h"
#include "ui_stl.h"
namespace widgets {
Stl::Stl(QWidget *parent) : QWidget(parent), ui(new Ui::Stl) {
  ui->setupUi(this);
}

Stl::~Stl() { delete ui; }
}  // namespace widgets
