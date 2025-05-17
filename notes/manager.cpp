#include "manager.h"
#include <QDir>
#include <QTextStream>

Manager::Manager() {
    QString folder_path = "data_of_user";

    QDir dir(folder_path);

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    list_of_user_files = GetListOfFileByCreationTime(folder_path);
    if (list_of_user_files.isEmpty()) {
        number_of_item = 0;
    } else {
        QString last_name = list_of_user_files[list_of_user_files.length() - 1];
        last_name.chop(8);
        number_of_item = last_name.toInt();
    }
}

void Manager::AddNoteToManager(QPushButton* note) {
    notes.push_back(note);
}

/*QStringList Manager::getListFilesInDirectory() {
    QDir dir("data_of_user");
    QStringList files;

    // Устанавливаем фильтр: только файлы (не папки)
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

    // Получаем список файлов
    files = dir.entryList();

    return files;
}*/

void Manager::OpenFileWithContent(QString name_of_file) {
    qDebug() << name_of_file;
}

void Manager::CreateFile(int number) {
    QDir dir("data_of_user");

    QString filePath = dir.filePath(QString::number(number) + "data.txt");

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "0";
        file.close();
    } else {
        qWarning() << "Не удалось создать файл:" << filePath;
    }
}

/*bool Manager::DoHaveFile(QString folder_path, QString name_of_file) {
    QDir dir_for_program(folder_path);

    QString maxNotePath = dir_for_program.filePath(name_of_file);
    QFile maxNoteFile(maxNotePath);
    return maxNoteFile.exists();
}*/

int Manager::ReadFirstLine(QString folder_path, QString name_of_file) {
    QDir dir_for_program(folder_path);
    QString maxNotePath = dir_for_program.filePath(folder_path);
    // Проверяем существование файла
    QFile maxNoteFile(maxNotePath);
    if (maxNoteFile.exists()) {
        if (maxNoteFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&maxNoteFile);
            QString firstLine = in.readLine();	// Читаем первую строку
            int value = firstLine.toInt();
            return value;
        }
    } else {
        return 0;
    }
}

QStringList Manager::GetListOfFileByCreationTime(const QString& directoryPath) {
    QDir directory(directoryPath);

    QFileInfoList fileInfoList =
        directory.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

    std::sort(fileInfoList.begin(), fileInfoList.end(),
              [](const QFileInfo& a, const QFileInfo& b) {
                  return a.birthTime() < b.birthTime();
              });

    QStringList fileNames;


    for (const QFileInfo& fileInfo : fileInfoList) {
        fileNames.append(fileInfo.fileName());
    }

    return fileNames;
}

void Manager::DeleteFile(const QString& folderPath, const QString& fileName) {
    QString filePath = folderPath + "/" + fileName;
    if (QFile::exists(filePath)) {
        QFile::remove(filePath);
    }
}


/*

void Manager::AddToDoListToManager(QPushButton* to_do_list) {
    to_do_lists.push_back(to_do_list);
}

void Manager::AddDRrawingToManager(QPushButton* draw) {
    drawing.push_back(draw);
}

void Manager::print() {
    qDebug() << "---------------";
    for (int i = 0; notes.length() != 0 && i < notes.length(); i++) {
        qDebug() << notes[i];
    }
    qDebug() << "---------------";
    for (int i = 0; to_do_lists.length() != 0 && i < to_do_lists.length();
         i++) {
        qDebug() << to_do_lists[i];
    }
    qDebug() << "---------------";
    for (int i = 0; drawing.length() != 0 && i < drawing.length(); i++) {
        qDebug() << drawing[i];
    }
    qDebug() << "---------------";
}*/
