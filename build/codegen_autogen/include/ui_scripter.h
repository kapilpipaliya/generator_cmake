/********************************************************************************
** Form generated from reading UI file 'scripter.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTER_H
#define UI_SCRIPTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scripter
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *Scripter)
    {
        if (Scripter->objectName().isEmpty())
            Scripter->setObjectName(QString::fromUtf8("Scripter"));
        Scripter->resize(450, 28);
        centralWidget = new QWidget(Scripter);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        Scripter->setCentralWidget(centralWidget);

        retranslateUi(Scripter);

        QMetaObject::connectSlotsByName(Scripter);
    } // setupUi

    void retranslateUi(QMainWindow *Scripter)
    {
        Scripter->setWindowTitle(QCoreApplication::translate("Scripter", "Scripter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scripter: public Ui_Scripter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTER_H
