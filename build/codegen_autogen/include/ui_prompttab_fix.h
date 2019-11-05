/********************************************************************************
** Form generated from reading UI file 'prompttab_fix.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPTTAB_FIX_H
#define UI_PROMPTTAB_FIX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PromptTab
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_SelectPromptProvider;
    QStackedWidget *stackedWidget;
    QWidget *page_FancyPrompts;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox_SelectFancyPrompt;
    QCheckBox *checkBox_CompactLargePrompts;
    QCheckBox *checkBox_CompactLargePrompts2;
    QCheckBox *checkBox_ParensInstead;
    QCheckBox *checkBox_NoColor;
    QCheckBox *checkBox_BoldLines;
    QCheckBox *checkBox_DoubleLines;
    QCheckBox *checkBox_DisableUnicode;
    QCheckBox *checkBox_MutedColors;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_TimeFormatText;
    QPushButton *pushButton_TimeFormatHelp;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_DateFormatText;
    QPushButton *pushButton_DateFormatHelp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_RightMargin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_ExtraNewlinesBeforePrompt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_PromptText;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_TitleText;
    QWidget *page_2;

    void setupUi(QWidget *PromptTab)
    {
        if (PromptTab->objectName().isEmpty())
            PromptTab->setObjectName(QString::fromUtf8("PromptTab"));
        PromptTab->resize(460, 496);
        verticalLayout = new QVBoxLayout(PromptTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(PromptTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 426, 620));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox_SelectPromptProvider = new QComboBox(scrollAreaWidgetContents);
        comboBox_SelectPromptProvider->addItem(QString());
        comboBox_SelectPromptProvider->addItem(QString());
        comboBox_SelectPromptProvider->setObjectName(QString::fromUtf8("comboBox_SelectPromptProvider"));

        verticalLayout_2->addWidget(comboBox_SelectPromptProvider);

        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_FancyPrompts = new QWidget();
        page_FancyPrompts->setObjectName(QString::fromUtf8("page_FancyPrompts"));
        verticalLayout_3 = new QVBoxLayout(page_FancyPrompts);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        comboBox_SelectFancyPrompt = new QComboBox(page_FancyPrompts);
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->addItem(QString());
        comboBox_SelectFancyPrompt->setObjectName(QString::fromUtf8("comboBox_SelectFancyPrompt"));

        verticalLayout_3->addWidget(comboBox_SelectFancyPrompt);

        checkBox_CompactLargePrompts = new QCheckBox(page_FancyPrompts);
        checkBox_CompactLargePrompts->setObjectName(QString::fromUtf8("checkBox_CompactLargePrompts"));

        verticalLayout_3->addWidget(checkBox_CompactLargePrompts);

        checkBox_CompactLargePrompts2 = new QCheckBox(page_FancyPrompts);
        checkBox_CompactLargePrompts2->setObjectName(QString::fromUtf8("checkBox_CompactLargePrompts2"));

        verticalLayout_3->addWidget(checkBox_CompactLargePrompts2);

        checkBox_ParensInstead = new QCheckBox(page_FancyPrompts);
        checkBox_ParensInstead->setObjectName(QString::fromUtf8("checkBox_ParensInstead"));

        verticalLayout_3->addWidget(checkBox_ParensInstead);

        checkBox_NoColor = new QCheckBox(page_FancyPrompts);
        checkBox_NoColor->setObjectName(QString::fromUtf8("checkBox_NoColor"));

        verticalLayout_3->addWidget(checkBox_NoColor);

        checkBox_BoldLines = new QCheckBox(page_FancyPrompts);
        checkBox_BoldLines->setObjectName(QString::fromUtf8("checkBox_BoldLines"));

        verticalLayout_3->addWidget(checkBox_BoldLines);

        checkBox_DoubleLines = new QCheckBox(page_FancyPrompts);
        checkBox_DoubleLines->setObjectName(QString::fromUtf8("checkBox_DoubleLines"));

        verticalLayout_3->addWidget(checkBox_DoubleLines);

        checkBox_DisableUnicode = new QCheckBox(page_FancyPrompts);
        checkBox_DisableUnicode->setObjectName(QString::fromUtf8("checkBox_DisableUnicode"));

        verticalLayout_3->addWidget(checkBox_DisableUnicode);

        checkBox_MutedColors = new QCheckBox(page_FancyPrompts);
        checkBox_MutedColors->setObjectName(QString::fromUtf8("checkBox_MutedColors"));

        verticalLayout_3->addWidget(checkBox_MutedColors);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        label_5 = new QLabel(page_FancyPrompts);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_TimeFormatText = new QLineEdit(page_FancyPrompts);
        lineEdit_TimeFormatText->setObjectName(QString::fromUtf8("lineEdit_TimeFormatText"));

        horizontalLayout_5->addWidget(lineEdit_TimeFormatText);

        pushButton_TimeFormatHelp = new QPushButton(page_FancyPrompts);
        pushButton_TimeFormatHelp->setObjectName(QString::fromUtf8("pushButton_TimeFormatHelp"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("help");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_TimeFormatHelp->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_TimeFormatHelp);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(page_FancyPrompts);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_DateFormatText = new QLineEdit(page_FancyPrompts);
        lineEdit_DateFormatText->setObjectName(QString::fromUtf8("lineEdit_DateFormatText"));

        horizontalLayout->addWidget(lineEdit_DateFormatText);

        pushButton_DateFormatHelp = new QPushButton(page_FancyPrompts);
        pushButton_DateFormatHelp->setObjectName(QString::fromUtf8("pushButton_DateFormatHelp"));
        pushButton_DateFormatHelp->setIcon(icon);

        horizontalLayout->addWidget(pushButton_DateFormatHelp);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(page_FancyPrompts);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        spinBox_RightMargin = new QSpinBox(page_FancyPrompts);
        spinBox_RightMargin->setObjectName(QString::fromUtf8("spinBox_RightMargin"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_RightMargin->sizePolicy().hasHeightForWidth());
        spinBox_RightMargin->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(spinBox_RightMargin);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(page_FancyPrompts);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox_ExtraNewlinesBeforePrompt = new QSpinBox(page_FancyPrompts);
        spinBox_ExtraNewlinesBeforePrompt->setObjectName(QString::fromUtf8("spinBox_ExtraNewlinesBeforePrompt"));

        horizontalLayout_3->addWidget(spinBox_ExtraNewlinesBeforePrompt);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_4 = new QLabel(page_FancyPrompts);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_PromptText = new QLineEdit(page_FancyPrompts);
        lineEdit_PromptText->setObjectName(QString::fromUtf8("lineEdit_PromptText"));

        horizontalLayout_4->addWidget(lineEdit_PromptText);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(page_FancyPrompts);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_TitleText = new QLineEdit(page_FancyPrompts);
        lineEdit_TitleText->setObjectName(QString::fromUtf8("lineEdit_TitleText"));

        horizontalLayout_7->addWidget(lineEdit_TitleText);


        verticalLayout_3->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(page_FancyPrompts);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(PromptTab);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PromptTab);
    } // setupUi

    void retranslateUi(QWidget *PromptTab)
    {
        PromptTab->setWindowTitle(QCoreApplication::translate("PromptTab", "Form", nullptr));
        comboBox_SelectPromptProvider->setItemText(0, QCoreApplication::translate("PromptTab", "Default", nullptr));
        comboBox_SelectPromptProvider->setItemText(1, QCoreApplication::translate("PromptTab", "Fancy Prompt", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_SelectPromptProvider->setToolTip(QCoreApplication::translate("PromptTab", "<html><head/><body><p>Change what gives you your prompt.</p><p>Default - Use what prompt you had before.</p><p>Fancy Prompt - Uses the MX Fancy Prompt utility</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_SelectFancyPrompt->setItemText(0, QCoreApplication::translate("PromptTab", "Tiny", nullptr));
        comboBox_SelectFancyPrompt->setItemText(1, QCoreApplication::translate("PromptTab", "Std", nullptr));
        comboBox_SelectFancyPrompt->setItemText(2, QCoreApplication::translate("PromptTab", "Color", nullptr));
        comboBox_SelectFancyPrompt->setItemText(3, QCoreApplication::translate("PromptTab", "Gentoo", nullptr));
        comboBox_SelectFancyPrompt->setItemText(4, QCoreApplication::translate("PromptTab", "Dir", nullptr));
        comboBox_SelectFancyPrompt->setItemText(5, QCoreApplication::translate("PromptTab", "Med", nullptr));
        comboBox_SelectFancyPrompt->setItemText(6, QCoreApplication::translate("PromptTab", "Narrow", nullptr));
        comboBox_SelectFancyPrompt->setItemText(7, QCoreApplication::translate("PromptTab", "Wide", nullptr));
        comboBox_SelectFancyPrompt->setItemText(8, QCoreApplication::translate("PromptTab", "Fancy", nullptr));
        comboBox_SelectFancyPrompt->setItemText(9, QCoreApplication::translate("PromptTab", "Zee", nullptr));
        comboBox_SelectFancyPrompt->setItemText(10, QCoreApplication::translate("PromptTab", "Date", nullptr));
        comboBox_SelectFancyPrompt->setItemText(11, QCoreApplication::translate("PromptTab", "Curl", nullptr));

        checkBox_CompactLargePrompts->setText(QCoreApplication::translate("PromptTab", "Make The Larger Prompts Smaller", nullptr));
        checkBox_CompactLargePrompts2->setText(QCoreApplication::translate("PromptTab", "Make the Larger Prompts Smaller Elsewhere", nullptr));
        checkBox_ParensInstead->setText(QCoreApplication::translate("PromptTab", "Use Parentheses Instead Of Square Brackets", nullptr));
        checkBox_NoColor->setText(QCoreApplication::translate("PromptTab", "No Colors(Overrides All Other Color Options)", nullptr));
        checkBox_BoldLines->setText(QCoreApplication::translate("PromptTab", "Use Bold Lines", nullptr));
        checkBox_DoubleLines->setText(QCoreApplication::translate("PromptTab", "Use Double Lines", nullptr));
        checkBox_DisableUnicode->setText(QCoreApplication::translate("PromptTab", "Disable Unicode", nullptr));
        checkBox_MutedColors->setText(QCoreApplication::translate("PromptTab", "Muted Colors", nullptr));
        label_5->setText(QCoreApplication::translate("PromptTab", "Time Format", nullptr));
        pushButton_TimeFormatHelp->setText(QCoreApplication::translate("PromptTab", "Help", nullptr));
        label->setText(QCoreApplication::translate("PromptTab", "Date Format", nullptr));
        pushButton_DateFormatHelp->setText(QCoreApplication::translate("PromptTab", "Help", nullptr));
        label_2->setText(QCoreApplication::translate("PromptTab", "Right Margin", nullptr));
        label_3->setText(QCoreApplication::translate("PromptTab", "Extra Newlines Before Prompt", nullptr));
        label_4->setText(QCoreApplication::translate("PromptTab", "Prompt Text", nullptr));
        label_7->setText(QCoreApplication::translate("PromptTab", "Title Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromptTab: public Ui_PromptTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPTTAB_FIX_H
