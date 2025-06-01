#include "manager.h"
#include <QDir>
#include <QTextStream>
#include "crypto.h"


Manager::Manager(QString work_folder, bool version) {
    this->work_folder = work_folder;
    if (version)
        Initialization();
}

void Manager::Initialization() {

    QDir dir(work_folder);

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    SortedByData();
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

void Manager::Update(bool sorted_by_data, bool is_private, QString key) {
    if (sorted_by_data) {
        SortedByData();
        return;
    }

    QDir directory(work_folder);

    QFileInfoList fileInfoList =
        directory.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

    QStringList fileNames;


    for (const QFileInfo& fileInfo : fileInfoList) {
        fileNames.append(fileInfo.fileName());
    }

    list_of_user_files = fileNames;
    SortedByAlphabet(work_folder, is_private, key);
}

void Manager::SortedByAlphabet(QString folder, bool is_private, QString key) {
    Crypto crypto;
    if (is_private)
        crypto.SetKey(key);

    std::sort(
        list_of_user_files.begin(), list_of_user_files.end(),
        [this, folder, is_private, &crypto](QString a, QString b) {
            QString first_title, second_title;
            if (is_private) {
                first_title = crypto.decryptAES(NameForTitle(folder, a));
                second_title = crypto.decryptAES(NameForTitle(folder, b));
            } else {
                first_title = NameForTitle(folder, a);
                second_title = NameForTitle(folder, b);
            }

            if (first_title.isEmpty() && ReadFirstLine(folder, a) == 0) {
                first_title = "New Note";
            } else if (first_title.isEmpty() && ReadFirstLine(folder, a) == 1) {
                first_title = "New To-Do List";
            } else if (second_title.isEmpty() &&
                       ReadFirstLine(folder, b) == 0) {
                second_title = "New Note";
            } else if (second_title.isEmpty() &&
                       ReadFirstLine(folder, b) == 1) {
                second_title = "New To-Do List";
            }

            return first_title < second_title;
        });
}

void Manager::SortedByData() {

    list_of_user_files = GetListOfFileByCreationTime(work_folder);
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
