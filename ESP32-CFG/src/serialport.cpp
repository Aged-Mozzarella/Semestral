#include "serialport.h"
#include "mainwindow.h"

#include "styleloader.h"
#include "iconpainter.h"
#include "colordefinitions.h"

#include <chrono>

static constexpr std::chrono::seconds writeTimeout = std::chrono::seconds{5};

SerialPort SerialPort::s_Instance;

SerialPort::~SerialPort(){
    if(serial != nullptr){
        delete serial;
    }
    if(timeout != nullptr){
        delete timeout;
    }
}

void SerialPort::IopenSerialPort(Settings & s){
    if(isInit){
        if(serial->isOpen()){
            IcloseSerialPort();
        }
        serial->setPortName(s.name);
        serial->setBaudRate(s.baudRate);
        serial->setDataBits(s.dataBits);
        serial->setParity(s.parity);
        serial->setStopBits(s.stopBits);
        serial->setFlowControl(s.flowControl);
        if (!serial->open(QIODevice::ReadWrite)) {
            // connect failed
            IshowAlert("Error!", serial->errorString());
        }else{
            emit connectionStarted();
        }
    }
}

void SerialPort::IcloseSerialPort(){
    if(isInit){
        if(serial->isOpen()){
            serial->close();
            queue.clear();
            bytesToWrite = 0;
            emit connectionEnded();
        }
    }
}

void SerialPort::IwriteData(const QByteArray & data){
    const qint64 written = serial->write(data);
    if(written == data.size()){
        bytesToWrite += written;
        timeout->start(writeTimeout);
    }else{
        IshowAlert("Something went wrong!", serial->errorString());
    }
}

QByteArray SerialPort::IreadData(){
    QByteArray result = queue.first();
    queue.pop_front();
    return result;
}

void SerialPort::Iinit(){
    if(!isInit){
        isInit = true;
        serial = new QSerialPort;
        timeout = new QTimer;
        timeout->setSingleShot(true);

        connect(serial, &QSerialPort::errorOccurred, this, &SerialPort::handleError);
        connect(serial, &QSerialPort::bytesWritten, this, &SerialPort::handleBytesWritten);
        connect(serial, &QSerialPort::readyRead, this, &SerialPort::handleIncomingData);
        connect(timeout, &QTimer::timeout, this, &SerialPort::handleWriteTimeout);
    }
}

void SerialPort::handleError(QSerialPort::SerialPortError error){
    if(error == QSerialPort::ResourceError){
        IshowAlert("Something went wrong!", serial->errorString());
        closeSerialPort();
    }
}

void SerialPort::handleBytesWritten(qint64 bytes){
    bytesToWrite -= bytes;
    if(!bytesToWrite){
        timeout->stop();
    }
}

void SerialPort::handleWriteTimeout(){
    const QString error = QString("Write operation timed out for port %1.\n"
                             "Error: %2").arg(serial->portName(),serial->errorString());
    IshowAlert("Something went wrong!", error);
}

void SerialPort::IshowAlert(const QString windowTitle, const QString errMsg, const QString fileName) const{
    QMessageBox msg = QMessageBox(QMessageBox::NoIcon, windowTitle, errMsg, QMessageBox::StandardButton::Ok, MainWindow::getMainWindowPtr(), Qt::Dialog | Qt::FramelessWindowHint);
    IconPainter p;
    msg.setIconPixmap(p.getIconFromFile(font_black_color, fileName).scaled(32,32, Qt::KeepAspectRatio));
    msg.setStyleSheet(StyleLoader::load(":/styles/connect/alert.qss"));
    msg.exec();
}

void SerialPort::handleIncomingData(){
    QByteArray arr = serial->readLine(bufferSizeLimit);
    queue.push_back(arr);
    emit receivedData();
}
