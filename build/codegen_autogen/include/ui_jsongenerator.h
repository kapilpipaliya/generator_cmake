/********************************************************************************
** Form generated from reading UI file 'jsongenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONGENERATOR_H
#define UI_JSONGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JsonGenerator
{
public:

    void setupUi(QWidget *JsonGenerator)
    {
        if (JsonGenerator->objectName().isEmpty())
            JsonGenerator->setObjectName(QString::fromUtf8("JsonGenerator"));
        JsonGenerator->resize(400, 300);

        retranslateUi(JsonGenerator);

        QMetaObject::connectSlotsByName(JsonGenerator);
    } // setupUi

    void retranslateUi(QWidget *JsonGenerator)
    {
        JsonGenerator->setWindowTitle(QCoreApplication::translate("JsonGenerator", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JsonGenerator: public Ui_JsonGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONGENERATOR_H
