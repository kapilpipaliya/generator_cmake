#include "namespacegenerator.h"
#include "ui_namespacegenerator.h"

NameSpaceGenerator::NameSpaceGenerator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameSpaceGenerator)
{
    ui->setupUi(this);
}

NameSpaceGenerator::~NameSpaceGenerator()
{
    delete ui;
}
