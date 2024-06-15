#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>
#include <QStringList>

class FileManager
{
public:
    explicit FileManager(const QString &filePath);

    QStringList readDefectNames();
    bool updateDefect(const QString &oldDefectName, const QString &newDefectName);
    bool writeToFile(const QString &data);

private:
    QString filePath;
};

#endif // FILEMANAGER_H
