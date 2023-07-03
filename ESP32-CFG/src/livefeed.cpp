#include "livefeed.h"
#include "./ui_livefeed.h"

#include "fontsizes.h"
#include "fontweights.h"
#include "colordefinitions.h"

#include "iconpainter.h"
#include "weathericon.h"
#include "styleloader.h"

LiveFeed::LiveFeed(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LiveFeed)
{
    ui->setupUi(this);
    populateStoptimes();
    populateWeeklyWeather();
    setupStyles();

    //TEMP

    Weather_t temp;
    temp.weatherCode[0] = 0;
    temp.date[0] = QString("01/01/2023");
    temp.temperatureMax[0] = QString("10.0");
    temp.temperatureMin[0] = QString("0.0");
    temp.precipSum[0] = QString("0.0");

    updateDailyWeather(temp);
    updateWeeklyWeather(temp);

}

LiveFeed::~LiveFeed(){
    delete ui;
}

void LiveFeed::populateStoptimes(){
    QVBoxLayout * leftLayout = new QVBoxLayout;
    QVBoxLayout * rightLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(0,0,0,0);
    rightLayout->setContentsMargins(0,0,0,0);
    leftLayout->setSpacing(0);
    rightLayout->setSpacing(0);
    ui->leftColumn->setLayout(leftLayout);
    ui->rightColumn->setLayout(rightLayout);
    const int entry_count = 5;
    for(int i = 0; i < entry_count; i++){
        QLabel * left_entry = new QLabel("left");
        QLabel * right_entry = new QLabel("right");
        QFont r = QFont(regular_weight, font_size_regular);
        left_entry->setFont(r);
        right_entry->setFont(r);
        left_entry->setStyleSheet(StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss"));
        right_entry->setStyleSheet(StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss"));
        left_entry->setMinimumHeight(18);
        right_entry->setMinimumHeight(18);
        left_entry->setAlignment(Qt::AlignHCenter);
        right_entry->setAlignment(Qt::AlignHCenter);
        leftColumn.push_back(left_entry);
        rightColumn.push_back(right_entry);
        leftLayout->addWidget(left_entry);
        rightLayout->addWidget(right_entry);
    }
}

void LiveFeed::populateWeeklyWeather(){
    QHBoxLayout * weeklyWeatherLayout = new QHBoxLayout;
    weeklyWeatherLayout->setContentsMargins(32, 16, 32, 16);
    weeklyWeatherLayout->setSpacing(0);
    ui->WeeklyWeather->setLayout(weeklyWeatherLayout);

    QString lineStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qline.qss");

    const int entry_count = 7;
    for(int i = 0; i < entry_count; i++){
        WeeklyWeatherEntry * current_entry = new WeeklyWeatherEntry;
        current_entry->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        weeklyWeather.push_back(current_entry);
        weeklyWeatherLayout->addWidget(current_entry);
        current_entry->styleUI();
        if(i < entry_count - 1){
            QFrame * verticalSeparator = new QFrame;
            verticalSeparator->setObjectName("lineSep");
            verticalSeparator->setFrameShape(QFrame::VLine);
            verticalSeparator->setStyleSheet(lineStyleString);
            verticalSeparator->setMaximumWidth(1);
            weeklyWeatherLayout->addWidget(verticalSeparator);
        }
    }
}

void LiveFeed::updateStoptimes(Stoptimes_t stoptimes){
    const int entry_count = 5;
    for(int i = 0; i < entry_count; i++){
        leftColumn.at(i)->setText(stoptimes.stoptime191[i]);
        rightColumn.at(i)->setText(stoptimes.stoptime149[i]);
    }
}

void LiveFeed::updateWeeklyWeather(Weather_t weather){
    const int entry_count = 7;
    for(int i = 0; i < entry_count; i++){
        weeklyWeather.at(i)->updateContents(weather, i);
    }
}

void LiveFeed::updateTime(TimeInfo_t time){
    ui->Time->setText(time.time);
    ui->Date->setText(time.date);
    ui->Day->setText(time.day);
}

void LiveFeed::updateRoom(Room_t room){
    ui->roomLightValue->setText(room.light);
    ui->roomTempValue->setText(room.temperature);
}

void LiveFeed::updateWiFi(Wifi_t wifi){
    ui->wifiSSIDValue->setText(wifi.SSID);
    ui->wifiRSSIValue->setText(QString("%1 dBm").arg(wifi.RSSI));
}

void LiveFeed::updateDailyWeather(Weather_t weather){
    ui->dailyIcon->setText("");
    IconPainter painter;
    QPixmap p = painter.getIconFromFile(font_default_color, getIconFileName(weather.weatherCode[0]));
    ui->dailyIcon->setPixmap(p.scaled(128,128, Qt::KeepAspectRatio));
    ui->dailyMax->setText(weather.temperatureMax[0]);
    ui->dailyMin->setText(weather.temperatureMin[0]);
    ui->dailyPrecip->setText(QString("%1 mm").arg(weather.precipSum[0]));
    ui->dailyDate->setText(weather.date[0]);
}

void LiveFeed::setupStyles(){
    styleFrames();
    styleSeparators();
    styleText();
    setFontSizes();
}

void LiveFeed::styleFrames(){
    QString frameStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qframe.qss");

    QVector<QFrame *> main_frames = {ui->TimeAndDate, ui->DailyWeather, ui->Stoptimes, ui->Room, ui->WiFi, ui->WeeklyWeather};
    for(int i = 0; i < main_frames.size(); i++){
        QFrame * current_frame = main_frames.at(i);
        current_frame->setObjectName("mainFrame");
        current_frame->setStyleSheet(frameStyleString);
    }
}

void LiveFeed::styleSeparators(){
    QString lineStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qline.qss");

    QVector<QFrame *> line_separators = {ui->horizontalTableSeparatorBottom, ui->horizontalTableSeparatorTop, ui->roomHorizontalSeparator, ui->wifiHorizontalSpacer, ui->verticalTableSeparator};
    for(int i = 0; i < line_separators.size(); i++){
        QFrame * current_line = line_separators.at(i);
        current_line->setObjectName("lineSep");
        current_line->setStyleSheet(lineStyleString);
    }
}

void LiveFeed::styleText(){
    QString fontStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss");

    QVector<QLabel *> labels = ui->Room->parent()->findChildren<QLabel *>(Qt::FindChildrenRecursively);
    for(int i = 0; i < labels.size(); i++){
        QLabel * current_label = labels.at(i);
        current_label->setStyleSheet(fontStyleString);
    }
}

void LiveFeed::setFontSizes(){
    QFont r = QFont(regular_weight, font_size_regular);
    QFont s = QFont(semiBold_weight, font_size_regular);
    QFont b = QFont(extraBold_weight, font_size_regular);
    ui->Time->setFont(b);
    ui->Time->setStyleSheet(getStyleForFontSize(font_size_time));
    ui->Date->setFont(s);
    ui->Date->setStyleSheet(getStyleForFontSize(font_size_heading));
    ui->Day->setFont(s);
    ui->Day->setStyleSheet(getStyleForFontSize(font_size_heading));
    ui->roomLabel->setFont(s);
    ui->roomLabel->setStyleSheet(getStyleForFontSize(font_size_subsection_title));
    ui->wifiLabel->setFont(s);
    ui->wifiLabel->setStyleSheet(getStyleForFontSize(font_size_subsection_title));
    ui->stoptimesLabel->setFont(s);
    ui->stoptimesLabel->setStyleSheet(getStyleForFontSize(font_size_heading));
    ui->stoptimesLeftLabel->setFont(s);
    ui->stoptimesLeftLabel->setStyleSheet(getStyleForFontSize(font_size_subsection_title));
    ui->stoptimesRightLabel->setFont(s);
    ui->stoptimesRightLabel->setStyleSheet(getStyleForFontSize(font_size_subsection_title));
    ui->dailyMax->setFont(s);
    // Due to font autoscaling in the labels I have to set up these too
    ui->dailySlash->setFont(r);
    ui->dailyMin->setFont(r);
    ui->dailyPrecip->setFont(r);
    ui->dailyDate->setFont(s);

}

QString LiveFeed::getStyleForFontSize(const int fontSize){
    QString style = StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss");
    style.insert(style.indexOf('}') - 1, QString("font-size: %1px;\r").arg(fontSize));
    return style;
}
