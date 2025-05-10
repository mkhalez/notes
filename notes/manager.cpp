#include "manager.h"
#include <QDir>

Manager::Manager() {
    QString folderPath = "data_of_user";

    // Создаём объект QDir для работы с директорией
    QDir dir(folderPath);

    if (!dir.exists()) {
        dir.mkpath(".");
    }
}

void Manager::AddNoteToManager(QPushButton* note) {
    notes.push_back(note);
}

QStringList Manager::getFilesInDirectory(const QString& folderPath) {
    QDir dir(folderPath);
    QStringList files;

    // Устанавливаем фильтр: только файлы (не папки)
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

    // Получаем список файлов
    files = dir.entryList();

    return files;
}

void Manager::OpenFileWithContent(QString name_of_file) {
    qDebug() << name_of_file;
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
