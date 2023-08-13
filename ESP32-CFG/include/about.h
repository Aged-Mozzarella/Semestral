#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class About; }
QT_END_NAMESPACE

class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;

    // Styles the text inside QLabels
    void styleText();
    // Sets up the legalLinkLabel QLabel as a hyperlink
    void addHrefs();

};

#endif // ABOUT_H
