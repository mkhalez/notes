#ifndef DIALOGFORTODOLIST_H
#define DIALOGFORTODOLIST_H

#include <filemanagerfornote.h>
#include <QPushButton>
#include <QWidget>
#include "manager.h"

namespace Ui {
class dialogfortodolist;
}

class dialogfortodolist : public QWidget {
    Q_OBJECT

   public:
    explicit dialogfortodolist(QPushButton* button, Manager* manager,
                               QString folder, QWidget* parent = nullptr);
    ~dialogfortodolist();


   private:
    Ui::dialogfortodolist* ui;
    Manager* manager;
    QMenu* dropdownMenu;
    QPushButton* button;
    QPushButton* correct_button;
    FileManagerForNote file_manager;
    void ConstructorCrossOutTask(int current_row);
    QString folder;

   private slots:
    void onItemClicked();
    void onItemSelectionChanged();
    void AddTask(QString text = "");
    void RemoveAll();
    void CorrectTask();
    void CrossOutTask();
    void RemoveTask();
};

#endif	// DIALOGFORTODOLIST_H
