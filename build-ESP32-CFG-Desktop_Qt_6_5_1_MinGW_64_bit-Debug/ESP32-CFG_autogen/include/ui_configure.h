/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configure
{
public:
    QVBoxLayout *mainVerticalLayout;
    QFrame *InputArea;
    QGridLayout *inputGridLayout;
    QLabel *titleLabel;
    QLineEdit *inputPW;
    QLabel *labelBusA;
    QLineEdit *inputBusB;
    QLabel *labelPW;
    QLabel *labelIP;
    QLabel *subtitleLabel;
    QLineEdit *inputBusA;
    QLabel *labelWeather;
    QLineEdit *inputIP;
    QLabel *labelBusB;
    QLineEdit *inputWeather;
    QLineEdit *inputSSID;
    QLabel *labelSSID;
    QFrame *inputSpacer;
    QFrame *ButtonArea;
    QHBoxLayout *buttonHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *noButton;
    QToolButton *uploadButton;

    void setupUi(QWidget *Configure)
    {
        if (Configure->objectName().isEmpty())
            Configure->setObjectName("Configure");
        Configure->resize(1160, 665);
        mainVerticalLayout = new QVBoxLayout(Configure);
        mainVerticalLayout->setSpacing(16);
        mainVerticalLayout->setObjectName("mainVerticalLayout");
        mainVerticalLayout->setContentsMargins(32, 32, 32, 32);
        InputArea = new QFrame(Configure);
        InputArea->setObjectName("InputArea");
        InputArea->setFrameShape(QFrame::StyledPanel);
        InputArea->setFrameShadow(QFrame::Raised);
        inputGridLayout = new QGridLayout(InputArea);
        inputGridLayout->setObjectName("inputGridLayout");
        inputGridLayout->setHorizontalSpacing(32);
        inputGridLayout->setVerticalSpacing(16);
        inputGridLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(InputArea);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMinimumSize(QSize(0, 48));
        titleLabel->setMaximumSize(QSize(16777215, 64));
        titleLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        inputGridLayout->addWidget(titleLabel, 0, 0, 1, 4);

        inputPW = new QLineEdit(InputArea);
        inputPW->setObjectName("inputPW");

        inputGridLayout->addWidget(inputPW, 6, 3, 1, 1);

        labelBusA = new QLabel(InputArea);
        labelBusA->setObjectName("labelBusA");

        inputGridLayout->addWidget(labelBusA, 3, 0, 1, 1);

        inputBusB = new QLineEdit(InputArea);
        inputBusB->setObjectName("inputBusB");

        inputGridLayout->addWidget(inputBusB, 4, 3, 1, 1);

        labelPW = new QLabel(InputArea);
        labelPW->setObjectName("labelPW");

        inputGridLayout->addWidget(labelPW, 6, 0, 1, 1);

        labelIP = new QLabel(InputArea);
        labelIP->setObjectName("labelIP");

        inputGridLayout->addWidget(labelIP, 7, 0, 1, 1);

        subtitleLabel = new QLabel(InputArea);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setMinimumSize(QSize(0, 48));
        subtitleLabel->setMaximumSize(QSize(16777215, 98));
        subtitleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        inputGridLayout->addWidget(subtitleLabel, 1, 0, 1, 4);

        inputBusA = new QLineEdit(InputArea);
        inputBusA->setObjectName("inputBusA");

        inputGridLayout->addWidget(inputBusA, 3, 3, 1, 1);

        labelWeather = new QLabel(InputArea);
        labelWeather->setObjectName("labelWeather");

        inputGridLayout->addWidget(labelWeather, 2, 0, 1, 1);

        inputIP = new QLineEdit(InputArea);
        inputIP->setObjectName("inputIP");

        inputGridLayout->addWidget(inputIP, 7, 3, 1, 1);

        labelBusB = new QLabel(InputArea);
        labelBusB->setObjectName("labelBusB");

        inputGridLayout->addWidget(labelBusB, 4, 0, 1, 1);

        inputWeather = new QLineEdit(InputArea);
        inputWeather->setObjectName("inputWeather");

        inputGridLayout->addWidget(inputWeather, 2, 3, 1, 1);

        inputSSID = new QLineEdit(InputArea);
        inputSSID->setObjectName("inputSSID");

        inputGridLayout->addWidget(inputSSID, 5, 3, 1, 1);

        labelSSID = new QLabel(InputArea);
        labelSSID->setObjectName("labelSSID");

        inputGridLayout->addWidget(labelSSID, 5, 0, 1, 1);

        inputSpacer = new QFrame(InputArea);
        inputSpacer->setObjectName("inputSpacer");
        inputSpacer->setMinimumSize(QSize(32, 0));
        inputSpacer->setFrameShape(QFrame::StyledPanel);
        inputSpacer->setFrameShadow(QFrame::Raised);

        inputGridLayout->addWidget(inputSpacer, 2, 4, 6, 1);


        mainVerticalLayout->addWidget(InputArea);

        ButtonArea = new QFrame(Configure);
        ButtonArea->setObjectName("ButtonArea");
        ButtonArea->setMaximumSize(QSize(16777215, 128));
        ButtonArea->setFrameShape(QFrame::StyledPanel);
        ButtonArea->setFrameShadow(QFrame::Raised);
        buttonHorizontalLayout = new QHBoxLayout(ButtonArea);
        buttonHorizontalLayout->setSpacing(6);
        buttonHorizontalLayout->setObjectName("buttonHorizontalLayout");
        buttonHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(920, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer);

        noButton = new QToolButton(ButtonArea);
        noButton->setObjectName("noButton");

        buttonHorizontalLayout->addWidget(noButton);

        uploadButton = new QToolButton(ButtonArea);
        uploadButton->setObjectName("uploadButton");

        buttonHorizontalLayout->addWidget(uploadButton);


        mainVerticalLayout->addWidget(ButtonArea);


        retranslateUi(Configure);

        QMetaObject::connectSlotsByName(Configure);
    } // setupUi

    void retranslateUi(QWidget *Configure)
    {
        Configure->setWindowTitle(QCoreApplication::translate("Configure", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("Configure", "Configure ESP32-DIS", nullptr));
        labelBusA->setText(QCoreApplication::translate("Configure", "BUS A Stoptimes API URL", nullptr));
        labelPW->setText(QCoreApplication::translate("Configure", "WiFi Password", nullptr));
        labelIP->setText(QCoreApplication::translate("Configure", "Remote Light Socket IP address", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("Configure", "Store custom credentials permanently in your device.", nullptr));
        labelWeather->setText(QCoreApplication::translate("Configure", "Weather API URL", nullptr));
        labelBusB->setText(QCoreApplication::translate("Configure", "BUS B Stoptimes API URL", nullptr));
        labelSSID->setText(QCoreApplication::translate("Configure", "WiFI SSID", nullptr));
        noButton->setText(QCoreApplication::translate("Configure", "No", nullptr));
        uploadButton->setText(QCoreApplication::translate("Configure", "Upload Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Configure: public Ui_Configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
