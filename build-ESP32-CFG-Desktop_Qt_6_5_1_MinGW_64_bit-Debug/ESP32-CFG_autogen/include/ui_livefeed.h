/********************************************************************************
** Form generated from reading UI file 'livefeed.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVEFEED_H
#define UI_LIVEFEED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiveFeed
{
public:
    QGridLayout *gridLayout;
    QFrame *Room;
    QVBoxLayout *verticalLayout_4;
    QLabel *roomLabel;
    QFrame *roomHorizontalSeparator;
    QFrame *roomData;
    QGridLayout *gridLayout_2;
    QLabel *roomLightLabel;
    QLabel *roomTempLabel;
    QLabel *roomLightValue;
    QLabel *roomTempValue;
    QFrame *WiFi;
    QVBoxLayout *verticalLayout_5;
    QLabel *wifiLabel;
    QFrame *wifiHorizontalSpacer;
    QFrame *wifiData;
    QGridLayout *gridLayout_3;
    QLabel *wifiRSSIValue;
    QLabel *wifiRSSILabel;
    QLabel *wifiSSIDLabel;
    QLabel *wifiSSIDValue;
    QFrame *Stoptimes;
    QVBoxLayout *verticalLayout_2;
    QLabel *stoptimesLabel;
    QFrame *horizontalTableSeparatorTop;
    QFrame *labelCentering;
    QHBoxLayout *horizontalLayout;
    QLabel *stoptimesLeftLabel;
    QLabel *stoptimesRightLabel;
    QFrame *horizontalTableSeparatorBottom;
    QFrame *stoptimesTable;
    QHBoxLayout *horizontalLayout_2;
    QFrame *leftColumn;
    QFrame *verticalTableSeparator;
    QFrame *rightColumn;
    QFrame *TimeAndDate;
    QVBoxLayout *verticalLayout;
    QLabel *Time;
    QLabel *Date;
    QLabel *Day;
    QFrame *WeeklyWeather;
    QFrame *DailyWeather;
    QVBoxLayout *verticalLayout_3;
    QLabel *dailyIcon;
    QFrame *dailyTemp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dailyMax;
    QLabel *dailySlash;
    QLabel *dailyMin;
    QLabel *dailyPrecip;
    QLabel *dailyDate;

    void setupUi(QWidget *LiveFeed)
    {
        if (LiveFeed->objectName().isEmpty())
            LiveFeed->setObjectName("LiveFeed");
        LiveFeed->resize(1160, 723);
        LiveFeed->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(LiveFeed);
        gridLayout->setSpacing(16);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(32, 32, 32, 32);
        Room = new QFrame(LiveFeed);
        Room->setObjectName("Room");
        Room->setMinimumSize(QSize(0, 0));
        Room->setMaximumSize(QSize(16777215, 140));
        Room->setFrameShape(QFrame::StyledPanel);
        Room->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(Room);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(32, 16, 32, 16);
        roomLabel = new QLabel(Room);
        roomLabel->setObjectName("roomLabel");
        roomLabel->setMaximumSize(QSize(16777215, 45));
        QFont font;
        font.setBold(true);
        roomLabel->setFont(font);
        roomLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}"));
        roomLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(roomLabel);

        roomHorizontalSeparator = new QFrame(Room);
        roomHorizontalSeparator->setObjectName("roomHorizontalSeparator");
        roomHorizontalSeparator->setMaximumSize(QSize(16777215, 1));
        roomHorizontalSeparator->setFrameShape(QFrame::HLine);
        roomHorizontalSeparator->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(roomHorizontalSeparator);

        roomData = new QFrame(Room);
        roomData->setObjectName("roomData");
        roomData->setFrameShape(QFrame::StyledPanel);
        roomData->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(roomData);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        roomLightLabel = new QLabel(roomData);
        roomLightLabel->setObjectName("roomLightLabel");

        gridLayout_2->addWidget(roomLightLabel, 0, 0, 1, 1);

        roomTempLabel = new QLabel(roomData);
        roomTempLabel->setObjectName("roomTempLabel");

        gridLayout_2->addWidget(roomTempLabel, 2, 0, 1, 1);

        roomLightValue = new QLabel(roomData);
        roomLightValue->setObjectName("roomLightValue");

        gridLayout_2->addWidget(roomLightValue, 0, 1, 1, 1);

        roomTempValue = new QLabel(roomData);
        roomTempValue->setObjectName("roomTempValue");

        gridLayout_2->addWidget(roomTempValue, 2, 1, 1, 1);


        verticalLayout_4->addWidget(roomData);


        gridLayout->addWidget(Room, 2, 1, 1, 1);

        WiFi = new QFrame(LiveFeed);
        WiFi->setObjectName("WiFi");
        WiFi->setFrameShape(QFrame::StyledPanel);
        WiFi->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(WiFi);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(32, 16, 32, 16);
        wifiLabel = new QLabel(WiFi);
        wifiLabel->setObjectName("wifiLabel");
        wifiLabel->setMaximumSize(QSize(16777215, 45));
        wifiLabel->setFont(font);
        wifiLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}"));
        wifiLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(wifiLabel);

        wifiHorizontalSpacer = new QFrame(WiFi);
        wifiHorizontalSpacer->setObjectName("wifiHorizontalSpacer");
        wifiHorizontalSpacer->setMaximumSize(QSize(16777215, 1));
        wifiHorizontalSpacer->setFrameShape(QFrame::HLine);
        wifiHorizontalSpacer->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(wifiHorizontalSpacer);

        wifiData = new QFrame(WiFi);
        wifiData->setObjectName("wifiData");
        wifiData->setFrameShape(QFrame::StyledPanel);
        wifiData->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(wifiData);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        wifiRSSIValue = new QLabel(wifiData);
        wifiRSSIValue->setObjectName("wifiRSSIValue");

        gridLayout_3->addWidget(wifiRSSIValue, 2, 1, 1, 1);

        wifiRSSILabel = new QLabel(wifiData);
        wifiRSSILabel->setObjectName("wifiRSSILabel");

        gridLayout_3->addWidget(wifiRSSILabel, 2, 0, 1, 1);

        wifiSSIDLabel = new QLabel(wifiData);
        wifiSSIDLabel->setObjectName("wifiSSIDLabel");

        gridLayout_3->addWidget(wifiSSIDLabel, 0, 0, 1, 1);

        wifiSSIDValue = new QLabel(wifiData);
        wifiSSIDValue->setObjectName("wifiSSIDValue");

        gridLayout_3->addWidget(wifiSSIDValue, 0, 1, 1, 1);


        verticalLayout_5->addWidget(wifiData);


        gridLayout->addWidget(WiFi, 2, 2, 1, 1);

        Stoptimes = new QFrame(LiveFeed);
        Stoptimes->setObjectName("Stoptimes");
        Stoptimes->setMinimumSize(QSize(200, 0));
        Stoptimes->setMaximumSize(QSize(350, 16777215));
        Stoptimes->setFrameShape(QFrame::StyledPanel);
        Stoptimes->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(Stoptimes);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(32, 16, 32, 16);
        stoptimesLabel = new QLabel(Stoptimes);
        stoptimesLabel->setObjectName("stoptimesLabel");
        stoptimesLabel->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(32);
        stoptimesLabel->setFont(font1);
        stoptimesLabel->setStyleSheet(QString::fromUtf8("font-size: 32pt;"));
        stoptimesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(stoptimesLabel);

        horizontalTableSeparatorTop = new QFrame(Stoptimes);
        horizontalTableSeparatorTop->setObjectName("horizontalTableSeparatorTop");
        horizontalTableSeparatorTop->setMaximumSize(QSize(16777215, 1));
        horizontalTableSeparatorTop->setFrameShape(QFrame::HLine);
        horizontalTableSeparatorTop->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(horizontalTableSeparatorTop);

        labelCentering = new QFrame(Stoptimes);
        labelCentering->setObjectName("labelCentering");
        labelCentering->setMaximumSize(QSize(16777215, 30));
        labelCentering->setFrameShape(QFrame::StyledPanel);
        labelCentering->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(labelCentering);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 2);
        stoptimesLeftLabel = new QLabel(labelCentering);
        stoptimesLeftLabel->setObjectName("stoptimesLeftLabel");
        stoptimesLeftLabel->setFont(font);
        stoptimesLeftLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}"));
        stoptimesLeftLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(stoptimesLeftLabel);

        stoptimesRightLabel = new QLabel(labelCentering);
        stoptimesRightLabel->setObjectName("stoptimesRightLabel");
        stoptimesRightLabel->setFont(font);
        stoptimesRightLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}"));
        stoptimesRightLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(stoptimesRightLabel);


        verticalLayout_2->addWidget(labelCentering);

        horizontalTableSeparatorBottom = new QFrame(Stoptimes);
        horizontalTableSeparatorBottom->setObjectName("horizontalTableSeparatorBottom");
        horizontalTableSeparatorBottom->setMaximumSize(QSize(16777215, 1));
        horizontalTableSeparatorBottom->setFrameShape(QFrame::HLine);
        horizontalTableSeparatorBottom->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(horizontalTableSeparatorBottom);

        stoptimesTable = new QFrame(Stoptimes);
        stoptimesTable->setObjectName("stoptimesTable");
        stoptimesTable->setFrameShape(QFrame::StyledPanel);
        stoptimesTable->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(stoptimesTable);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leftColumn = new QFrame(stoptimesTable);
        leftColumn->setObjectName("leftColumn");
        leftColumn->setStyleSheet(QString::fromUtf8("padding-top: 6px;"));
        leftColumn->setFrameShape(QFrame::StyledPanel);
        leftColumn->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(leftColumn);

        verticalTableSeparator = new QFrame(stoptimesTable);
        verticalTableSeparator->setObjectName("verticalTableSeparator");
        verticalTableSeparator->setMaximumSize(QSize(1, 16777215));
        verticalTableSeparator->setFrameShape(QFrame::VLine);
        verticalTableSeparator->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(verticalTableSeparator);

        rightColumn = new QFrame(stoptimesTable);
        rightColumn->setObjectName("rightColumn");
        rightColumn->setStyleSheet(QString::fromUtf8("padding-top: 6px;"));
        rightColumn->setFrameShape(QFrame::StyledPanel);
        rightColumn->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(rightColumn);


        verticalLayout_2->addWidget(stoptimesTable);


        gridLayout->addWidget(Stoptimes, 0, 2, 1, 1);

        TimeAndDate = new QFrame(LiveFeed);
        TimeAndDate->setObjectName("TimeAndDate");
        TimeAndDate->setMinimumSize(QSize(200, 0));
        TimeAndDate->setMaximumSize(QSize(16777215, 16777215));
        TimeAndDate->setFrameShape(QFrame::StyledPanel);
        TimeAndDate->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(TimeAndDate);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(32, 16, 32, 16);
        Time = new QLabel(TimeAndDate);
        Time->setObjectName("Time");
        Time->setMinimumSize(QSize(0, 0));
        Time->setFont(font);
        Time->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 124px;\n"
"	font-weight: bold;\n"
"}\n"
""));

        verticalLayout->addWidget(Time);

        Date = new QLabel(TimeAndDate);
        Date->setObjectName("Date");
        Date->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 32px;\n"
"}"));

        verticalLayout->addWidget(Date);

        Day = new QLabel(TimeAndDate);
        Day->setObjectName("Day");
        Day->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size: 32px;\n"
"}"));

        verticalLayout->addWidget(Day);


        gridLayout->addWidget(TimeAndDate, 0, 0, 1, 1);

        WeeklyWeather = new QFrame(LiveFeed);
        WeeklyWeather->setObjectName("WeeklyWeather");
        WeeklyWeather->setMinimumSize(QSize(0, 140));
        WeeklyWeather->setMaximumSize(QSize(16777215, 160));
        WeeklyWeather->setFrameShape(QFrame::StyledPanel);
        WeeklyWeather->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(WeeklyWeather, 3, 0, 1, 3);

        DailyWeather = new QFrame(LiveFeed);
        DailyWeather->setObjectName("DailyWeather");
        DailyWeather->setMinimumSize(QSize(0, 0));
        DailyWeather->setMaximumSize(QSize(350, 16777215));
        DailyWeather->setStyleSheet(QString::fromUtf8(""));
        DailyWeather->setFrameShape(QFrame::StyledPanel);
        DailyWeather->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(DailyWeather);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(32, 16, 32, 16);
        dailyIcon = new QLabel(DailyWeather);
        dailyIcon->setObjectName("dailyIcon");
        dailyIcon->setMinimumSize(QSize(80, 140));
        dailyIcon->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(dailyIcon);

        dailyTemp = new QFrame(DailyWeather);
        dailyTemp->setObjectName("dailyTemp");
        dailyTemp->setFrameShape(QFrame::StyledPanel);
        dailyTemp->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(dailyTemp);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dailyMax = new QLabel(dailyTemp);
        dailyMax->setObjectName("dailyMax");
        dailyMax->setMinimumSize(QSize(0, 18));
        QFont font2;
        font2.setPointSize(12);
        dailyMax->setFont(font2);
        dailyMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(dailyMax);

        dailySlash = new QLabel(dailyTemp);
        dailySlash->setObjectName("dailySlash");
        dailySlash->setMinimumSize(QSize(0, 18));
        dailySlash->setMaximumSize(QSize(20, 16777215));
        dailySlash->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(dailySlash);

        dailyMin = new QLabel(dailyTemp);
        dailyMin->setObjectName("dailyMin");
        dailyMin->setMinimumSize(QSize(0, 18));
        dailyMin->setFont(font2);
        dailyMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(dailyMin);


        verticalLayout_3->addWidget(dailyTemp);

        dailyPrecip = new QLabel(DailyWeather);
        dailyPrecip->setObjectName("dailyPrecip");
        dailyPrecip->setMinimumSize(QSize(0, 18));
        dailyPrecip->setFont(font2);
        dailyPrecip->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(dailyPrecip);

        dailyDate = new QLabel(DailyWeather);
        dailyDate->setObjectName("dailyDate");
        dailyDate->setMinimumSize(QSize(0, 18));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        dailyDate->setFont(font3);
        dailyDate->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(dailyDate);


        gridLayout->addWidget(DailyWeather, 0, 1, 1, 1);


        retranslateUi(LiveFeed);

        QMetaObject::connectSlotsByName(LiveFeed);
    } // setupUi

    void retranslateUi(QWidget *LiveFeed)
    {
        LiveFeed->setWindowTitle(QCoreApplication::translate("LiveFeed", "Form", nullptr));
        roomLabel->setText(QCoreApplication::translate("LiveFeed", "Room Status", nullptr));
        roomLightLabel->setText(QCoreApplication::translate("LiveFeed", "Light:", nullptr));
        roomTempLabel->setText(QCoreApplication::translate("LiveFeed", "Temp.:", nullptr));
        roomLightValue->setText(QCoreApplication::translate("LiveFeed", "lightStatus", nullptr));
        roomTempValue->setText(QCoreApplication::translate("LiveFeed", "tempValue", nullptr));
        wifiLabel->setText(QCoreApplication::translate("LiveFeed", "WiFi Status", nullptr));
        wifiRSSIValue->setText(QCoreApplication::translate("LiveFeed", "rssiValue", nullptr));
        wifiRSSILabel->setText(QCoreApplication::translate("LiveFeed", "RSSI:", nullptr));
        wifiSSIDLabel->setText(QCoreApplication::translate("LiveFeed", "SSID:", nullptr));
        wifiSSIDValue->setText(QCoreApplication::translate("LiveFeed", "ssidValue", nullptr));
        stoptimesLabel->setText(QCoreApplication::translate("LiveFeed", "STOPTIMES", nullptr));
        stoptimesLeftLabel->setText(QCoreApplication::translate("LiveFeed", "191", nullptr));
        stoptimesRightLabel->setText(QCoreApplication::translate("LiveFeed", "149", nullptr));
        Time->setText(QCoreApplication::translate("LiveFeed", "23:59", nullptr));
        Date->setText(QCoreApplication::translate("LiveFeed", "01/01/2023", nullptr));
        Day->setText(QCoreApplication::translate("LiveFeed", "Monday", nullptr));
        dailyIcon->setText(QCoreApplication::translate("LiveFeed", "weatherIcon", nullptr));
        dailyMax->setText(QCoreApplication::translate("LiveFeed", "10.0", nullptr));
        dailySlash->setText(QCoreApplication::translate("LiveFeed", "/", nullptr));
        dailyMin->setText(QCoreApplication::translate("LiveFeed", "0.0", nullptr));
        dailyPrecip->setText(QCoreApplication::translate("LiveFeed", "0.00 mm", nullptr));
        dailyDate->setText(QCoreApplication::translate("LiveFeed", "01/01/2023", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiveFeed: public Ui_LiveFeed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVEFEED_H
