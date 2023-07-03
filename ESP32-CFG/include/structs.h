#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <recordsizes.h>
// %0%
struct Weather_t{
    int weatherCode[7];
    QString date[7];
    QString temperatureMax[7];
    QString temperatureMin[7];
    QString precipSum[7];
};

// %1%
struct Stoptimes_t{
    QString stoptime191[5];
    QString stoptime149[5];
};

// %2%
struct Wifi_t{
    QString SSID;
    QString RSSI;
};

// %3%
struct Room_t{
    QString light;
    QString temperature;
};

// %4%
struct TimeInfo_t{
    QString time;
    QString date;
    QString day;
};

// Configuration struct
struct Credentials_t{
    char SSID[EEPROM_SIZE_SSID];
    char password[EEPROM_SIZE_PASS];
    char url_weather[EEPROM_SIZE_URL];
    char url_bus_a[EEPROM_SIZE_URL], url_bus_b[EEPROM_SIZE_URL];
    char socket_ip[EEPROM_SIZE_IP];
};

#endif // STRUCTS_H
