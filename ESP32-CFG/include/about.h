#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

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

    void styleText();

};

#endif // ABOUT_H
