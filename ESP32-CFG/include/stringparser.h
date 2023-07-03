#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <structs.h>
#include <QString>
#include <QStringList>
#include <QRegularExpression>

namespace StringParser{
    // Parses a string containing live feed data into a string list
    QStringList parse_live_feed(const QString input);
    // Converts a string with weather data to a struct
    Weather_t convert_weather(const QString input);
    // Converts a string with stoptimes data to a struct
    Stoptimes_t convert_stoptimes(const QString input);
    // Converts a string with wifi data to a struct
    Wifi_t convert_wifi(const QString input);
    // Converts a string with room data to a struct
    Room_t convert_room(const QString input);
    // Converts a string with time info data to a struct
    TimeInfo_t convert_time_info(const QString input);
}

#endif // STRINGPARSER_H
