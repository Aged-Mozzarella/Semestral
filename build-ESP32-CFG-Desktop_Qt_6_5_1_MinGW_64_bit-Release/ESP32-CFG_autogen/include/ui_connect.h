/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QVBoxLayout *mainAreaLayout;
    QFrame *InputArea;
    QGridLayout *connectGridLayout;
    QLabel *titleLabel;
    QFrame *FormArea;
    QVBoxLayout *formVerticalLayout;
    QLabel *portLabel;
    QComboBox *portSelect;
    QFrame *FormRefresh;
    QHBoxLayout *refreshHorizontalLayout;
    QSpacerItem *formRefreshSpacer;
    QToolButton *formRefreshButton;
    QLabel *baudLabel;
    QComboBox *baudSelect;
    QSpacerItem *formSpacer;
    QFrame *PortInfoArea;
    QGridLayout *portInfoGridLayout;
    QLabel *infoDescriptionLabel;
    QLabel *infoProductLabel;
    QLabel *infoPortLabel;
    QLabel *infoLocationValue;
    QLabel *infoVendorLabel;
    QLabel *infoDescriptionValue;
    QLabel *infoProductValue;
    QLabel *infoSerialLabel;
    QLabel *infoVendorValue;
    QLabel *infoLocationLabel;
    QLabel *infoPortValue;
    QLabel *infoManufacturerLabel;
    QLabel *infoSerialValue;
    QLabel *infoManufacturerValue;
    QLabel *portInfoTitleLabel;
    QSpacerItem *infoSpacer;
    QLabel *subtitleLabel;
    QFrame *ButtonArea;
    QHBoxLayout *buttonLayout;
    QSpacerItem *connectSpacer;
    QToolButton *connectButton;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName("Connect");
        Connect->resize(1160, 665);
        mainAreaLayout = new QVBoxLayout(Connect);
        mainAreaLayout->setSpacing(16);
        mainAreaLayout->setObjectName("mainAreaLayout");
        mainAreaLayout->setContentsMargins(32, 32, 32, 32);
        InputArea = new QFrame(Connect);
        InputArea->setObjectName("InputArea");
        InputArea->setFrameShape(QFrame::StyledPanel);
        InputArea->setFrameShadow(QFrame::Raised);
        connectGridLayout = new QGridLayout(InputArea);
        connectGridLayout->setObjectName("connectGridLayout");
        connectGridLayout->setHorizontalSpacing(64);
        connectGridLayout->setVerticalSpacing(12);
        connectGridLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(InputArea);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMinimumSize(QSize(0, 48));
        titleLabel->setMaximumSize(QSize(16777215, 64));
        titleLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        connectGridLayout->addWidget(titleLabel, 1, 0, 1, 2);

        FormArea = new QFrame(InputArea);
        FormArea->setObjectName("FormArea");
        FormArea->setMaximumSize(QSize(640, 400));
        FormArea->setFrameShape(QFrame::StyledPanel);
        FormArea->setFrameShadow(QFrame::Raised);
        formVerticalLayout = new QVBoxLayout(FormArea);
        formVerticalLayout->setSpacing(12);
        formVerticalLayout->setObjectName("formVerticalLayout");
        formVerticalLayout->setContentsMargins(0, 0, 0, 0);
        portLabel = new QLabel(FormArea);
        portLabel->setObjectName("portLabel");
        portLabel->setMinimumSize(QSize(0, 32));
        portLabel->setMaximumSize(QSize(16777215, 32));

        formVerticalLayout->addWidget(portLabel);

        portSelect = new QComboBox(FormArea);
        portSelect->setObjectName("portSelect");
        portSelect->setCursor(QCursor(Qt::PointingHandCursor));
        portSelect->setMouseTracking(true);

        formVerticalLayout->addWidget(portSelect);

        FormRefresh = new QFrame(FormArea);
        FormRefresh->setObjectName("FormRefresh");
        FormRefresh->setMinimumSize(QSize(0, 64));
        FormRefresh->setFrameShape(QFrame::StyledPanel);
        FormRefresh->setFrameShadow(QFrame::Raised);
        refreshHorizontalLayout = new QHBoxLayout(FormRefresh);
        refreshHorizontalLayout->setSpacing(0);
        refreshHorizontalLayout->setObjectName("refreshHorizontalLayout");
        refreshHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        formRefreshSpacer = new QSpacerItem(586, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        refreshHorizontalLayout->addItem(formRefreshSpacer);

        formRefreshButton = new QToolButton(FormRefresh);
        formRefreshButton->setObjectName("formRefreshButton");
        formRefreshButton->setCursor(QCursor(Qt::PointingHandCursor));
        formRefreshButton->setMouseTracking(true);

        refreshHorizontalLayout->addWidget(formRefreshButton);


        formVerticalLayout->addWidget(FormRefresh);

        baudLabel = new QLabel(FormArea);
        baudLabel->setObjectName("baudLabel");
        baudLabel->setMinimumSize(QSize(0, 32));
        baudLabel->setMaximumSize(QSize(16777215, 32));

        formVerticalLayout->addWidget(baudLabel);

        baudSelect = new QComboBox(FormArea);
        baudSelect->setObjectName("baudSelect");
        baudSelect->setCursor(QCursor(Qt::PointingHandCursor));
        baudSelect->setMouseTracking(true);

        formVerticalLayout->addWidget(baudSelect);

        formSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formVerticalLayout->addItem(formSpacer);


        connectGridLayout->addWidget(FormArea, 3, 0, 1, 1);

        PortInfoArea = new QFrame(InputArea);
        PortInfoArea->setObjectName("PortInfoArea");
        PortInfoArea->setMaximumSize(QSize(480, 16777215));
        PortInfoArea->setFrameShape(QFrame::StyledPanel);
        PortInfoArea->setFrameShadow(QFrame::Raised);
        portInfoGridLayout = new QGridLayout(PortInfoArea);
        portInfoGridLayout->setSpacing(12);
        portInfoGridLayout->setObjectName("portInfoGridLayout");
        portInfoGridLayout->setContentsMargins(0, 0, 0, 0);
        infoDescriptionLabel = new QLabel(PortInfoArea);
        infoDescriptionLabel->setObjectName("infoDescriptionLabel");

        portInfoGridLayout->addWidget(infoDescriptionLabel, 3, 0, 1, 1);

        infoProductLabel = new QLabel(PortInfoArea);
        infoProductLabel->setObjectName("infoProductLabel");

        portInfoGridLayout->addWidget(infoProductLabel, 7, 0, 1, 1);

        infoPortLabel = new QLabel(PortInfoArea);
        infoPortLabel->setObjectName("infoPortLabel");

        portInfoGridLayout->addWidget(infoPortLabel, 1, 0, 1, 1);

        infoLocationValue = new QLabel(PortInfoArea);
        infoLocationValue->setObjectName("infoLocationValue");

        portInfoGridLayout->addWidget(infoLocationValue, 2, 1, 1, 1);

        infoVendorLabel = new QLabel(PortInfoArea);
        infoVendorLabel->setObjectName("infoVendorLabel");

        portInfoGridLayout->addWidget(infoVendorLabel, 6, 0, 1, 1);

        infoDescriptionValue = new QLabel(PortInfoArea);
        infoDescriptionValue->setObjectName("infoDescriptionValue");

        portInfoGridLayout->addWidget(infoDescriptionValue, 3, 1, 1, 1);

        infoProductValue = new QLabel(PortInfoArea);
        infoProductValue->setObjectName("infoProductValue");

        portInfoGridLayout->addWidget(infoProductValue, 7, 1, 1, 1);

        infoSerialLabel = new QLabel(PortInfoArea);
        infoSerialLabel->setObjectName("infoSerialLabel");

        portInfoGridLayout->addWidget(infoSerialLabel, 5, 0, 1, 1);

        infoVendorValue = new QLabel(PortInfoArea);
        infoVendorValue->setObjectName("infoVendorValue");

        portInfoGridLayout->addWidget(infoVendorValue, 6, 1, 1, 1);

        infoLocationLabel = new QLabel(PortInfoArea);
        infoLocationLabel->setObjectName("infoLocationLabel");

        portInfoGridLayout->addWidget(infoLocationLabel, 2, 0, 1, 1);

        infoPortValue = new QLabel(PortInfoArea);
        infoPortValue->setObjectName("infoPortValue");

        portInfoGridLayout->addWidget(infoPortValue, 1, 1, 1, 1);

        infoManufacturerLabel = new QLabel(PortInfoArea);
        infoManufacturerLabel->setObjectName("infoManufacturerLabel");

        portInfoGridLayout->addWidget(infoManufacturerLabel, 4, 0, 1, 1);

        infoSerialValue = new QLabel(PortInfoArea);
        infoSerialValue->setObjectName("infoSerialValue");

        portInfoGridLayout->addWidget(infoSerialValue, 5, 1, 1, 1);

        infoManufacturerValue = new QLabel(PortInfoArea);
        infoManufacturerValue->setObjectName("infoManufacturerValue");

        portInfoGridLayout->addWidget(infoManufacturerValue, 4, 1, 1, 1);

        portInfoTitleLabel = new QLabel(PortInfoArea);
        portInfoTitleLabel->setObjectName("portInfoTitleLabel");
        portInfoTitleLabel->setMinimumSize(QSize(0, 32));
        portInfoTitleLabel->setMaximumSize(QSize(16777215, 32));

        portInfoGridLayout->addWidget(portInfoTitleLabel, 0, 0, 1, 2);

        infoSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        portInfoGridLayout->addItem(infoSpacer, 8, 0, 1, 2);


        connectGridLayout->addWidget(PortInfoArea, 3, 1, 1, 1);

        subtitleLabel = new QLabel(InputArea);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setMinimumSize(QSize(0, 48));
        subtitleLabel->setMaximumSize(QSize(16777215, 98));
        subtitleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        connectGridLayout->addWidget(subtitleLabel, 2, 0, 1, 2);


        mainAreaLayout->addWidget(InputArea);

        ButtonArea = new QFrame(Connect);
        ButtonArea->setObjectName("ButtonArea");
        ButtonArea->setMinimumSize(QSize(0, 128));
        ButtonArea->setFrameShape(QFrame::StyledPanel);
        ButtonArea->setFrameShadow(QFrame::Raised);
        buttonLayout = new QHBoxLayout(ButtonArea);
        buttonLayout->setSpacing(0);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        connectSpacer = new QSpacerItem(1044, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(connectSpacer);

        connectButton = new QToolButton(ButtonArea);
        connectButton->setObjectName("connectButton");
        connectButton->setCursor(QCursor(Qt::PointingHandCursor));
        connectButton->setMouseTracking(true);
        connectButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        buttonLayout->addWidget(connectButton);


        mainAreaLayout->addWidget(ButtonArea);


        retranslateUi(Connect);

        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QCoreApplication::translate("Connect", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("Connect", "Connect to ESP32-DIS ", nullptr));
        portLabel->setText(QCoreApplication::translate("Connect", "Port:", nullptr));
        formRefreshButton->setText(QCoreApplication::translate("Connect", "Refresh", nullptr));
        baudLabel->setText(QCoreApplication::translate("Connect", "Baud Rate:", nullptr));
        infoDescriptionLabel->setText(QCoreApplication::translate("Connect", "Description:", nullptr));
        infoProductLabel->setText(QCoreApplication::translate("Connect", "Product Identifier:", nullptr));
        infoPortLabel->setText(QCoreApplication::translate("Connect", "Name:", nullptr));
        infoLocationValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoVendorLabel->setText(QCoreApplication::translate("Connect", "Vendor Identifier:", nullptr));
        infoDescriptionValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoProductValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoSerialLabel->setText(QCoreApplication::translate("Connect", "Serial Number:", nullptr));
        infoVendorValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoLocationLabel->setText(QCoreApplication::translate("Connect", "Location:", nullptr));
        infoPortValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoManufacturerLabel->setText(QCoreApplication::translate("Connect", "Manufacturer:", nullptr));
        infoSerialValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        infoManufacturerValue->setText(QCoreApplication::translate("Connect", "TextLabel", nullptr));
        portInfoTitleLabel->setText(QCoreApplication::translate("Connect", "Selected Port Information:", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("Connect", "It looks like you are not connected to your device.", nullptr));
        connectButton->setText(QCoreApplication::translate("Connect", "Connect to Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
