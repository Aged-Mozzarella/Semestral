#ifndef ICONPAINTER_H
#define ICONPAINTER_H

#include <QWidget>
#include <QPainter>

class IconPainter
{
public:
    IconPainter();

    QPixmap getIconFromFile(const QColor color, const QString filename);
private:
    // Overlays the alpha with the colour
    void overlayIcon(QPainter & p, const QColor color, const QImage & alpha);
    // Returns an icon in a specified color
    QPixmap getColoredIcon(const QColor color, const QImage & alpha);
};

#endif // ICONPAINTER_H
