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

    // Applies the CSS styling to all the text
    void styleText();
    void styleButtons();
    void styleInputs();

    void restrictInputs();
    bool checkInputs();
    void parseInputs();

    void beginConfig();

    // Assumes arr is big enough to accept the contents of input
    void byteArrToChar(char * arr, const QByteArray & input);
};

#endif // CONFIGURE_H
