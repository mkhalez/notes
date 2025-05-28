#include "manager.h"
#include <QDir>
#include <QTextStream>


Manager::Manager(bool version) {
    if (version)
        Initialization();
}

void Manager::Initialization() {
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

void Manager::AddNoteToManager(QPushButton* note, QString name_of_file) {
    notes.insert(std::make_pair(note, name_of_file));
}

void Manager::AddToDoListToManager(QPushButton* to_do_list,
                                   QString name_of_file) {
    this->to_do_list.insert(std::make_pair(to_do_list, name_of_file));
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

/*void Manager::OpenFileWithContent(QPushButton* button) {
    if (is_open_button[button]) {
        return;
    }

    dialog = new dialogfornote();
    is_open_button[button] = true;
    dialog->show();
}*/

void Manager::FillIsOpenButton(QPushButton* button, QString folder,
                               bool value = false) {
    QDir dir(folder);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    QStringList files = dir.entryList();
    is_open_button.insert(std::make_pair(button, value));
}

void Manager::CreateFile(int number, int type, QString folder) {
    QDir dir(folder);

    QString filePath = dir.filePath(QString::number(number) + "data.txt");

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << QString::number(type);
        file.close();
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

QString Manager::GetNameOfFileThanksPtr(QPushButton* ptr) {
    auto it = notes.find(ptr);

    if (it != notes.end())
        return notes[ptr];

    return to_do_list[ptr];
}

void Manager::DeleteFile(const QString& folderPath, const QString& fileName) {
    QString filePath = folderPath + "/" + fileName;
    if (QFile::exists(filePath)) {
        QFile::remove(filePath);
    }
}

QString Manager::NameForTitle(const QString& folderPath,
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
