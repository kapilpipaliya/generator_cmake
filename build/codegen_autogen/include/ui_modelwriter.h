/********************************************************************************
** Form generated from reading UI file 'modelwriter.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELWRITER_H
#define UI_MODELWRITER_H

#include <QCodeEditor>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelWriter
{
public:
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_filter;
    QToolButton *toolButton_filter_clear;
    QToolButton *toolButton_all;
    QTreeView *treeView;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_lineedit_all_clear;
    QCodeEditor *textEdit_final;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;

    void setupUi(QWidget *ModelWriter)
    {
        if (ModelWriter->objectName().isEmpty())
            ModelWriter->setObjectName(QString::fromUtf8("ModelWriter"));
        ModelWriter->resize(1362, 682);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModelWriter->sizePolicy().hasHeightForWidth());
        ModelWriter->setSizePolicy(sizePolicy);
        horizontalLayout_11 = new QHBoxLayout(ModelWriter);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox = new QGroupBox(ModelWriter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_filter = new QLineEdit(groupBox);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        horizontalLayout->addWidget(lineEdit_filter);

        toolButton_filter_clear = new QToolButton(groupBox);
        toolButton_filter_clear->setObjectName(QString::fromUtf8("toolButton_filter_clear"));

        horizontalLayout->addWidget(toolButton_filter_clear);

        toolButton_all = new QToolButton(groupBox);
        toolButton_all->setObjectName(QString::fromUtf8("toolButton_all"));

        horizontalLayout->addWidget(toolButton_all);


        verticalLayout->addLayout(horizontalLayout);

        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);


        verticalLayout_8->addWidget(groupBox);

        groupBox_3 = new QGroupBox(ModelWriter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton_lineedit_all_clear = new QToolButton(groupBox_3);
        toolButton_lineedit_all_clear->setObjectName(QString::fromUtf8("toolButton_lineedit_all_clear"));

        horizontalLayout_3->addWidget(toolButton_lineedit_all_clear);


        verticalLayout_3->addLayout(horizontalLayout_3);

        textEdit_final = new QCodeEditor(groupBox_3);
        textEdit_final->setObjectName(QString::fromUtf8("textEdit_final"));

        verticalLayout_3->addWidget(textEdit_final);


        verticalLayout_8->addWidget(groupBox_3);


        horizontalLayout_11->addLayout(verticalLayout_8);

        scrollArea = new QScrollArea(ModelWriter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 890, 662));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_2->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_11->addWidget(scrollArea);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 2);
        QWidget::setTabOrder(scrollArea, lineEdit_filter);
        QWidget::setTabOrder(lineEdit_filter, toolButton_filter_clear);
        QWidget::setTabOrder(toolButton_filter_clear, toolButton_all);
        QWidget::setTabOrder(toolButton_all, treeView);
        QWidget::setTabOrder(treeView, toolButton_lineedit_all_clear);
        QWidget::setTabOrder(toolButton_lineedit_all_clear, textEdit_final);

        retranslateUi(ModelWriter);

        QMetaObject::connectSlotsByName(ModelWriter);
    } // setupUi

    void retranslateUi(QWidget *ModelWriter)
    {
        ModelWriter->setWindowTitle(QCoreApplication::translate("ModelWriter", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ModelWriter", "Table:", nullptr));
        toolButton_filter_clear->setText(QCoreApplication::translate("ModelWriter", "*", nullptr));
        toolButton_all->setText(QCoreApplication::translate("ModelWriter", "All", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ModelWriter", "Merge Result:", nullptr));
        toolButton_lineedit_all_clear->setText(QCoreApplication::translate("ModelWriter", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelWriter: public Ui_ModelWriter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELWRITER_H
