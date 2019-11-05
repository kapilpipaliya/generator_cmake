/********************************************************************************
** Form generated from reading UI file 'window_fix.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_FIX_H
#define UI_WINDOW_FIX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_Tabs;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_About;
    QPushButton *pushButton_Help;
    QPushButton *pushButton_Apply;
    QLabel *label;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(468, 452);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window->sizePolicy().hasHeightForWidth());
        Window->setSizePolicy(sizePolicy);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("terminal");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Window->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Window);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget_Tabs = new QTabWidget(Window);
        tabWidget_Tabs->setObjectName(QString::fromUtf8("tabWidget_Tabs"));

        verticalLayout->addWidget(tabWidget_Tabs);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_About = new QPushButton(Window);
        pushButton_About->setObjectName(QString::fromUtf8("pushButton_About"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("help-about");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_About->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_About);

        pushButton_Help = new QPushButton(Window);
        pushButton_Help->setObjectName(QString::fromUtf8("pushButton_Help"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("help");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_Help->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_Help);

        pushButton_Apply = new QPushButton(Window);
        pushButton_Apply->setObjectName(QString::fromUtf8("pushButton_Apply"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_Apply->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_Apply);

        label = new QLabel(Window);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(32, 32));
        label->setPixmap(QPixmap(QString::fromUtf8(":/mx/mx.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        pushButton_Close = new QPushButton(Window);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_Close->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_Close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        pushButton_About->setText(QCoreApplication::translate("Window", "About", nullptr));
        pushButton_Help->setText(QCoreApplication::translate("Window", "Help", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Apply->setToolTip(QCoreApplication::translate("Window", "<html><head/><body><p>Applies Changes.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Apply->setText(QCoreApplication::translate("Window", "Apply", nullptr));
        label->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Close->setToolTip(QCoreApplication::translate("Window", "<html><head/><body><p>Closes the application.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Close->setText(QCoreApplication::translate("Window", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_FIX_H
