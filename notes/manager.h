#ifndef MANAGER_H
#define MANAGER_H
#include <QPushButton>
#include <QVector>
#include <unordered_map>

class Manager {
   public:
    Manager();

    size_t number_of_item = 0;
    QStringList list_of_user_files;
    //dialogfornote* dialog;


    void AddNoteToManager(QPushButton* note, QString name_of_file);
    void DeleteFile(const QString& folderPath, const QString& fileName);
    //void OpenFileWithContent(QPushButton* button);
    void FillIsOpenButton(QPushButton* button, bool value);
    void CreateFile(int number);
    bool DoHaveFile(QString folder_path, QString name_of_file);
    int ReadFirstLine(QString folder_path, QString name_of_file);
    QStringList GetListOfFileByCreationTime(const QString& directoryPath);
    QStringList getListFilesInDirectory();
    QString GetNameOfFileThanksPtr(QPushButton* ptr);
    std::unordered_map<QPushButton*, bool> is_open_button;

    /*void AddToDoListToManager(QPushButton* to_do_list);
    void AddDRrawingToManager(QPushButton* draw);*/
    /*void print();*/

   private:
    //QVector<QPushButton*> notes;
    std::unordered_map<QPushButton*, QString> notes;

    QStringList all_files;
    void RefreshFileList();
    /*QVector<QPushButton*> to_do_lists;
    QVector<QPushButton*> drawing;*/
};

#endif	// MANAGER_H
