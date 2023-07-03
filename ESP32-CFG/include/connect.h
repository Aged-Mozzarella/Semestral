#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>
#include <QSerialPortInfo>
#include <QSerialPort>

#include "styleloader.h"

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;
    QVector<QStringList> portInfo;

    // Applies the CSS styling to all the text
    void styleText();
    void styleButtons();

    // Populates the select boxes with info about the serial ports
    void populateBaud();
    void populatePort();

    // Fetches current info about the serial ports
    void getPortsInfo();
    // Updates the port info of the selected port
    void updateCurrentPort(int idx);

    // Callback function for when the connect button is pressed
    void connectToSerial();
};

#endif // CONNECT_H
