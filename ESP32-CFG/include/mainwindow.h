#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtGui>

#include "livefeed.h"
#include "configure.h"
#include "about.h"
#include "connect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class ContentType{
    liveFeed,
    Configure,
    About,
    Connect
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Initialize the window
    void initWindow();

    static MainWindow * getMainWindowPtr();

private:
    static MainWindow * pMainWindow;

    Ui::MainWindow *ui;
    QPointF oldPos;
    int selectedMenu;
    QWidget * currentMenu;
    LiveFeed * liveFeed;
    Configure * configure;
    About * about;
    Connect  * serialConnect;
    bool configInProgress = false;

    // Signal & Slot connection for the menu buttons
    void connectButtons();
    // Creates all of the icons using an alpha-map overlay
    void createIcons();
    // Imports all custom fonts
    void importCustomFonts();

    // Switches the CurrentMenu widget to whatever has been selected through the side menu buttons
    void changeContent(ContentType requestedContent);
    // Fancy graphics for focusing the button (showing the current menu selected)
    void focusButton();
    // Shows the previous selected menu
    void showPrevMenu();

    // Initializes the icons for the control buttons
    void initControlButtons();
    // Initializes the menus
    void initMenus();
    // Initializes the app icon
    void initIcon();

    // Sends data mode command to the unit
    void sendModeCommand(const uint8_t * cmd, const int cmdIdx);
    // Decides what to do with incoming serial data
    void handleIncomingSerial();

protected:
    // Mouse clicked event handle
    void mousePressEvent(QMouseEvent * e);
    // Mouse moved event handle
    void mouseMoveEvent(QMouseEvent * e);
};
#endif // MAINWINDOW_H
