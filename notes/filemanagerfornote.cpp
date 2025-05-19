#include "filemanagerfornote.h"
#include <QFile>
#include <QTextStream>

FileManagerForNote::FileManagerForNote() {}

QString FileManagerForNote::ReadFile(const QString& folderPath,
                                     const QString& fileName) {
    QFile file(folderPath + "/" + fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }

    QTextStream in(&file);
    QString content;
    int lineCount = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (lineCount >= 2) {
            content += line + "\n";
        }
        lineCount++;
    }

    file.close();
    return content;
}

void FileManagerForNote::SaveFile(const QString& folderPath,
                                  const QString& fileName,
                                  const QString& newText) {
    QFile file(folderPath + "/" + fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&file);
    QString line1, line2;

    if (!stream.atEnd())
        line1 = stream.readLine();
    if (!stream.atEnd())
        line2 = stream.readLine();

    file.resize(0);
    stream << line1 << "\n";
    stream << line2 << "\n";
    stream << newText;

    file.close();
}

QString FileManagerForNote::NameForTitle(const QString& folderPath,
                                         const QString& fileName) {
    QFile file(folderPath + "/" + fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }

    QTextStream in(&file);
    QString content;
    int lineCount = 0;

    QString line;

    while (!in.atEnd()) {
        line = in.readLine();
        if (lineCount == 1) {
            return line;
        }
        lineCount++;
    }

    file.close();
    return content;
}

void FileManagerForNote::SaveTitle(const QString& folderPath,
                                   const QString& fileName,
                                   QString nameOfTitle) {
    QFile file(folderPath + "/" + fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&file);
    QString line1, line2;

    if (!stream.atEnd())
        line1 = stream.readLine();
    line2 = nameOfTitle;

    file.resize(0);
    stream << line1 << "\n";
    stream << line2 << "\n";

    file.close();
}
