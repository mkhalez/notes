#include "manager.h"
#include <QDir>
#include <QTextStream>

Manager::Manager() {
    QString folderPath = "data_of_user";

    // Создаём объект QDir для работы с директорией
    QDir dir(folderPath);

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    folderPath = "data_of_program";
    QDir dir_for_program(folderPath);

    if (!dir_for_program.exists()) {
        dir_for_program.mkpath(".");
    }

    QString maxNotePath = dir_for_program.filePath("max_note.txt");
    // Проверяем существование файла
    QFile maxNoteFile(maxNotePath);
    if (maxNoteFile.exists()) {
        if (maxNoteFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&maxNoteFile);
            QString firstLine = in.readLine();	// Читаем первую строку
            int value = firstLine.toInt();
            number_of_item = value;
            maxNoteFile.close();
        }
    } else {
        number_of_item = 0;
    }
}

Manager::~Manager() {
    QDir dir("data_of_program");

    QString filePath = dir.filePath("max_note.txt");

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << QString::number(number_of_item);
        file.close();
    } else {
        qWarning() << "Не удалось создать файл:" << filePath;
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

bool Manager::DoHaveFile(QString folder_path, QString name_of_file) {
    QDir dir_for_program(folder_path);

    QString maxNotePath = dir_for_program.filePath(name_of_file);
    // Проверяем существование файла
    QFile maxNoteFile(maxNotePath);
    if (maxNoteFile.exists()) {
        return true;
    } else {
        return false;
    }
}

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
