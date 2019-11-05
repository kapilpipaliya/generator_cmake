/********************************************************************************
** Form generated from reading UI file 'sqlcompare.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLCOMPARE_H
#define UI_SQLCOMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SqlCompare
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_filter;
    QToolButton *toolButton_filter_clear;
    QToolButton *toolButton_all;
    QTreeView *treeView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_table;
    QLineEdit *lineEdit_db2;
    QLineEdit *lineEdit_columns;
    QLabel *label_8;
    QLabel *label;
    QLineEdit *lineEdit_order_by;
    QLineEdit *lineEdit_db1;
    QLabel *label_7;
    QLineEdit *lineEdit_where;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_go_1;
    QToolButton *toolButton_go_2;
    QToolButton *toolButton_match;
    QToolButton *toolButton_go_all;
    QToolButton *toolButton_load;
    QToolButton *toolButton_save;
    QToolButton *toolButton_c;
    QToolButton *toolButton_count;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_result_columns;
    QToolButton *toolButton_set;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_1;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox_2;
    QLabel *label_5;

    void setupUi(QWidget *SqlCompare)
    {
        if (SqlCompare->objectName().isEmpty())
            SqlCompare->setObjectName(QString::fromUtf8("SqlCompare"));
        SqlCompare->resize(881, 564);
        verticalLayout_3 = new QVBoxLayout(SqlCompare);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_filter = new QLineEdit(SqlCompare);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        horizontalLayout_3->addWidget(lineEdit_filter);

        toolButton_filter_clear = new QToolButton(SqlCompare);
        toolButton_filter_clear->setObjectName(QString::fromUtf8("toolButton_filter_clear"));

        horizontalLayout_3->addWidget(toolButton_filter_clear);

        toolButton_all = new QToolButton(SqlCompare);
        toolButton_all->setObjectName(QString::fromUtf8("toolButton_all"));

        horizontalLayout_3->addWidget(toolButton_all);


        verticalLayout_2->addLayout(horizontalLayout_3);

        treeView = new QTreeView(SqlCompare);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_2->addWidget(treeView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(SqlCompare);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_table = new QLineEdit(groupBox);
        lineEdit_table->setObjectName(QString::fromUtf8("lineEdit_table"));

        gridLayout->addWidget(lineEdit_table, 2, 1, 1, 1);

        lineEdit_db2 = new QLineEdit(groupBox);
        lineEdit_db2->setObjectName(QString::fromUtf8("lineEdit_db2"));

        gridLayout->addWidget(lineEdit_db2, 1, 1, 1, 1);

        lineEdit_columns = new QLineEdit(groupBox);
        lineEdit_columns->setObjectName(QString::fromUtf8("lineEdit_columns"));

        gridLayout->addWidget(lineEdit_columns, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_order_by = new QLineEdit(groupBox);
        lineEdit_order_by->setObjectName(QString::fromUtf8("lineEdit_order_by"));

        gridLayout->addWidget(lineEdit_order_by, 5, 1, 1, 1);

        lineEdit_db1 = new QLineEdit(groupBox);
        lineEdit_db1->setObjectName(QString::fromUtf8("lineEdit_db1"));

        gridLayout->addWidget(lineEdit_db1, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        lineEdit_where = new QLineEdit(groupBox);
        lineEdit_where->setObjectName(QString::fromUtf8("lineEdit_where"));

        gridLayout->addWidget(lineEdit_where, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        toolButton_go_1 = new QToolButton(groupBox);
        toolButton_go_1->setObjectName(QString::fromUtf8("toolButton_go_1"));

        horizontalLayout_7->addWidget(toolButton_go_1);

        toolButton_go_2 = new QToolButton(groupBox);
        toolButton_go_2->setObjectName(QString::fromUtf8("toolButton_go_2"));

        horizontalLayout_7->addWidget(toolButton_go_2);

        toolButton_match = new QToolButton(groupBox);
        toolButton_match->setObjectName(QString::fromUtf8("toolButton_match"));

        horizontalLayout_7->addWidget(toolButton_match);

        toolButton_go_all = new QToolButton(groupBox);
        toolButton_go_all->setObjectName(QString::fromUtf8("toolButton_go_all"));

        horizontalLayout_7->addWidget(toolButton_go_all);

        toolButton_load = new QToolButton(groupBox);
        toolButton_load->setObjectName(QString::fromUtf8("toolButton_load"));

        horizontalLayout_7->addWidget(toolButton_load);

        toolButton_save = new QToolButton(groupBox);
        toolButton_save->setObjectName(QString::fromUtf8("toolButton_save"));

        horizontalLayout_7->addWidget(toolButton_save);

        toolButton_c = new QToolButton(groupBox);
        toolButton_c->setObjectName(QString::fromUtf8("toolButton_c"));

        horizontalLayout_7->addWidget(toolButton_c);

        toolButton_count = new QToolButton(groupBox);
        toolButton_count->setObjectName(QString::fromUtf8("toolButton_count"));

        horizontalLayout_7->addWidget(toolButton_count);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(SqlCompare);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_result_columns = new QLineEdit(SqlCompare);
        lineEdit_result_columns->setObjectName(QString::fromUtf8("lineEdit_result_columns"));

        horizontalLayout_4->addWidget(lineEdit_result_columns);

        toolButton_set = new QToolButton(SqlCompare);
        toolButton_set->setObjectName(QString::fromUtf8("toolButton_set"));

        horizontalLayout_4->addWidget(toolButton_set);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit_1 = new QTextEdit(SqlCompare);
        textEdit_1->setObjectName(QString::fromUtf8("textEdit_1"));

        horizontalLayout->addWidget(textEdit_1);

        textEdit_2 = new QTextEdit(SqlCompare);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout->addWidget(textEdit_2);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(SqlCompare);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 20, 57, 16));

        verticalLayout_3->addWidget(groupBox_2);

        QWidget::setTabOrder(lineEdit_filter, toolButton_filter_clear);
        QWidget::setTabOrder(toolButton_filter_clear, toolButton_all);
        QWidget::setTabOrder(toolButton_all, treeView);
        QWidget::setTabOrder(treeView, lineEdit_db1);
        QWidget::setTabOrder(lineEdit_db1, lineEdit_db2);
        QWidget::setTabOrder(lineEdit_db2, lineEdit_table);
        QWidget::setTabOrder(lineEdit_table, lineEdit_columns);
        QWidget::setTabOrder(lineEdit_columns, lineEdit_where);
        QWidget::setTabOrder(lineEdit_where, lineEdit_order_by);
        QWidget::setTabOrder(lineEdit_order_by, toolButton_go_1);
        QWidget::setTabOrder(toolButton_go_1, toolButton_go_2);
        QWidget::setTabOrder(toolButton_go_2, toolButton_match);
        QWidget::setTabOrder(toolButton_match, toolButton_go_all);
        QWidget::setTabOrder(toolButton_go_all, toolButton_load);
        QWidget::setTabOrder(toolButton_load, toolButton_save);
        QWidget::setTabOrder(toolButton_save, toolButton_c);
        QWidget::setTabOrder(toolButton_c, toolButton_count);
        QWidget::setTabOrder(toolButton_count, lineEdit_result_columns);
        QWidget::setTabOrder(lineEdit_result_columns, toolButton_set);
        QWidget::setTabOrder(toolButton_set, textEdit_1);
        QWidget::setTabOrder(textEdit_1, textEdit_2);

        retranslateUi(SqlCompare);

        QMetaObject::connectSlotsByName(SqlCompare);
    } // setupUi

    void retranslateUi(QWidget *SqlCompare)
    {
        SqlCompare->setWindowTitle(QCoreApplication::translate("SqlCompare", "Form", nullptr));
        toolButton_filter_clear->setText(QCoreApplication::translate("SqlCompare", "*", nullptr));
        toolButton_all->setText(QCoreApplication::translate("SqlCompare", "All", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SqlCompare", "GroupBox", nullptr));
        label_2->setText(QCoreApplication::translate("SqlCompare", "database2:", nullptr));
        label_3->setText(QCoreApplication::translate("SqlCompare", "table:", nullptr));
        label_4->setText(QCoreApplication::translate("SqlCompare", "columns:", nullptr));
        label_8->setText(QCoreApplication::translate("SqlCompare", "where:", nullptr));
        label->setText(QCoreApplication::translate("SqlCompare", "database1:", nullptr));
        label_7->setText(QCoreApplication::translate("SqlCompare", "order_by:", nullptr));
        toolButton_go_1->setText(QCoreApplication::translate("SqlCompare", "Get 1", nullptr));
        toolButton_go_2->setText(QCoreApplication::translate("SqlCompare", "Get 2", nullptr));
        toolButton_match->setText(QCoreApplication::translate("SqlCompare", "Match", nullptr));
        toolButton_go_all->setText(QCoreApplication::translate("SqlCompare", "Get All && Match", nullptr));
        toolButton_load->setText(QCoreApplication::translate("SqlCompare", "Load", nullptr));
        toolButton_save->setText(QCoreApplication::translate("SqlCompare", "Save", nullptr));
        toolButton_c->setText(QCoreApplication::translate("SqlCompare", "Columns", nullptr));
        toolButton_count->setText(QCoreApplication::translate("SqlCompare", "Count", nullptr));
        label_6->setText(QCoreApplication::translate("SqlCompare", "result columns:", nullptr));
        toolButton_set->setText(QCoreApplication::translate("SqlCompare", "set", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SqlCompare", "Result", nullptr));
        label_5->setText(QCoreApplication::translate("SqlCompare", "matched", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SqlCompare: public Ui_SqlCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLCOMPARE_H
