#include "iconpainter.h"

IconPainter::IconPainter()
{

}


QPixmap IconPainter::getIconFromFile(const QColor color, const QString filename){
    QImage img = QImage(filename);
    return getColoredIcon(color, img);
}


QPixmap IconPainter::getColoredIcon(const QColor color, const QImage & alpha){
    QPixmap result(alpha.size());
    result.fill(Qt::transparent);
    QPainter p;
    p.begin(&result);
    p.setRenderHint(QPainter::RenderHint::Antialiasing);
    p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    QRect r = result.rect();
    p.fillRect(r, QBrush(color, Qt::SolidPattern));
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.drawImage(0, 0, alpha);
    p.end();
    return result;
}

