#ifndef MANAGER_H
#define MANAGER_H
#include <QPushButton>
#include <QVector>

class Manager {
   public:
    Manager();
    void AddNoteToManager(QPushButton* note);
    size_t number_of_item = 0;
    QStringList getFilesInDirectory(const QString& folderPath);
    void OpenFileWithContent(QString name_of_file);
    /*void AddToDoListToManager(QPushButton* to_do_list);
    void AddDRrawingToManager(QPushButton* draw);*/
    /*void print();*/

   private:
    QVector<QPushButton*> notes;
    QStringList all_files;
    /*QVector<QPushButton*> to_do_lists;
    QVector<QPushButton*> drawing;*/
};

#endif	// MANAGER_H
