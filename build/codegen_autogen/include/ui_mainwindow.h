/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QCodeEditor>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionclient;
    QAction *action_exit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_filter;
    QToolButton *toolButton_filter_clear;
    QToolButton *toolButton_all;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_textedit_inter_clear;
    QCodeEditor *textEdit_inter;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_template_clear;
    QPlainTextEdit *plainTextEdit_template;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_lineedit_all_clear;
    QCodeEditor *textEdit_final;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(929, 610);
        actionclient = new QAction(MainWindow);
        actionclient->setObjectName(QString::fromUtf8("actionclient"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_filter = new QLineEdit(centralWidget);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        horizontalLayout->addWidget(lineEdit_filter);

        toolButton_filter_clear = new QToolButton(centralWidget);
        toolButton_filter_clear->setObjectName(QString::fromUtf8("toolButton_filter_clear"));

        horizontalLayout->addWidget(toolButton_filter_clear);

        toolButton_all = new QToolButton(centralWidget);
        toolButton_all->setObjectName(QString::fromUtf8("toolButton_all"));

        horizontalLayout->addWidget(toolButton_all);


        verticalLayout->addLayout(horizontalLayout);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_textedit_inter_clear = new QToolButton(centralWidget);
        toolButton_textedit_inter_clear->setObjectName(QString::fromUtf8("toolButton_textedit_inter_clear"));

        horizontalLayout_2->addWidget(toolButton_textedit_inter_clear);


        verticalLayout_3->addLayout(horizontalLayout_2);

        textEdit_inter = new QCodeEditor(centralWidget);
        textEdit_inter->setObjectName(QString::fromUtf8("textEdit_inter"));

        verticalLayout_3->addWidget(textEdit_inter);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        toolButton_template_clear = new QToolButton(centralWidget);
        toolButton_template_clear->setObjectName(QString::fromUtf8("toolButton_template_clear"));

        horizontalLayout_4->addWidget(toolButton_template_clear);


        verticalLayout_3->addLayout(horizontalLayout_4);

        plainTextEdit_template = new QPlainTextEdit(centralWidget);
        plainTextEdit_template->setObjectName(QString::fromUtf8("plainTextEdit_template"));

        verticalLayout_3->addWidget(plainTextEdit_template);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton_lineedit_all_clear = new QToolButton(centralWidget);
        toolButton_lineedit_all_clear->setObjectName(QString::fromUtf8("toolButton_lineedit_all_clear"));

        horizontalLayout_3->addWidget(toolButton_lineedit_all_clear);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit_final = new QCodeEditor(centralWidget);
        textEdit_final->setObjectName(QString::fromUtf8("textEdit_final"));

        verticalLayout_2->addWidget(textEdit_final);


        horizontalLayout_5->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(action_exit);
        mainToolBar->addAction(actionclient);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(toolButton_filter_clear, SIGNAL(clicked()), lineEdit_filter, SLOT(clear()));
        QObject::connect(action_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionclient->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "&exit", nullptr));
        toolButton_filter_clear->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        toolButton_all->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        toolButton_textedit_inter_clear->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        toolButton_template_clear->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        toolButton_lineedit_all_clear->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
