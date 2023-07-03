#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QtSerialPort/QSerialPort>

struct Settings {
    QString name;
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QSerialPort::FlowControl flowControl;
};

#endif // SETTINGS_H
