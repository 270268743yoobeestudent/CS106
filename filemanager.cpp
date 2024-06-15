#include "filemanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FileManager::FileManager(const QString &filePath)
    : filePath(filePath)
{
}

QStringList FileManager::readDefectNames()
{
    QStringList defectNames;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty() && line.startsWith("Defect Name: ")) {
                defectNames << line.mid(13); // Assuming "Defect Name: " is always present
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open defects file for reading:" << file.errorString();
    }
    return defectNames;
}

bool FileManager::updateDefect(const QString &oldDefectName, const QString &newDefectName)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Failed to open defects file for updating:" << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    QStringList lines;
    bool defectFound = false;

    // Read all lines and update the defect name if found
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (!line.isEmpty()) {
            if (line.startsWith("Defect Name: ") && line.endsWith(oldDefectName)) {
                lines << "Defect Name: " + newDefectName;
                defectFound = true;
            } else {
                lines << line;
            }
        }
    }

    file.resize(0); // Clear contents of the file
    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }

    file.close();
    qDebug() << "Defect name updated in file:" << oldDefectName << "->" << newDefectName;

    return defectFound;
}

bool FileManager::writeToFile(const QString &data)
{
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return false;
    }

    QTextStream out(&file);
    out << data << "\n";

    file.close();
    qDebug() << "Data written to file:" << data;

    return true;
}
