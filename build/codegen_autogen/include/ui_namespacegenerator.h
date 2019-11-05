/********************************************************************************
** Form generated from reading UI file 'namespacegenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMESPACEGENERATOR_H
#define UI_NAMESPACEGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NameSpaceGenerator
{
public:

    void setupUi(QWidget *NameSpaceGenerator)
    {
        if (NameSpaceGenerator->objectName().isEmpty())
            NameSpaceGenerator->setObjectName(QString::fromUtf8("NameSpaceGenerator"));
        NameSpaceGenerator->resize(400, 300);

        retranslateUi(NameSpaceGenerator);

        QMetaObject::connectSlotsByName(NameSpaceGenerator);
    } // setupUi

    void retranslateUi(QWidget *NameSpaceGenerator)
    {
        NameSpaceGenerator->setWindowTitle(QCoreApplication::translate("NameSpaceGenerator", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NameSpaceGenerator: public Ui_NameSpaceGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMESPACEGENERATOR_H
