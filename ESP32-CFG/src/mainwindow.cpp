#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "iconpainter.h"
#include "styleloader.h"
#include "stringparser.h"

#include "colordefinitions.h"
#include "fontsizes.h"
#include "fontweights.h"

#include "serialport.h"
#include "serialcommands.h"

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pMainWindow = this;
    ui->setupUi(this);
    ui->disconnectButton->hide();
    this->setWindowTitle("ESP32-CFG");
    SerialPort::init();
    defineColors();
    importCustomFonts();
    connectButtons();

    QFont s = QFont(semiBold_weight, font_size_subsection_title);
    ui->disconnectButton->setFont(s);

    connect(&SerialPort::getInstance(), &SerialPort::connectionStarted, this, [=](){
        SerialPort::showAlert("Connected", "Connected to ESP32-DIS.", ":/icons/buttons/about.png");
        ui->disconnectButton->show();
        showPrevMenu();
    });

    connect(&SerialPort::getInstance(), &SerialPort::connectionEnded, this, [=](){
        SerialPort::showAlert("Disconnected", "Disconnected from ESP32-DIS.", ":/icons/buttons/about.png");
        ui->disconnectButton->hide();
        configInProgress = false;
        showPrevMenu();
    });

    connect(&SerialPort::getInstance(), &SerialPort::receivedData, this, &MainWindow::handleIncomingSerial);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete liveFeed;
    delete configure;
    delete about;
    delete serialConnect;
}

MainWindow * MainWindow::getMainWindowPtr(){
    return pMainWindow;
}

void MainWindow::importCustomFonts(){
    QFontDatabase::addApplicationFont(":/fonts/Montserrat-Light.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Montserrat-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Montserrat-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Montserrat-ExtraBold.ttf");

    //Set it as application default
    QFont defaultFont(regular_weight, font_size_regular);
    QApplication::setFont(defaultFont);
}

void MainWindow::initWindow(){
    initMenus();
    initIcon();
    initControlButtons();
    selectedMenu = 0;
    currentMenu = liveFeed;
    changeContent(ContentType::liveFeed);
}

void MainWindow::initControlButtons(){
    IconPainter painter;
    QVector<QToolButton *> buttons = {ui->controlMinimize, ui->controlClose};
    QVector<QString> fileNames = {"minimize.png", "close.png"};
    for(int i = 0; i < buttons.size(); i++){
        QToolButton * currentButton = buttons.at(i);
        QString currentFileName = QString(":/icons/buttons/").append(fileNames.at(i));
        QColor color = font_default_color;
        currentButton->setIcon(QIcon(painter.getIconFromFile(color, currentFileName)));
        currentButton->setIconSize(QSize(12,12));
    }
}

void MainWindow::initIcon(){
    QIcon icon = QIcon(":/icons/system/icon-1024h.png");
    QPixmap p = icon.pixmap(QSize(200, 200));
    ui->appTitle->setText("");
    ui->appTitle->setPixmap(p);
    ui->appSubtitle->setText("ESP32-DIS\nConfiguration Tool");
}

void MainWindow::initMenus(){
    liveFeed = new LiveFeed;
    configure = new Configure;
    about = new About;
    serialConnect = new Connect;
}

void MainWindow::connectButtons(){
    // Window manipulation buttons
    connect(ui->controlMinimize, &QAbstractButton::clicked, this, [=](){
        this->setWindowState(Qt::WindowMinimized);
    });
    connect(ui->controlClose, &QAbstractButton::clicked, this, [=](){
        if(!configInProgress){
            QApplication::quit();
        }
    });

    // Main content switching (side menu buttons)
    connect(ui->menuLiveFeed, &QAbstractButton::clicked, this, [=](){
        if(!configInProgress){
            selectedMenu = 0;
            changeContent(ContentType::liveFeed);
        }
    });
    connect(ui->menuConfigure, &QAbstractButton::clicked, this, [=](){
        if(!configInProgress){
            selectedMenu = 1;
            changeContent(ContentType::Configure);
        }
    });
    connect(ui->menuAbout, &QAbstractButton::clicked, this, [=](){
        if(!configInProgress){
            selectedMenu = 2;
            changeContent(ContentType::About);
        }
    });

    // Disconnect button
    connect(ui->disconnectButton, &QAbstractButton::clicked, this, [=](){
        if(!configInProgress){
            if(SerialPort::isOpen()){
                SerialPort::closeSerialPort();
            }
        }
    });
}

void MainWindow::showPrevMenu(){
    ContentType type = ContentType::About;
    if(selectedMenu == 0){
        type = ContentType::liveFeed;
    }
    if(selectedMenu == 1){
        type = ContentType::Configure;
    }
    changeContent(type);
}

void MainWindow::changeContent(ContentType requestedContent){
    if(!configInProgress){
        QSizePolicy policy;
        policy.setHorizontalPolicy(QSizePolicy::Expanding);
        policy.setVerticalPolicy(QSizePolicy::Expanding);

        currentMenu->setVisible(false);
        ui->horizontalLayout_3->removeWidget(currentMenu);
        if(SerialPort::isOpen() && requestedContent != ContentType::About){
            if(requestedContent == ContentType::liveFeed){
                ui->horizontalLayout_3->addWidget(liveFeed);
                liveFeed->setSizePolicy(policy);
                currentMenu = liveFeed;
                sendModeCommand(CMD_LIVE_FEED, 0);
            }
            if(requestedContent == ContentType::Configure){
                ui->horizontalLayout_3->addWidget(configure);
                configure->setSizePolicy(policy);
                currentMenu = configure;
                sendModeCommand(CMD_STOP, 2);
            }
        }else if(!SerialPort::isOpen() && requestedContent != ContentType::About){
            serialConnect->setSizePolicy(policy);
            ui->horizontalLayout_3->addWidget(serialConnect);
            currentMenu = serialConnect;
        }else{
            // All menus that do not require a connected SerialPort to function
            if(requestedContent == ContentType::About){
                ui->horizontalLayout_3->addWidget(about);
                about->setSizePolicy(policy);
                currentMenu = about;
            }
        }
        currentMenu->setVisible(true);

        // Focus the appropriate button
        focusButton();
    }
}

