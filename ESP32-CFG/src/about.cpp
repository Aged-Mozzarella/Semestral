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
}
