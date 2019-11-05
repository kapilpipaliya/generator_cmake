/********************************************************************************
** Form generated from reading UI file 'stl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STL_H
#define UI_STL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stl
{
public:

    void setupUi(QWidget *Stl)
    {
        if (Stl->objectName().isEmpty())
            Stl->setObjectName(QString::fromUtf8("Stl"));
        Stl->resize(400, 300);

        retranslateUi(Stl);

        QMetaObject::connectSlotsByName(Stl);
    } // setupUi

    void retranslateUi(QWidget *Stl)
    {
        Stl->setWindowTitle(QCoreApplication::translate("Stl", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stl: public Ui_Stl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STL_H