void MainWindow::focusButton(){
    // Load appropriate styles from the resource folder
    QString defStyleString = StyleLoader::load(":/styles/left_menu/left_menu_default.qss");
    QString focusedStyleString = StyleLoader::load(":/styles/left_menu/left_menu_focused.qss");

    IconPainter painter;
    QVector<QToolButton *> buttons = {ui->menuLiveFeed, ui->menuConfigure, ui->menuAbout, ui->disconnectButton};
    QVector<QString> fileNames = {"live_feed.png", "configure.png", "about.png", "disconnect.png"};
    for(int i = 0; i < buttons.size(); i++){
        QToolButton * currentButton = buttons.at(i);
        QString currentFileName = QString(":/icons/buttons/").append(fileNames.at(i));
        QColor color;
        if(selectedMenu == i){
            color = font_black_color;
            currentButton->setStyleSheet(focusedStyleString);

        }else{
            color = font_default_color;
            currentButton->setStyleSheet(defStyleString);
        }
        QFont f = QFont(semiBold_weight, font_size_heading);
        currentButton->setFont(f);
        currentButton->setIcon(QIcon(painter.getIconFromFile(color, currentFileName)));
        currentButton->setIconSize(QSize(32,32));
    }
}

void MainWindow::mousePressEvent(QMouseEvent * e){
    oldPos = e->globalPosition();
}

void MainWindow::mouseMoveEvent(QMouseEvent * e){
    if(ui->ControlBar->underMouse() && !ui->controlClose->underMouse() && !ui->controlMinimize->underMouse()){
        const QPointF delta = e->globalPosition() - oldPos;
        move(x() + delta.x(), y() + delta.y());
        oldPos = e->globalPosition();
    }
}

void MainWindow::handleIncomingSerial(){
    QString raw_data = QString(SerialPort::readData());
    qDebug() << "\n" << raw_data << "\n";
    if(raw_data.left(3) == "%%%"){
        QStringList entries = StringParser::parse_live_feed(raw_data.mid(3));
        for(const QString & data : entries){
            const uint8_t headerSize = 3;
            if(data.size() >= headerSize && data.left(1) == "%"){
                QString cmd = data.left(headerSize);
                QString payload = data.mid(headerSize);
                // Weather info
                if(cmd == "%0%"){
                    Weather_t temp = StringParser::convert_weather(payload);
                    liveFeed->updateDailyWeather(temp);
                    liveFeed->updateWeeklyWeather(temp);
                }
                // Stoptimes info
                if(cmd == "%1%"){
                    liveFeed->updateStoptimes(StringParser::convert_stoptimes(payload));
                }
                // Wifi info
                if(cmd == "%2%"){
                    liveFeed->updateWiFi(StringParser::convert_wifi(payload));
                }
                // Room info
                if(cmd == "%3%"){
                    liveFeed->updateRoom(StringParser::convert_room(payload));
                }
                // Time info
                if(cmd == "%4%"){
                    liveFeed->updateTime(StringParser::convert_time_info(payload));
                }
            }
        }
    }
    if(raw_data.left(1) == "*" && raw_data.size() == 3){
        if(raw_data == CONFIG_BEGIN){
            configInProgress = true;
            Credentials_t cred = configure->getCredentials();
            QString data = QString("%1%2&%3&%4&%5&%6&%7\0").arg(CONFIG_HEADER, cred.url_weather, cred.url_bus_a, cred.url_bus_b, cred.password, cred.SSID, cred.socket_ip);
            qDebug() << "QD: " << data;
            SerialPort::writeData(data.toUtf8());
        }
        if(raw_data == CONFIG_RECEIVED){
            qDebug() << "QD: Configuration received\n";
            sendModeCommand(CMD_SAVE, 1);
        }
        if(raw_data == CONFIG_SAVED){
            SerialPort::showAlert("Saved", "Successuflly updated the configuration.", ":/icons/buttons/about.png");
            qDebug() << "QD: Configuration saved\n";
            configInProgress = false;
        }
        if(raw_data == CONFIG_ILLEGAL){
            SerialPort::showAlert("Illegal", "Illegal save configuration request.");
            configInProgress = false;
        }
        if(raw_data == CONFIG_BAD_HEADER){
            SerialPort::showAlert("Bad Header", "Bad header.");
            configInProgress = false;
        }
        if(raw_data == CONFIG_BAD_CONTENT){
            SerialPort::showAlert("Bad Content", "Bad content.");
            configInProgress = false;
        }
        if(raw_data == CONFIG_TIMEOUT){
            SerialPort::showAlert("Timeout", "Save confirmation timed out.");
            configInProgress = false;
        }
    }
}

void MainWindow::sendModeCommand(const uint8_t * cmd, const int cmdIdx){
    static int currCmd = -1;
    // This should prevent sending multiples of the same command
    if(currCmd != cmdIdx){
        const char * cCmd = reinterpret_cast<const char *>(cmd);
        SerialPort::writeData(QByteArray(cCmd));
        currCmd = cmdIdx;
    }
}

