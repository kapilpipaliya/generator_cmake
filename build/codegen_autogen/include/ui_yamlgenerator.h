/********************************************************************************
** Form generated from reading UI file 'yamlgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAMLGENERATOR_H
#define UI_YAMLGENERATOR_H

#include <QCodeEditor>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YamlGenerator
{
public:
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_filename;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lineEdit_variable0;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_go_1;
    QToolButton *toolButton_save_1;
    QPlainTextEdit *plainTextEdit_templ_1;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_variable;
    QLineEdit *lineEdit_yamltext;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_go_2;
    QToolButton *toolButton_save_2;
    QPlainTextEdit *plainTextEdit_templ_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_go_3;
    QToolButton *toolButton_save_3;
    QPlainTextEdit *plainTextEdit_templ_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_go_4;
    QToolButton *toolButton_save_4;
    QPlainTextEdit *plainTextEdit_templ_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_go_5;
    QToolButton *toolButton_save_5;
    QPlainTextEdit *plainTextEdit_templ_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_inter_clear;
    QCodeEditor *textEdit_inter;

    void setupUi(QWidget *YamlGenerator)
    {
        if (YamlGenerator->objectName().isEmpty())
            YamlGenerator->setObjectName(QString::fromUtf8("YamlGenerator"));
        YamlGenerator->resize(1056, 800);
        horizontalLayout_4 = new QHBoxLayout(YamlGenerator);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        scrollArea = new QScrollArea(YamlGenerator);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 500, 875));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_filename = new QLineEdit(groupBox_2);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));

        gridLayout_2->addWidget(lineEdit_filename, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_variable0 = new QLineEdit(groupBox_2);
        lineEdit_variable0->setObjectName(QString::fromUtf8("lineEdit_variable0"));

        gridLayout_2->addWidget(lineEdit_variable0, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_go_1 = new QToolButton(groupBox_2);
        toolButton_go_1->setObjectName(QString::fromUtf8("toolButton_go_1"));

        horizontalLayout_2->addWidget(toolButton_go_1);

        toolButton_save_1 = new QToolButton(groupBox_2);
        toolButton_save_1->setObjectName(QString::fromUtf8("toolButton_save_1"));

        horizontalLayout_2->addWidget(toolButton_save_1);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        plainTextEdit_templ_1 = new QPlainTextEdit(groupBox_2);
        plainTextEdit_templ_1->setObjectName(QString::fromUtf8("plainTextEdit_templ_1"));

        verticalLayout->addWidget(plainTextEdit_templ_1);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_variable = new QLineEdit(groupBox);
        lineEdit_variable->setObjectName(QString::fromUtf8("lineEdit_variable"));

        gridLayout->addWidget(lineEdit_variable, 1, 1, 1, 1);

        lineEdit_yamltext = new QLineEdit(groupBox);
        lineEdit_yamltext->setObjectName(QString::fromUtf8("lineEdit_yamltext"));

        gridLayout->addWidget(lineEdit_yamltext, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        toolButton_go_2 = new QToolButton(groupBox);
        toolButton_go_2->setObjectName(QString::fromUtf8("toolButton_go_2"));

        horizontalLayout_7->addWidget(toolButton_go_2);

        toolButton_save_2 = new QToolButton(groupBox);
        toolButton_save_2->setObjectName(QString::fromUtf8("toolButton_save_2"));

        horizontalLayout_7->addWidget(toolButton_save_2);


        gridLayout->addLayout(horizontalLayout_7, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        plainTextEdit_templ_2 = new QPlainTextEdit(groupBox);
        plainTextEdit_templ_2->setObjectName(QString::fromUtf8("plainTextEdit_templ_2"));

        verticalLayout_5->addWidget(plainTextEdit_templ_2);


        verticalLayout_6->addWidget(groupBox);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_10 = new QVBoxLayout(groupBox_4);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        toolButton_go_3 = new QToolButton(groupBox_4);
        toolButton_go_3->setObjectName(QString::fromUtf8("toolButton_go_3"));

        horizontalLayout_3->addWidget(toolButton_go_3);

        toolButton_save_3 = new QToolButton(groupBox_4);
        toolButton_save_3->setObjectName(QString::fromUtf8("toolButton_save_3"));

        horizontalLayout_3->addWidget(toolButton_save_3);


        verticalLayout_10->addLayout(horizontalLayout_3);

        plainTextEdit_templ_3 = new QPlainTextEdit(groupBox_4);
        plainTextEdit_templ_3->setObjectName(QString::fromUtf8("plainTextEdit_templ_3"));

        verticalLayout_10->addWidget(plainTextEdit_templ_3);


        verticalLayout_6->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_3 = new QVBoxLayout(groupBox_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        toolButton_go_4 = new QToolButton(groupBox_6);
        toolButton_go_4->setObjectName(QString::fromUtf8("toolButton_go_4"));

        horizontalLayout_6->addWidget(toolButton_go_4);

        toolButton_save_4 = new QToolButton(groupBox_6);
        toolButton_save_4->setObjectName(QString::fromUtf8("toolButton_save_4"));

        horizontalLayout_6->addWidget(toolButton_save_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        plainTextEdit_templ_4 = new QPlainTextEdit(groupBox_6);
        plainTextEdit_templ_4->setObjectName(QString::fromUtf8("plainTextEdit_templ_4"));

        verticalLayout_3->addWidget(plainTextEdit_templ_4);


        verticalLayout_6->addWidget(groupBox_6);


        verticalLayout_8->addLayout(verticalLayout_6);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        toolButton_go_5 = new QToolButton(groupBox_3);
        toolButton_go_5->setObjectName(QString::fromUtf8("toolButton_go_5"));

        horizontalLayout_8->addWidget(toolButton_go_5);

        toolButton_save_5 = new QToolButton(groupBox_3);
        toolButton_save_5->setObjectName(QString::fromUtf8("toolButton_save_5"));

        horizontalLayout_8->addWidget(toolButton_save_5);


        verticalLayout_7->addLayout(horizontalLayout_8);

        plainTextEdit_templ_5 = new QPlainTextEdit(groupBox_3);
        plainTextEdit_templ_5->setObjectName(QString::fromUtf8("plainTextEdit_templ_5"));

        verticalLayout_7->addWidget(plainTextEdit_templ_5);


        verticalLayout_8->addWidget(groupBox_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_inter_clear = new QToolButton(YamlGenerator);
        toolButton_inter_clear->setObjectName(QString::fromUtf8("toolButton_inter_clear"));

        horizontalLayout->addWidget(toolButton_inter_clear);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        textEdit_inter = new QCodeEditor(YamlGenerator);
        textEdit_inter->setObjectName(QString::fromUtf8("textEdit_inter"));

        verticalLayout_4->addWidget(textEdit_inter);


        horizontalLayout_4->addLayout(verticalLayout_4);

        QWidget::setTabOrder(scrollArea, pushButton);
        QWidget::setTabOrder(pushButton, toolButton_go_1);
        QWidget::setTabOrder(toolButton_go_1, toolButton_save_1);
        QWidget::setTabOrder(toolButton_save_1, lineEdit_variable0);
        QWidget::setTabOrder(lineEdit_variable0, lineEdit_filename);
        QWidget::setTabOrder(lineEdit_filename, plainTextEdit_templ_1);
        QWidget::setTabOrder(plainTextEdit_templ_1, toolButton_go_2);
        QWidget::setTabOrder(toolButton_go_2, toolButton_save_2);
        QWidget::setTabOrder(toolButton_save_2, lineEdit_variable);
        QWidget::setTabOrder(lineEdit_variable, lineEdit_yamltext);
        QWidget::setTabOrder(lineEdit_yamltext, plainTextEdit_templ_2);
        QWidget::setTabOrder(plainTextEdit_templ_2, toolButton_go_3);
        QWidget::setTabOrder(toolButton_go_3, toolButton_save_3);
        QWidget::setTabOrder(toolButton_save_3, plainTextEdit_templ_3);
        QWidget::setTabOrder(plainTextEdit_templ_3, toolButton_go_4);
        QWidget::setTabOrder(toolButton_go_4, toolButton_save_4);
        QWidget::setTabOrder(toolButton_save_4, plainTextEdit_templ_4);
        QWidget::setTabOrder(plainTextEdit_templ_4, toolButton_go_5);
        QWidget::setTabOrder(toolButton_go_5, toolButton_save_5);
        QWidget::setTabOrder(toolButton_save_5, plainTextEdit_templ_5);
        QWidget::setTabOrder(plainTextEdit_templ_5, toolButton_inter_clear);
        QWidget::setTabOrder(toolButton_inter_clear, textEdit_inter);

        retranslateUi(YamlGenerator);

        QMetaObject::connectSlotsByName(YamlGenerator);
    } // setupUi

    void retranslateUi(QWidget *YamlGenerator)
    {
        YamlGenerator->setWindowTitle(QCoreApplication::translate("YamlGenerator", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("YamlGenerator", "Loading a configuration file", nullptr));
        label_6->setText(QCoreApplication::translate("YamlGenerator", "variable name:", nullptr));
        label_2->setText(QCoreApplication::translate("YamlGenerator", "loadFile:", nullptr));
        pushButton->setText(QCoreApplication::translate("YamlGenerator", "url", nullptr));
        toolButton_go_1->setText(QCoreApplication::translate("YamlGenerator", "G", nullptr));
        toolButton_save_1->setText(QCoreApplication::translate("YamlGenerator", "S", nullptr));
        plainTextEdit_templ_1->setPlainText(QCoreApplication::translate("YamlGenerator", "YAML::Node config = YAML::LoadFile(\"%1\");", nullptr));
        groupBox->setTitle(QCoreApplication::translate("YamlGenerator", "Basic Parsing and Node Editing", nullptr));
        label_4->setText(QCoreApplication::translate("YamlGenerator", "variable name:", nullptr));
        label_5->setText(QCoreApplication::translate("YamlGenerator", "yaml text:", nullptr));
        toolButton_go_2->setText(QCoreApplication::translate("YamlGenerator", "G", nullptr));
        toolButton_save_2->setText(QCoreApplication::translate("YamlGenerator", "S", nullptr));
        plainTextEdit_templ_2->setPlainText(QCoreApplication::translate("YamlGenerator", "YAML::Node config = YAML::LoadFile(\"%1\");", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("YamlGenerator", "you can query the type of a node:", nullptr));
        toolButton_go_3->setText(QCoreApplication::translate("YamlGenerator", "G", nullptr));
        toolButton_save_3->setText(QCoreApplication::translate("YamlGenerator", "S", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("YamlGenerator", "Building Nodes", nullptr));
        toolButton_go_4->setText(QCoreApplication::translate("YamlGenerator", "G", nullptr));
        toolButton_save_4->setText(QCoreApplication::translate("YamlGenerator", "S", nullptr));
        plainTextEdit_templ_4->setPlainText(QCoreApplication::translate("YamlGenerator", "YAML::Node node;  // starts out as null\n"
"node[\"key\"] = \"value\";  // it now is a map node\n"
"node[\"seq\"].push_back(\"first element\");  // node[\"seq\"] automatically becomes a sequence\n"
"node[\"seq\"].push_back(\"second element\");\n"
"\n"
"node[\"mirror\"] = node[\"seq\"][0];  // this creates an alias\n"
"node[\"seq\"][0] = \"1st element\";  // this also changes node[\"mirror\"]\n"
"node[\"mirror\"] = \"element #1\";  // and this changes node[\"seq\"][0] - they're really the \"same\" node\n"
"\n"
"node[\"self\"] = node;  // you can even create self-aliases\n"
"node[node[\"mirror\"]] = node[\"seq\"];  // and strange loops :)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("YamlGenerator", "Converting To/From Native Data Types", nullptr));
        toolButton_go_5->setText(QCoreApplication::translate("YamlGenerator", "G", nullptr));
        toolButton_save_5->setText(QCoreApplication::translate("YamlGenerator", "S", nullptr));
        toolButton_inter_clear->setText(QCoreApplication::translate("YamlGenerator", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YamlGenerator: public Ui_YamlGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAMLGENERATOR_H
