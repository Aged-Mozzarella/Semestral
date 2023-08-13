#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QMessageBox>

#include "settings.h"

// Should behave like a singleton
class SerialPort : public QObject{

    Q_OBJECT

public:
    // Disabling any form of data copying
    SerialPort(const SerialPort &) = delete;
    SerialPort & operator=(const SerialPort &) = delete;

    // Implementing the destructor to free the allocated resources within the class
    ~SerialPort();

    // Returns reference to the SerialPort singleton
    static SerialPort & getInstance(){
        return s_Instance;
    }

    // Initializes the SerialPort signal handles
    static void init(){ getInstance().Iinit(); }

    // Attempts to open the serial port if not opened already
    static void openSerialPort(Settings & s){ getInstance().IopenSerialPort(s); }
    // Attempts to close the serial port if not closed already
    static void closeSerialPort(){ getInstance().IcloseSerialPort(); }
    // Writes data to the serial port if opened
    static void writeData(const QByteArray & data){ getInstance().IwriteData(data); }
    // Reads buffered data from the serial port if opened
    static QByteArray readData(){ return getInstance().IreadData(); }

    // Displays an alert window
    static void showAlert(const QString windowTitle, const QString errMsg, const QString fileName = ":/icons/buttons/close.png"){getInstance().IshowAlert(windowTitle, errMsg, fileName);}

    // Returns the state of the serial port
    static bool isOpen(){return getInstance().serial->isOpen();}

signals:
    // Emitted when the connection is established
    void connectionStarted();
    // Emitted when the connection is terminated
    void connectionEnded();
    // Emitted when no more data is being received by the serial port in a set time window - buffering
    void receivedData();

private slots:
    // Handles error thrown by the serial port
    void handleError(QSerialPort::SerialPortError error);
    // Checks if all bytes have been written before timeout
    void handleBytesWritten(qint64 bytes);
    // Handles if not all bytes have been written
    void handleWriteTimeout();
    // Handles incoming data read into a buffer
    void handleIncomingData();

private:
    static SerialPort s_Instance;

    SerialPort() = default;

    // Private variables

    // Keeps track of the initialization
    bool isInit = false;
    // Actual serial port object
    QSerialPort * serial = nullptr;
    // Write timeout timer
    QTimer * timeout = nullptr;
    // For keeping track of successfully written bytes to serial
    qint64 bytesToWrite = 0;
    // FIFO queue for buffering data
    QVector<QByteArray> queue;

    // Used to limit the size of the buffer [bytes]
    const int bufferSizeLimit= 1024;

    // Private implementations
    // Attempts to open a serial port with the settings passed as argument
    void IopenSerialPort(Settings & s);
    // Closes the serial port
    void IcloseSerialPort();
    // Writes the data passed as argument to serial port
    void IwriteData(const QByteArray &data);
    // Reads data from serial port
    QByteArray IreadData();

    // Initializes the internal workings
    void Iinit();

    // Displays a styled QMessageBox alert
    void IshowAlert(const QString windowTitle, const QString errMsg, const QString fileName = ":/icons/buttons/close.png") const;
};

#endif // SERIALPORT_H
