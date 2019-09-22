#include "jsongenerator.h"
#include "ui_jsongenerator.h"

JsonGenerator::JsonGenerator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonGenerator)
{
    ui->setupUi(this);
}

JsonGenerator::~JsonGenerator()
{
    delete ui;
}
