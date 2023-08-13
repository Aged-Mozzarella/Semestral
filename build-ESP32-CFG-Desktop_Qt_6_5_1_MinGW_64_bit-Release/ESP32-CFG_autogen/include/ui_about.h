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
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout;
    QLabel *aboutProjectLabel;
    QSpacerItem *verticalSpacer;
    QFrame *legalFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *legalLabel;
    QLabel *legalLink;
    QSpacerItem *legalSpacer;

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
        verticalLayout = new QVBoxLayout(contentFrame);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        aboutProjectLabel = new QLabel(contentFrame);
        aboutProjectLabel->setObjectName("aboutProjectLabel");
        aboutProjectLabel->setWordWrap(true);

        verticalLayout->addWidget(aboutProjectLabel);


        mainAreaLayout->addWidget(contentFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainAreaLayout->addItem(verticalSpacer);

        legalFrame = new QFrame(About);
        legalFrame->setObjectName("legalFrame");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(legalFrame->sizePolicy().hasHeightForWidth());
        legalFrame->setSizePolicy(sizePolicy);
        legalFrame->setFrameShape(QFrame::StyledPanel);
        legalFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(legalFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        legalLabel = new QLabel(legalFrame);
        legalLabel->setObjectName("legalLabel");

        horizontalLayout->addWidget(legalLabel);

        legalLink = new QLabel(legalFrame);
        legalLink->setObjectName("legalLink");

        horizontalLayout->addWidget(legalLink);

        legalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(legalSpacer);


        mainAreaLayout->addWidget(legalFrame);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("About", "About", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("About", "A brief overview of the project", nullptr));
        aboutProjectLabel->setText(QCoreApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The ESP32-DIS system fetches an array of data via a REST API (weather forecast, stop times for two bus lines of choice, etc.) and displays it on an E-Paper display. It also lets the user remotely control a TP-Link power socket for extra convenience. </p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" marg"
                        "in-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The initial version of ESP32-DIS (submitted as a semestral project for the course B2B99EKP) had a lot of room for improvement in its final design. Firstly, to ensure the correct functionality, this version of ESP32-DIS used a system of hardcoded string literals containing the URLs and Wi-Fi login credentials, significantly hindering the device's practical use. And, if, due to the rigid nature of the design, the device failed to connect to the internet, no alert would appear on the screen to notify the user.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This semestral project aims to address the issues highlighted earlier by providin"
                        "g a simple configuration tool for the user and polishing up the device's final design (on-screen alert when the device fails to connect to the internet, revamped inner workings, etc.). As a bonus, the application provides a live feed of the on-screen data.</p></body></html>", nullptr));
        legalLabel->setText(QCoreApplication::translate("About", "Due to legal reasons, I am required to attribute the authors of the icons used in this application, link ", nullptr));
        legalLink->setText(QCoreApplication::translate("About", "here [15 hyperlinks].", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
