#include "connect.h"
#include "ui_connect.h"

#include "styleloader.h"
#include "fontweights.h"
#include "fontsizes.h"

#include "serialport.h"
#include "serialdefault.h"
#include "settings.h"

Connect::Connect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connect)
{
    ui->setupUi(this);

    styleText();
    styleButtons();

    connect(ui->portSelect, &QComboBox::currentIndexChanged, this, &Connect::updateCurrentPort);

    connect(ui->formRefreshButton, &QAbstractButton::clicked, this, [=](){
        getPortsInfo();
        populatePort();
        updateCurrentPort(0);
    });

    connect(ui->connectButton, &QAbstractButton::clicked, this, &Connect::connectToSerial);

    getPortsInfo();
    populateBaud();
    populatePort();
}


Connect::~Connect()
{
    delete ui;
}


void Connect::styleText(){
    QString fontStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss");

    QVector<QLabel *> labels = ui->ButtonArea->parent()->findChildren<QLabel *>(Qt::FindChildrenRecursively);
    for(int i = 0; i < labels.size(); i++){
        QLabel * current_label = labels.at(i);
        current_label->setStyleSheet(fontStyleString);
    }

    QFont s = QFont(semiBold_weight, font_size_regular);
    ui->baudLabel->setFont(s);
    ui->portLabel->setFont(s);
    ui->portInfoTitleLabel->setFont(s);
    s.setPointSize(font_size_heading);
    ui->titleLabel->setStyleSheet(StyleLoader::load(":/styles/connect/title.qss"));
    ui->titleLabel->setFont(s);
    QFont r = QFont(regular_weight, font_size_small);
    ui->subtitleLabel->setFont(r);

    const QFont l = QFont(light_weight, font_size_small);
    ui->infoPortValue->setFont(l);
    ui->infoLocationValue->setFont(l);
    ui->infoDescriptionValue->setFont(l);
    ui->infoManufacturerValue->setFont(l);
    ui->infoSerialValue->setFont(l);
    ui->infoVendorValue->setFont(l);
    ui->infoProductValue->setFont(l);
}

void Connect::styleButtons(){
    ui->connectButton->setStyleSheet(StyleLoader::load(":/styles/connect/connect_button.qss"));
    ui->formRefreshButton->setStyleSheet(StyleLoader::load(":/styles/connect/button.qss"));
    QFont s = QFont(semiBold_weight, font_size_regular);
    ui->connectButton->setFont(s);
}

void Connect::populateBaud(){
    ui->baudSelect->setInsertPolicy(QComboBox::NoInsert);
    ui->baudSelect->setFocusPolicy(Qt::NoFocus);
    ui->baudSelect->setStyleSheet(StyleLoader::load(":/styles/connect/select.qss"));

    ui->baudSelect->addItem(QStringLiteral("9600 Bd"), 9600);
    ui->baudSelect->addItem(QStringLiteral("19200 Bd"), 19200);
    ui->baudSelect->addItem(QStringLiteral("38400 Bd"), 38400);
    ui->baudSelect->addItem(QStringLiteral("115200 Bd"), 115200);
}

void Connect::populatePort(){
    ui->portSelect->setInsertPolicy(QComboBox::NoInsert);
    ui->portSelect->setFocusPolicy(Qt::NoFocus);
    ui->portSelect->setStyleSheet(StyleLoader::load(":/styles/connect/select.qss"));
    ui->portSelect->clear();
    if(!portInfo.size()){
        ui->portSelect->addItem("No devices detected!", -1);
        ui->PortInfoArea->hide();
    }else{
        int i = 0;
        for(const auto & currentPort : portInfo){
            ui->portSelect->addItem(QString(currentPort.constFirst()), i);
            i++;
        }
        if(!ui->PortInfoArea->isVisible()){
            ui->PortInfoArea->setVisible(true);
        }
    }
}

void Connect::updateCurrentPort(int idx){
    if(idx == -1){
        return;
    }

    const QString blank = QString("N/A");
    QStringList currentPort;

    if(ui->portSelect->itemData(idx) == -1){
        // Could not find any devices
        for(int i = 0; i < 7; i++){
            currentPort << "N/A";
        }
    }else{
        currentPort = portInfo.at(idx);
    }

    ui->infoPortValue->setText(currentPort.value(0, blank));
    ui->infoLocationValue->setText(currentPort.value(1, blank));
    ui->infoDescriptionValue->setText(currentPort.value(2, blank));
    ui->infoDescriptionValue->setWordWrap(true);
    ui->infoManufacturerValue->setText(currentPort.value(3, blank));
    ui->infoSerialValue->setText(currentPort.value(4, blank));
    ui->infoVendorValue->setText(currentPort.value(5, blank));
    ui->infoProductValue->setText(currentPort.value(6, blank));

}

void Connect::getPortsInfo(){
    const auto information = QSerialPortInfo::availablePorts();
    const QString blank = QString("");
    portInfo.clear();
    for(const QSerialPortInfo & info : information){
        QStringList currentPortInfo;
        const QString name = info.portName();
        const QString location = info.systemLocation();
        const QString description = info.description();
        const QString manufacturer = info.manufacturer();
        const QString serialNumber = info.serialNumber();
        const auto vendorId = info.vendorIdentifier();
        const auto productId = info.productIdentifier();
        currentPortInfo << name
                        << (!location.isEmpty() ? location : blank)
                        << (!description.isEmpty() ? description : blank)
                        << (!manufacturer.isEmpty() ? manufacturer : blank)
                        << (!serialNumber.isEmpty() ? serialNumber : blank)
                        << (vendorId ? QString::number(vendorId, 16) : blank)
                        << (productId ? QString::number(productId, 16) : blank);
        portInfo.push_back(currentPortInfo);
    }
}

void Connect::connectToSerial(){
    const int currentPortIdx = ui->portSelect->currentIndex();
    if(ui->portSelect->currentData() == -1){
        SerialPort::showAlert("Error!", "Invalid port name.");
        return;
    }
    QSerialPort::BaudRate currentBaudRate;
    const qint64 baud = ui->baudSelect->currentData().toInt();
    switch (baud) {
    case 9600:
        currentBaudRate = QSerialPort::Baud9600;
        break;
    case 19200:
        currentBaudRate = QSerialPort::Baud19200;
        break;
    case 38400:
        currentBaudRate = QSerialPort::Baud38400;
        break;
    case 115200:
        currentBaudRate = QSerialPort::Baud115200;
        break;
    default:
        currentBaudRate = SERIAL_BAUD_DEF;
    }
    QStringList currentPortInfo = portInfo.at(currentPortIdx);
    Settings s;
    s.name = currentPortInfo.constFirst();
    s.baudRate = currentBaudRate;
    s.dataBits = SERIAL_DATA_BITS_DEF;
    s.parity = SERIAL_PARITY_DEF;
    s.stopBits = SERIAL_STOP_BITS_DEF;
    s.flowControl = SERIAL_FLOW_CTRL_DEF;
    SerialPort::init();
    SerialPort::openSerialPort(s);
    const uint8_t correct[] = {0x6C, 0x69, 0x76, 0x65, 0x66, 0x65, 0x65, 0x64};
    const uint8_t wrong[] = {0x6B, 0x68, 0x75, 0x65, 0x65, 0x64, 0x64, 0x63};
    const char * cCorrect = reinterpret_cast<const char *>(correct);
    const char * cWrong = reinterpret_cast<const char *>(wrong);
    SerialPort::writeData(QByteArray(cCorrect));
    //SerialPort::writeData(QByteArray(cWrong));
}

