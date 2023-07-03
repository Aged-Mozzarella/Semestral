#include "styleloader.h"

StyleLoader::StyleLoader() = default;
StyleLoader::~StyleLoader() = default;

StyleLoader StyleLoader::loader;

QString StyleLoader::load(const QString path){
    QFile file(path);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    return styleSheet;
}
