/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *CentralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *ControlBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *hSpacer;
    QToolButton *controlMinimize;
    QToolButton *controlClose;
    QWidget *ContentWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *LeftMenu;
    QVBoxLayout *verticalLayout_3;
    QLabel *appTitle;
    QLabel *appSubtitle;
    QLabel *verticalSplit;
    QToolButton *menuLiveFeed;
    QToolButton *menuConfigure;
    QToolButton *menuAbout;
    QSpacerItem *verticalSpacer;
    QToolButton *disconnectButton;
    QWidget *CurrentMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 700);
        MainWindow->setMinimumSize(QSize(1400, 700));
        MainWindow->setMaximumSize(QSize(1400, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #232B32;"));
        CentralWidget = new QWidget(MainWindow);
        CentralWidget->setObjectName("CentralWidget");
        CentralWidget->setEnabled(true);
        CentralWidget->setMinimumSize(QSize(640, 360));
        CentralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(CentralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ControlBar = new QWidget(CentralWidget);
        ControlBar->setObjectName("ControlBar");
        ControlBar->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlBar->sizePolicy().hasHeightForWidth());
        ControlBar->setSizePolicy(sizePolicy);
        ControlBar->setMinimumSize(QSize(0, 35));
        ControlBar->setMaximumSize(QSize(16777215, 35));
        ControlBar->setStyleSheet(QString::fromUtf8("background-color: #161A1F;\n"
""));
        horizontalLayout_2 = new QHBoxLayout(ControlBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(hSpacer);

        controlMinimize = new QToolButton(ControlBar);
        controlMinimize->setObjectName("controlMinimize");
        controlMinimize->setMinimumSize(QSize(55, 35));
        controlMinimize->setCursor(QCursor(Qt::PointingHandCursor));
        controlMinimize->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border: 0px solid;\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background: #3b47d9;\n"
"}\n"
"\n"
"QToolButton:focus{\n"
"    outline: none;\n"
"}"));

        horizontalLayout_2->addWidget(controlMinimize);

        controlClose = new QToolButton(ControlBar);
        controlClose->setObjectName("controlClose");
        controlClose->setMinimumSize(QSize(55, 35));
        controlClose->setCursor(QCursor(Qt::PointingHandCursor));
        controlClose->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border: 0px solid;\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background: #e74c3c;\n"
"}\n"
"\n"
"QToolButton:focus{\n"
"    outline: none;\n"
"}"));

        horizontalLayout_2->addWidget(controlClose);


        verticalLayout->addWidget(ControlBar);

        ContentWidget = new QWidget(CentralWidget);
        ContentWidget->setObjectName("ContentWidget");
        horizontalLayout_3 = new QHBoxLayout(ContentWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        LeftMenu = new QWidget(ContentWidget);
        LeftMenu->setObjectName("LeftMenu");
        LeftMenu->setMinimumSize(QSize(240, 0));
        LeftMenu->setMaximumSize(QSize(240, 16777215));
        LeftMenu->setStyleSheet(QString::fromUtf8("background-color: #171F24;\n"
""));
        verticalLayout_3 = new QVBoxLayout(LeftMenu);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(16, 32, 16, 32);
        appTitle = new QLabel(LeftMenu);
        appTitle->setObjectName("appTitle");
        appTitle->setMinimumSize(QSize(0, 64));
        appTitle->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: #98A1B7;\n"
"	border: 0px solid;\n"
"	font-weight: bold;\n"
"	font-size: 32px;\n"
"}"));

        verticalLayout_3->addWidget(appTitle);

        appSubtitle = new QLabel(LeftMenu);
        appSubtitle->setObjectName("appSubtitle");
        appSubtitle->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: #98A1B7;\n"
"	font-size: 18px;\n"
"}"));

        verticalLayout_3->addWidget(appSubtitle);

        verticalSplit = new QLabel(LeftMenu);
        verticalSplit->setObjectName("verticalSplit");
        verticalSplit->setMaximumSize(QSize(16777215, 2));
        verticalSplit->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: #98A1B7;\n"
