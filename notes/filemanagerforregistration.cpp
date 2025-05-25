#include "filemanagerforregistration.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

FileManagerForRegistration::FileManagerForRegistration() {}

void FileManagerForRegistration::CreateFile(QString folder,
                                            QString name_of_file) {
    QDir dir(folder);
    QString filePath = dir.filePath(name_of_file);
    QFile file(filePath);

    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "-1\n";
            file.close();
        }
    }
}

int FileManagerForRegistration::ReadFirstLine(QString folder_path,
                                              QString name_of_file) {
    QDir dir_for_program(folder_path);
    QString filePath = dir_for_program.filePath(name_of_file);

    QFile file(filePath);
    if (!file.exists()) {
        return -1;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }

    QTextStream in(&file);
    QString firstLine = in.readLine();
    file.close();

    bool ok;
    int value = firstLine.toInt(&ok);
    return ok ? value : -1;
}

void FileManagerForRegistration::WriteStation(QString folder,
                                              QString name_of_file,
                                              QString password) {
    QDir dir(folder);
    QString filePath = dir.filePath(name_of_file);
    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "0\n";
        if (!password.isEmpty())
            out << password + "\n";

        file.close();
    }
}

QString FileManagerForRegistration::ReadSecondLine(QString folder,
                                                   QString name_of_file) {
    QDir dir_for_program(folder);
    QString filePath = dir_for_program.filePath(name_of_file);

    QFile file(filePath);
    if (!file.exists()) {
        return "";
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }

    QTextStream in(&file);
    in.readLine();
    QString secondLine = in.readLine();
    file.close();

    return secondLine;
}
