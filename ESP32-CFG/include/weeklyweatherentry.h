#ifndef WEEKLYWEATHERENTRY_H
#define WEEKLYWEATHERENTRY_H

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QPixmap>

#include "structs.h"

class WeeklyWeatherEntry : public QFrame
{
public:
    WeeklyWeatherEntry();

    // Update the contents
    void updateContents(Weather_t weather, int index);
    // Style the UI
    void styleUI();
private:
    QLabel * icon, * dailyMax, * slash, * dailyMin, * precip, * date;

    // Set up the UI manually
    void createUI();
};

#endif // WEEKLYWEATHERENTRY_H
