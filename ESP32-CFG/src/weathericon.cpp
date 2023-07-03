#include "weathericon.h"

QString getIconFileName(int weatherCode){
    // Sunny as default
    QString fileName = "sun.png";
    // Mainly Clear
    if(weatherCode == 1 || weatherCode == 2){
        fileName = "cloudy.png";
    }
    // Overcast
    if(weatherCode == 3){
        fileName = "overcast.png";
    }
    // Fog
    if(weatherCode == 45 || weatherCode == 48){
        fileName = "fog.png";
    }
    // Slight Rain
    if(weatherCode == 51 || weatherCode == 56 || weatherCode == 61 || weatherCode == 66 || weatherCode == 80){
        fileName = "light_rain.png";
    }
    // Rain
    if(weatherCode == 53 || weatherCode == 55 || weatherCode == 57 || weatherCode == 63 || weatherCode == 65 || weatherCode == 67 || weatherCode == 81 || weatherCode == 82){
        fileName = "rain.png";
    }
    // Snow
    if(weatherCode == 71 || weatherCode == 73 || weatherCode == 75 || weatherCode == 77 || weatherCode == 85 || weatherCode == 86){
        fileName = "snow.png";
    }
    // Thunderstorm
    if(weatherCode == 95 || weatherCode == 96 || weatherCode == 99){
        fileName = "storm.png";
    }
    return QString(":/icons/weather/%1").arg(fileName);
}
