#ifndef MANAGER_H
#define MANAGER_H
#include <QPushButton>
#include <QVector>
#include <unordered_map>

class Manager {
   public:
    Manager(QString work_folder, bool version = true);

    QString work_folder;
    size_t number_of_item = 0;
    QStringList list_of_user_files;
    bool isOpenPrivate;
    //dialogfornote* dialog;


    void AddNoteToManager(QPushButton* note, QString name_of_file);
    void AddToDoListToManager(QPushButton* to_do_list, QString name_of_file);
    void DeleteFile(const QString& folderPath, const QString& fileName);
    virtual QString NameForTitle(const QString& folderPath,
                                 const QString& fileName);
    //void OpenFileWithContent(QPushButton* button);
    void FillIsOpenButton(QPushButton* button, QString folder, bool value);
    virtual void CreateFile(int number, int type, QString folder);
    bool DoHaveFile(QString folder_path, QString name_of_file);
    int ReadFirstLine(QString folder_path, QString name_of_file);
    QStringList GetListOfFileByCreationTime(const QString& directoryPath);
    QStringList getListFilesInDirectory();
    QString GetNameOfFileThanksPtr(QPushButton* ptr);


    std::unordered_map<QPushButton*, bool> is_open_button;
    std::unordered_map<QPushButton*, QString> notes;
    std::unordered_map<QPushButton*, QString> to_do_list;


    /*void AddToDoListToManager(QPushButton* to_do_list);
    void AddDRrawingToManager(QPushButton* draw);*/
    /*void print();*/
   protected:
    virtual void Initialization();

   private:
    //QVector<QPushButton*> notes;


    QStringList all_files;
    void RefreshFileList();
    /*QVector<QPushButton*> to_do_lists;
    QVector<QPushButton*> drawing;*/
};

#endif	// MANAGER_H
