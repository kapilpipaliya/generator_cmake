/********************************************************************************
** Form generated from reading UI file 'wstest.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSTEST_H
#define UI_WSTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WsTest
{
public:
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_port;
    QLineEdit *lineEdit_host;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_endpoint;
    QLabel *label_4;
    QLineEdit *lineEdit_protocol;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_connect;
    QWidget *widget;
    QLabel *label_status;

    void setupUi(QWidget *WsTest)
    {
        if (WsTest->objectName().isEmpty())
            WsTest->setObjectName(QString::fromUtf8("WsTest"));
        WsTest->resize(958, 654);
        verticalLayout_5 = new QVBoxLayout(WsTest);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scrollArea = new QScrollArea(WsTest);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 938, 634));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_port = new QLineEdit(groupBox);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 2, 1, 1, 1);

        lineEdit_host = new QLineEdit(groupBox);
        lineEdit_host->setObjectName(QString::fromUtf8("lineEdit_host"));

        gridLayout->addWidget(lineEdit_host, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_endpoint = new QLineEdit(groupBox);
        lineEdit_endpoint->setObjectName(QString::fromUtf8("lineEdit_endpoint"));

        gridLayout->addWidget(lineEdit_endpoint, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_protocol = new QLineEdit(groupBox);
        lineEdit_protocol->setObjectName(QString::fromUtf8("lineEdit_protocol"));

        gridLayout->addWidget(lineEdit_protocol, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        toolButton_connect = new QToolButton(groupBox);
        toolButton_connect->setObjectName(QString::fromUtf8("toolButton_connect"));

        horizontalLayout_6->addWidget(toolButton_connect);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBox);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_4->addWidget(widget);

        label_status = new QLabel(scrollAreaWidgetContents);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        verticalLayout_4->addWidget(label_status);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        retranslateUi(WsTest);

        QMetaObject::connectSlotsByName(WsTest);
    } // setupUi

    void retranslateUi(QWidget *WsTest)
    {
        WsTest->setWindowTitle(QCoreApplication::translate("WsTest", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WsTest", "GroupBox", nullptr));
        lineEdit_port->setText(QCoreApplication::translate("WsTest", "8400", nullptr));
        lineEdit_host->setText(QCoreApplication::translate("WsTest", "localhost", nullptr));
        label_2->setText(QCoreApplication::translate("WsTest", "port", nullptr));
        label_3->setText(QCoreApplication::translate("WsTest", "endpoint", nullptr));
        label->setText(QCoreApplication::translate("WsTest", "host:", nullptr));
        lineEdit_endpoint->setText(QCoreApplication::translate("WsTest", "/todo", nullptr));
        label_4->setText(QCoreApplication::translate("WsTest", "protocol:", nullptr));
        lineEdit_protocol->setText(QCoreApplication::translate("WsTest", "ws://", nullptr));
        toolButton_connect->setText(QCoreApplication::translate("WsTest", "C", nullptr));
        label_status->setText(QCoreApplication::translate("WsTest", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WsTest: public Ui_WsTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSTEST_H
