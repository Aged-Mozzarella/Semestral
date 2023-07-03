#include "stringparser.h"

QStringList StringParser::parse_live_feed(const QString input){
    QStringList cmds;
    static QRegularExpression rx = QRegularExpression("%[0-9]+%");
    QRegularExpressionMatchIterator rxIt = rx.globalMatch(input);
    while(rxIt.hasNext()){
        QRegularExpressionMatch match = rxIt.next();
        cmds << match.captured();
    }
    QStringList payload = input.split(rx);
    payload.removeFirst();
    QStringList res;
    for(int i = 0; i < cmds.size(); i++){
        QString str = payload.at(i);
        QString cmd = cmds.at(i);
        cmd.append(str);
        res << cmd;
    }
    return res;
}

Weather_t StringParser::convert_weather(const QString input){
    Weather_t weather;

    QStringList weeklyWeather = input.split("&");
    if(!weeklyWeather.isEmpty()){
        weeklyWeather.takeFirst();
    }
    int day = 0;
    for(QString & dWeather : weeklyWeather){
        QStringList dailyWeather = dWeather.split("?");
        QStringList dateSplit = dailyWeather.at(0).split("-");
        QString date = QString("%3/%2/%1").arg(dateSplit.at(0), dateSplit.at(1), dateSplit.at(2));
        QString max = dailyWeather.at(2);
        if(!max.contains(".")){
            max.append(".0");
        }
        QString min = dailyWeather.at(3);
        if(!min.contains(".")){
            min.append(".0");
        }
        QString precip = dailyWeather.at(4);
        if(!precip.contains(".")){
            precip.append(".0");
        }
        weather.date[day] = date;
        weather.weatherCode[day] = dailyWeather.at(1).toInt();
        weather.temperatureMax[day] = max;
        weather.temperatureMin[day] = min;
        weather.precipSum[day] = precip;
        day++;
    }
    return weather;
}

Stoptimes_t StringParser::convert_stoptimes(const QString input){
    QStringList splitInput = input.split("%");
    QStringList stoptimes191 = splitInput.constFirst().split("&");
    QStringList stoptimes149 = splitInput.constLast().split("&");
    if(!stoptimes191.isEmpty()){
        stoptimes191.takeFirst();
    }
    if(!stoptimes149.isEmpty()){
        stoptimes149.takeFirst();
    }
    Stoptimes_t stoptimes;
    for(int i = 0; (i < stoptimes191.size()) && (i < 5); i++){
        stoptimes.stoptime191[i] = stoptimes191.at(i);
    }
    for(int i = 0; (i < stoptimes149.size()) && (i < 5); i++){
        stoptimes.stoptime149[i] = stoptimes149.at(i);
    }
    return stoptimes;
}

Wifi_t StringParser::convert_wifi(const QString input){
    QStringList splitInput = input.split("&");
    Wifi_t result;
    result.SSID = splitInput.constFirst();
    result.RSSI = splitInput.constLast();
    return result;
}

Room_t StringParser::convert_room(const QString input){
    QStringList splitInput = input.split("&");
    Room_t result;
    result.light = splitInput.constFirst();
    result.temperature = splitInput.constLast();
    return result;
}

TimeInfo_t StringParser::convert_time_info(const QString input){
    QStringList splitInput = input.split("&");
    TimeInfo_t result;
    result.time = splitInput.constFirst();
    result.date = splitInput.at(1);
    result.day = splitInput.constLast();
    return result;
}
