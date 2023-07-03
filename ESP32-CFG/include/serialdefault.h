#ifndef SERIALDEFAULT_H
#define SERIALDEFAULT_H

#include <QSerialPort>

// Default serial parameters

// Baud rate
QSerialPort::BaudRate SERIAL_BAUD_DEF = QSerialPort::Baud115200;
// Data bits
QSerialPort::DataBits SERIAL_DATA_BITS_DEF = QSerialPort::Data8;
// Direction
QSerialPort::Direction SERIAL_DIR_DEF = QSerialPort::AllDirections;
// Flow control
QSerialPort::FlowControl SERIAL_FLOW_CTRL_DEF = QSerialPort::NoFlowControl;
// Parity
QSerialPort::Parity SERIAL_PARITY_DEF = QSerialPort::NoParity;
// Stop bits
QSerialPort::StopBits SERIAL_STOP_BITS_DEF = QSerialPort::OneStop;

#endif // SERIALDEFAULT_H
