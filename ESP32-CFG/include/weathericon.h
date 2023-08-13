#ifndef WEATHERICON_H
#define WEATHERICON_H

#include <QString>

// Returns the filename of an appropriate weather icon depending on the weatherCode argument
QString getIconFileName(int weatherCode = 0);

#endif // WEATHERICON_H
