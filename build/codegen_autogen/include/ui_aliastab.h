/********************************************************************************
** Form generated from reading UI file 'aliastab.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALIASTAB_H
#define UI_ALIASTAB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AliasTab
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_Aliases;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AliasAdd;
    QPushButton *pushButton_AliasRemove;
    QVBoxLayout *verticalLayout_SuggestionAliases;

    void setupUi(QWidget *AliasTab)
    {
        if (AliasTab->objectName().isEmpty())
            AliasTab->setObjectName(QString::fromUtf8("AliasTab"));
        AliasTab->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AliasTab->sizePolicy().hasHeightForWidth());
        AliasTab->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(AliasTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(AliasTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 280));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_Aliases = new QTableWidget(scrollAreaWidgetContents);
        tableWidget_Aliases->setObjectName(QString::fromUtf8("tableWidget_Aliases"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_Aliases->sizePolicy().hasHeightForWidth());
        tableWidget_Aliases->setSizePolicy(sizePolicy1);
        tableWidget_Aliases->setFrameShadow(QFrame::Plain);

        verticalLayout_2->addWidget(tableWidget_Aliases);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_AliasAdd = new QPushButton(scrollAreaWidgetContents);
        pushButton_AliasAdd->setObjectName(QString::fromUtf8("pushButton_AliasAdd"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("list-add");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_AliasAdd->setIcon(icon);

        horizontalLayout->addWidget(pushButton_AliasAdd);

        pushButton_AliasRemove = new QPushButton(scrollAreaWidgetContents);
        pushButton_AliasRemove->setObjectName(QString::fromUtf8("pushButton_AliasRemove"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("list-remove");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_AliasRemove->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_AliasRemove);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_SuggestionAliases = new QVBoxLayout();
        verticalLayout_SuggestionAliases->setObjectName(QString::fromUtf8("verticalLayout_SuggestionAliases"));

        verticalLayout_2->addLayout(verticalLayout_SuggestionAliases);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(AliasTab);

        QMetaObject::connectSlotsByName(AliasTab);
    } // setupUi

    void retranslateUi(QWidget *AliasTab)
    {
        AliasTab->setWindowTitle(QCoreApplication::translate("AliasTab", "Form", nullptr));
        pushButton_AliasAdd->setText(QCoreApplication::translate("AliasTab", "Add Alias", nullptr));
        pushButton_AliasRemove->setText(QCoreApplication::translate("AliasTab", "Remove Alias(es)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AliasTab: public Ui_AliasTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALIASTAB_H
