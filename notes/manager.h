#ifndef MANAGER_H
#define MANAGER_H
#include <QPushButton>
#include <QVector>

class Manager {
   public:
    Manager();

    size_t number_of_item = 0;
    QStringList list_of_user_files;

    void AddNoteToManager(QPushButton* note);
    QStringList getListFilesInDirectory();
    void OpenFileWithContent(QString name_of_file);
    void CreateFile(int number);
    bool DoHaveFile(QString folder_path, QString name_of_file);
    int ReadFirstLine(QString folder_path, QString name_of_file);
    QStringList GetListOfFileByCreationTime(const QString& directoryPath);
    void DeleteFile(const QString& folderPath, const QString& fileName);
    /*void AddToDoListToManager(QPushButton* to_do_list);
    void AddDRrawingToManager(QPushButton* draw);*/
    /*void print();*/

   private:
    QVector<QPushButton*> notes;
    QStringList all_files;
    void RefreshFileList();
    /*QVector<QPushButton*> to_do_lists;
    QVector<QPushButton*> drawing;*/
};

#endif	// MANAGER_H
