#include "weeklyweatherentry.h"

#include "fontsizes.h"
#include "fontweights.h"
#include "colordefinitions.h"

#include "iconpainter.h"

#include "weathericon.h"

WeeklyWeatherEntry::WeeklyWeatherEntry(){
    createUI();
}

void WeeklyWeatherEntry::createUI(){
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLayout);

    icon = new QLabel("Icon");

    QFrame * dailyMaxFrame = new QFrame;
    QHBoxLayout * dailyMaxLayout = new QHBoxLayout;
    dailyMaxLayout->setSpacing(0);
    dailyMaxLayout->setContentsMargins(0, 0, 0, 0);
    dailyMaxFrame->setMinimumHeight(font_size_small + 4);
    dailyMax = new QLabel("dailyMax");
    slash = new QLabel("/");
    dailyMin = new QLabel("dailyMin");
    dailyMaxLayout->addWidget(dailyMax);
    dailyMaxLayout->addWidget(slash);
    dailyMaxLayout->addWidget(dailyMin);
    dailyMaxFrame->setLayout(dailyMaxLayout);

    precip = new QLabel("Precip");
    date = new QLabel("Date");

    mainLayout->addWidget(icon);
    mainLayout->addWidget(dailyMaxFrame);
    mainLayout->addWidget(precip);
    mainLayout->addWidget(date);
}

void WeeklyWeatherEntry::styleUI(){
    // Set alignments
    icon->setAlignment(Qt::AlignHCenter);
    dailyMax->setAlignment(Qt::AlignRight);
    slash->setAlignment(Qt::AlignHCenter);
    dailyMin->setAlignment(Qt::AlignLeft);
    precip->setAlignment(Qt::AlignHCenter);
    date->setAlignment(Qt::AlignHCenter);

    // Set maximal width of slash
    slash->setMaximumWidth(16);

    // Set minimal size of the icon
    icon->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    icon->setMinimumHeight(64);

    precip->setMinimumHeight(font_size_small + 4);
    date->setMinimumHeight(font_size_small + 4);

    //Fonts
    QFont r = QFont(regular_weight, font_size_small);
    QFont s = QFont(semiBold_weight, font_size_small);

    dailyMax->setFont(s);
    slash->setFont(r);
    dailyMin->setFont(r);
    precip->setFont(r);
    date->setFont(s);
}

void WeeklyWeatherEntry::updateContents(Weather_t weather, int index){
    icon->setText("");
    IconPainter painter;
    QPixmap p = painter.getIconFromFile(font_default_color, getIconFileName(weather.weatherCode[index]));
    icon->setPixmap(p.scaled(64, 64, Qt::KeepAspectRatio));
    dailyMax->setText(weather.temperatureMax[index]);
    dailyMin->setText(weather.temperatureMin[index]);
    precip->setText(QString("%1 mm").arg(weather.precipSum[index]));
    date->setText(weather.date[index]);
}
