#include "privatefilemanagerfornote.h"
#include <QDebug>
#include <QFile>

PrivateFileManagerForNote::PrivateFileManagerForNote(Crypto* crypto) {
    this->crypto = crypto;
}

QString PrivateFileManagerForNote::ReadFile(const QString& folderPath,
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
    return crypto->decryptAES(content);
}

void PrivateFileManagerForNote::SaveFile(const QString& folderPath,
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
    stream << crypto->encryptAES(newText);

    file.close();
}

void PrivateFileManagerForNote::SaveTitle(const QString& folderPath,
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
    line2 = crypto->encryptAES(nameOfTitle);

    file.resize(0);
    stream << line1 << "\n";
    stream << line2 << "\n";

    file.close();
}

void PrivateFileManagerForNote::SaveFileForToDoList(const QString& folderPath,
                                                    const QString& fileName,
                                                    const QStringList& lines) {
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


    for (const QString& line : lines) {
        stream << crypto->encryptAES(line) << "\n";
    }

    file.close();
}

QStringList PrivateFileManagerForNote::ReadFileForToDoList(
    const QString& folderPath, const QString& fileName) {
    QStringList lines;
    QFile file(folderPath + "/" + fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return lines;  // Возвращаем пустой список, если файл не открылся
    }

    QTextStream in(&file);
    int lineCount = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (lineCount >= 2) {  // Пропускаем первые две строки
            lines.append(crypto->decryptAES(line));
        }
        lineCount++;
    }

    file.close();
    return lines;
}
