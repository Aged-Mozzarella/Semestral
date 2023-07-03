#ifndef COLORDEFINITIONS_H
#define COLORDEFINITIONS_H

#include <QColor>

//-------------------//
// Background colors //
//-------------------//

// Background color: #232B32
extern QColor background_color;
// Control bar color: #161A1F
extern QColor control_bar_color;
// Left menu color: #171F24
extern QColor left_menu_color;

//-------------//
// Font colors //
//-------------//

// Font default color: #98A1B7
extern QColor font_default_color;
// Font accent color: #D0D9F6
extern QColor font_accent_color;
// Font inverse default color: #000000
extern QColor font_black_color;

//---------------//
// Accent colors //
//---------------//

// Orange accent: #FC4C02
extern QColor accent_orange_color;
// Blue accent: #3B47D9
extern QColor accent_blue_color;
// Red accent: #E74C3C
extern QColor accent_red_color;

// Function for defining the global color variables
void defineColors();

#endif // COLORDEFINITIONS_H
