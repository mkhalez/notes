#ifndef DIALOGFORTODOLIST_H
#define DIALOGFORTODOLIST_H

#include <filemanagerfornote.h>
#include <QPushButton>
#include <QWidget>
#include "crypto.h"
#include "manager.h"
#include "privatefilemanagerfornote.h"

namespace Ui {
class dialogfortodolist;
}

class dialogfortodolist : public QWidget {
    Q_OBJECT

   public:
    explicit dialogfortodolist(QPushButton* button, Manager* manager,
                               QString folder, Crypto* crypto,
                               QWidget* parent = nullptr);
    ~dialogfortodolist();


   private:
    Ui::dialogfortodolist* ui;
    Manager* manager;
    QMenu* dropdownMenu;
    QPushButton* button;
    QPushButton* correct_button;
    FileManagerForNote* file_manager;
    PrivateFileManagerForNote* private_file_manager;
    void ConstructorCrossOutTask(int current_row);
    QString folder;

   private slots:
    void AddTask(QString text = "");
    void RemoveAll();
    void CorrectTask();
    void CrossOutTask();
    void RemoveTask();
};

#endif	// DIALOGFORTODOLIST_H
