#include <QColor>

QColor background_color;
QColor control_bar_color;
QColor left_menu_color;
QColor font_default_color;
QColor font_accent_color;
QColor font_black_color;
QColor accent_orange_color;
QColor accent_blue_color;
QColor accent_red_color;

void defineColors(){
    background_color = QColor::fromRgb(35, 43, 50);
    control_bar_color = QColor::fromRgb(22, 26, 31);
    left_menu_color = QColor::fromRgb(23, 31, 36);
    font_default_color = QColor::fromRgb(152, 161, 183);
    font_accent_color = QColor::fromRgb(208, 217, 246);
    font_black_color = QColor::fromRgb(0,0,0);
    accent_orange_color = QColor::fromRgb(252, 76, 2);
    accent_blue_color = QColor::fromRgb(59, 71, 217);
    accent_red_color = QColor::fromRgb(231, 76, 60);
}