"	border: 0px solid;\n"
"	border-radius:0.5px;\n"
"}"));

        verticalLayout_3->addWidget(verticalSplit);

        menuLiveFeed = new QToolButton(LeftMenu);
        menuLiveFeed->setObjectName("menuLiveFeed");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menuLiveFeed->sizePolicy().hasHeightForWidth());
        menuLiveFeed->setSizePolicy(sizePolicy1);
        menuLiveFeed->setMinimumSize(QSize(0, 60));
        menuLiveFeed->setCursor(QCursor(Qt::PointingHandCursor));
        menuLiveFeed->setMouseTracking(true);
        menuLiveFeed->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color: #98A1B7;\n"
"	border: 0px solid;\n"
"	border-radius: 5px;\n"
"  	text-decoration: none;\n"
"	font-size: 20px;\n"
"	padding: 0px 0px 0px 20px;\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background-color: #272F37;\n"
"	color: #D0D9F6;\n"
"}"));
        menuLiveFeed->setIconSize(QSize(32, 32));
        menuLiveFeed->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_3->addWidget(menuLiveFeed);

        menuConfigure = new QToolButton(LeftMenu);
        menuConfigure->setObjectName("menuConfigure");
        sizePolicy1.setHeightForWidth(menuConfigure->sizePolicy().hasHeightForWidth());
        menuConfigure->setSizePolicy(sizePolicy1);
        menuConfigure->setMinimumSize(QSize(0, 60));
        menuConfigure->setCursor(QCursor(Qt::PointingHandCursor));
        menuConfigure->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color: #98A1B7;\n"
"	border: 0px solid;\n"
"	border-radius: 5px;\n"
"  	text-decoration: none;\n"
"	font-size: 20px;\n"
"	padding: 0px 0px 0px 20px;\n"
"\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background-color: #272F37;\n"
"	color: #D0D9F6;\n"
"}"));
        menuConfigure->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_3->addWidget(menuConfigure);

        menuAbout = new QToolButton(LeftMenu);
        menuAbout->setObjectName("menuAbout");
        sizePolicy1.setHeightForWidth(menuAbout->sizePolicy().hasHeightForWidth());
        menuAbout->setSizePolicy(sizePolicy1);
        menuAbout->setMinimumSize(QSize(0, 60));
        menuAbout->setCursor(QCursor(Qt::PointingHandCursor));
        menuAbout->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color: #98A1B7;\n"
"	border: 0px solid;\n"
"	border-radius: 5px;\n"
"  	text-decoration: none;\n"
"	font-size: 20px;\n"
"	padding: 0px 0px 0px 20px;\n"
"\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background-color: #272F37;\n"
"	color: #D0D9F6;\n"
"}"));
        menuAbout->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_3->addWidget(menuAbout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        disconnectButton = new QToolButton(LeftMenu);
        disconnectButton->setObjectName("disconnectButton");
        sizePolicy1.setHeightForWidth(disconnectButton->sizePolicy().hasHeightForWidth());
        disconnectButton->setSizePolicy(sizePolicy1);
        disconnectButton->setMinimumSize(QSize(0, 60));
        disconnectButton->setCursor(QCursor(Qt::PointingHandCursor));
        disconnectButton->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color: #98A1B7;\n"
"	border: 0px solid;\n"
"	border-radius: 5px;\n"
"  	text-decoration: none;\n"
"	font-size: 20px;\n"
"	padding: 0px 0px 0px 20px;\n"
"\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background-color: #272F37;\n"
"	color: #D0D9F6;\n"
"}"));
        disconnectButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_3->addWidget(disconnectButton);


        horizontalLayout_3->addWidget(LeftMenu);

        CurrentMenu = new QWidget(ContentWidget);
        CurrentMenu->setObjectName("CurrentMenu");

        horizontalLayout_3->addWidget(CurrentMenu);


        verticalLayout->addWidget(ContentWidget);

        MainWindow->setCentralWidget(CentralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        controlMinimize->setText(QString());
        controlClose->setText(QString());
        appTitle->setText(QCoreApplication::translate("MainWindow", "ESP32-DIS", nullptr));
        appSubtitle->setText(QCoreApplication::translate("MainWindow", "Configuration Tool", nullptr));
        verticalSplit->setText(QString());
        menuLiveFeed->setText(QCoreApplication::translate("MainWindow", "   Live Feed", nullptr));
        menuConfigure->setText(QCoreApplication::translate("MainWindow", "   Configure", nullptr));
        menuAbout->setText(QCoreApplication::translate("MainWindow", "   About", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "   Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
