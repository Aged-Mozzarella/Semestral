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

    // Applies CSS styling to all the text
    void styleText();
    // Applies CSS styling to all the buttons
    void styleButtons();

    // Populates the baud rate select box with info about the serial ports
    void populateBaud();
    // Populates the port select box with a list of all of the available serial ports
    void populatePort();

    // Fetches current info about the serial ports
    void getPortsInfo();
    // Updates the port info of the selected port
    void updateCurrentPort(int idx);

    // Callback function for when the connect button is pressed
    void connectToSerial();
};

#endif // CONNECT_H
