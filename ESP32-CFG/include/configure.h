#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QWidget>
#include <QRegularExpression>

#include "structs.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Configure; }
QT_END_NAMESPACE


class Configure : public QWidget
{
    Q_OBJECT

public:
    explicit Configure(QWidget *parent = nullptr);
    ~Configure();

    Credentials_t getCredentials();

private:
    Ui::Configure *ui;
    Credentials_t cred;
    bool confirm = false;

    // Applies CSS styling to all the text
    void styleText();
    // Applies CSS styling to all the buttons
    void styleButtons();
    // Applies CSS styling to all the input areas
    void styleInputs();

    // Sets appropriate sizes for the input areas
    void restrictInputs();
    // Checks if the input areas only contain ASCII characters
    bool checkInputs();
    // Parses the contents of the input areas into the member variables
    void parseInputs();

    // Sends the begin config command to serial
    void beginConfig();

    // Assumes arr is big enough to accept the contents of the input array
    void byteArrToChar(char * arr, const QByteArray & input);
};

#endif // CONFIGURE_H
