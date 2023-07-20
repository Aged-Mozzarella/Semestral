/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *mainAreaLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QFrame *contentFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *aboutProjectLabel;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(1160, 665);
        mainAreaLayout = new QVBoxLayout(About);
        mainAreaLayout->setSpacing(16);
        mainAreaLayout->setObjectName("mainAreaLayout");
        mainAreaLayout->setContentsMargins(32, 32, 32, 32);
        titleLabel = new QLabel(About);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMinimumSize(QSize(0, 48));
        titleLabel->setMaximumSize(QSize(16777215, 64));
        titleLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        mainAreaLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(About);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setMinimumSize(QSize(0, 48));
        subtitleLabel->setMaximumSize(QSize(16777215, 98));
        subtitleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        mainAreaLayout->addWidget(subtitleLabel);

        contentFrame = new QFrame(About);
        contentFrame->setObjectName("contentFrame");
        contentFrame->setFrameShape(QFrame::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(contentFrame);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        aboutProjectLabel = new QLabel(contentFrame);
        aboutProjectLabel->setObjectName("aboutProjectLabel");
        aboutProjectLabel->setWordWrap(true);

        horizontalLayout->addWidget(aboutProjectLabel);


        mainAreaLayout->addWidget(contentFrame);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("About", "About", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("About", "A brief overview of the app", nullptr));
        aboutProjectLabel->setText(QCoreApplication::translate("About", "<html><head/><body><p>The application <span style=\" font-weight:700;\">ESP32-CFG</span> serves as a simple configuration tool for the ESP32-DIS device \342\200\223 a system that neatly displays an array of data fetched from a REST API (such as the weather forecast, stoptimes for two bus lines of choice etc.) on an E-Paper display. Furthermore, it allows you to remotely control your desk light via a smart TP-Link power socket. </p><p>The initial version of ESP32-DIS featured an impractically rigid system of a series of hardcoded string literals containing the URLs and Wi-Fi login credentials which ensured the proper functionality of the device. </p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
