#ifndef LIVEFEED_H
#define LIVEFEED_H

#include <QWidget>
#include <QFile>
#include <QLabel>

#include "weeklyweatherentry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LiveFeed; }
QT_END_NAMESPACE

class LiveFeed : public QWidget
{
    Q_OBJECT
public:
    explicit LiveFeed(QWidget *parent = nullptr);
    ~LiveFeed();

    // Updates the stoptimes section
    void updateStoptimes(Stoptimes_t stoptimes);
    // Updates the weekly weather section
    void updateWeeklyWeather(Weather_t weather);
    // Updates the time section
    void updateTime(TimeInfo_t time);
    // Updates the room section
    void updateRoom(Room_t room);
    // Updates the wifi section
    void updateWiFi(Wifi_t wifi);
    // Updates the daily weather section
    void updateDailyWeather(Weather_t weather);

signals:

private:
    Ui::LiveFeed *ui;

    QVector<QLabel *> leftColumn;
    QVector<QLabel *> rightColumn;

    QVector<WeeklyWeatherEntry *> weeklyWeather;

    // Populates the stoptimes table with modifiable entries
    void populateStoptimes();
    // Populates the weekly weather box with modifiable entries
    void populateWeeklyWeather();

    // Fills all of the entries with dummy values
    void fillDummyValues();

    // Sets up the styling for the main components
    void setupStyles();

    // Styles the frames of each section
    void styleFrames();
    // Styles the thin separators
    void styleSeparators();
    // Styles all of the text contained within QLabels
    void styleText();
    // Sets font size to all non-standard QLabels
    void setFontSizes();

    // Returns stylesheet for a specific point size
    QString getStyleForFontSize(const int fontSize);
};

#endif // LIVEFEED_H
