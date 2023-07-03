#ifndef STYLELOADER_H
#define STYLELOADER_H

#include <QString>
#include <QFile>

class StyleLoader
{
public:
    static StyleLoader & getInstance(){
        return loader;
    }
    static QString load(const QString path);

private:
    static StyleLoader loader;

    StyleLoader();
    ~StyleLoader();
    StyleLoader(const StyleLoader &) = delete;
    StyleLoader & operator=(const StyleLoader&) = delete;
};

#endif // STYLELOADER_H
