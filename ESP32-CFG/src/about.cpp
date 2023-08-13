#include "about.h"
#include "./ui_about.h"

#include "styleloader.h"
#include "fontsizes.h"
#include "fontweights.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    styleText();
    addHrefs();
}

About::~About()
{
    delete ui;
}

void About::styleText(){
    QString fontStyleString = StyleLoader::load(":/styles/live_feed/live_feed_qlabel.qss");
    QVector<QLabel *> labels = ui->contentFrame->parent()->findChildren<QLabel *>(Qt::FindChildrenRecursively);
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
    ui->legalLabel->setFont(r);
    ui->legalLink->setFont(r);
}

void About::addHrefs(){
    QString text = QString("<a href=\"whatever\" style=\"%1\">here [13 hyperlinks].</a>").arg(StyleLoader::load(":/styles/about/link.qss"));
    qDebug() << text;
    ui->legalLink->setText(text);
    ui->legalLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(ui->legalLink, &QLabel::linkActivated, this, [=](){
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/cloudy_557715"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/fog_514262"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/rain_557762"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/snow_557738"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/storm_557714"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/sun_606795"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/info-button_64494"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/arrow-down-sign-to-navigate_32195"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/close_1828778"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/settings_807313"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/unplugged_9506538"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/graph_2567943"));
        QDesktopServices::openUrl(QUrl("https://www.flaticon.com/free-icon/minus_3482470"));
    });
}
