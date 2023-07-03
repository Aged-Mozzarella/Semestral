#include "configure.h"
#include "./ui_configure.h"

#include "qregularexpression.h"
#include "styleloader.h"
#include "fontsizes.h"
#include "fontweights.h"
#include "recordsizes.h"
#include "serialport.h"
//#include "serialcommands.h"

Configure::Configure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configure)
{
    ui->setupUi(this);
    ui->noButton->hide();
    styleButtons();
    styleText();
    styleInputs();
    restrictInputs();

    connect(ui->uploadButton, &QAbstractButton::clicked, this, [=](){
        if(confirm){
            ui->noButton->hide();
            confirm = false;
            beginConfig();
        }else{
            if(checkInputs()){
                confirm = true;
                ui->noButton->show();
                parseInputs();
            }else{
                SerialPort::showAlert("Invalid", "Invalid input, only ASCII characters accepted.");
            }
        }
    });

    connect(ui->noButton, &QAbstractButton::clicked, this, [=](){
        confirm = false;
        ui->noButton->hide();
    });

}

Configure::~Configure()
{
    delete ui;
}

Credentials_t Configure::getCredentials(){
    return cred;
}

void Configure::styleText(){
    QString fontStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss");

    QVector<QLabel *> labels = ui->ButtonArea->parent()->findChildren<QLabel *>(Qt::FindChildrenRecursively);
    for(int i = 0; i < labels.size(); i++){
        QLabel * current_label = labels.at(i);
        current_label->setStyleSheet(fontStyleString);
    }

    QFont s = QFont(semiBold_weight, font_size_regular);
    s.setPointSize(font_size_heading);
    ui->titleLabel->setStyleSheet(StyleLoader::load(":/styles/connect/title.qss"));
    ui->titleLabel->setFont(s);
    QFont r = QFont(regular_weight, font_size_small);
    ui->subtitleLabel->setFont(r);
}

void Configure::styleButtons(){
    ui->uploadButton->setStyleSheet(StyleLoader::load(":/styles/connect/connect_button.qss"));
    QFont s = QFont(semiBold_weight, font_size_regular);
    ui->uploadButton->setFont(s);
}

void Configure::styleInputs(){
    QString fontStyleString = StyleLoader::load(":/styles/configure/input.qss");

    QVector<QLineEdit *> lines = ui->ButtonArea->parent()->findChildren<QLineEdit *>(Qt::FindChildrenRecursively);
    for(int i = 0; i < lines.size(); i++){
        QLineEdit * current_label = lines.at(i);
        current_label->setStyleSheet(fontStyleString);
    }
}

void Configure::restrictInputs(){
    const int scaler = 13;
    ui->inputWeather->setMaxLength(EEPROM_SIZE_URL);
    ui->inputWeather->setMaximumWidth(scaler * EEPROM_SIZE_URL);
    ui->inputBusA->setMaxLength(EEPROM_SIZE_URL);
    ui->inputBusA->setMaximumWidth(scaler * EEPROM_SIZE_URL);
    ui->inputBusB->setMaxLength(EEPROM_SIZE_URL);
    ui->inputBusB->setMaximumWidth(scaler * EEPROM_SIZE_URL);
    ui->inputSSID->setMaxLength(EEPROM_SIZE_SSID);
    ui->inputSSID->setMaximumWidth(scaler * EEPROM_SIZE_SSID);
    ui->inputPW->setMaxLength(EEPROM_SIZE_PASS);
    ui->inputPW->setMaximumWidth(scaler * EEPROM_SIZE_PASS);
    ui->inputIP->setMaxLength(EEPROM_SIZE_IP);
    ui->inputIP->setMaximumWidth(scaler * EEPROM_SIZE_IP);
}

bool Configure::checkInputs(){
    QVector<QLineEdit *> lines = ui->ButtonArea->parent()->findChildren<QLineEdit *>(Qt::FindChildrenRecursively);
    for(int i = 0; i < lines.size(); i++){
        QLineEdit * current_label = lines.at(i);
        if(current_label->text() == ""){
            return false;
        }
        bool containsNonASCII = current_label->text().contains(QRegularExpression(QStringLiteral("[^\\x{0000}-\\x{007F}]")));
        if(containsNonASCII){
            return false;
        }
    }
    return true;
}

void Configure::parseInputs(){
    QByteArray url_weather = ui->inputWeather->text().toLocal8Bit();
    QByteArray url_bus_a = ui->inputBusA->text().toLocal8Bit();
    QByteArray url_bus_b = ui->inputBusB->text().toLocal8Bit();
    QByteArray wifi_ssid = ui->inputSSID->text().toLocal8Bit();
    QByteArray wifi_pass = ui->inputPW->text().toLocal8Bit();
    QByteArray ip = ui->inputIP->text().toLocal8Bit();
    byteArrToChar(cred.url_weather, url_weather);
    byteArrToChar(cred.url_bus_a, url_bus_a);
    byteArrToChar(cred.url_bus_b, url_bus_b);
    byteArrToChar(cred.SSID, wifi_ssid);
    byteArrToChar(cred.password, wifi_pass);
    byteArrToChar(cred.socket_ip, ip);
}

void Configure::beginConfig(){
    const uint8_t CMD_CONFIGURE[] = {0x63, 0x6F, 0x6E, 0x66, 0x69, 0x67, 0x75, 0x72};
    const char * cCmd = reinterpret_cast<const char *>(CMD_CONFIGURE);
    SerialPort::writeData(QByteArray(cCmd));
    qDebug() << "\n"
             << cred.url_weather
             << "\n"
             << cred.url_bus_a
             << "\n"
             << cred.url_bus_b
             << "\n"
             << cred.SSID
             << "\n"
             << cred.password
             << "\n"
             << cred.socket_ip;
}

void Configure::byteArrToChar(char * arr, const QByteArray & input){
    for(int i = 0; i < input.size(); i++){
        arr[i] = input.at(i);
    }
    arr[input.size()] = '\0';
}

