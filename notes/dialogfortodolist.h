#ifndef DIALOGFORTODOLIST_H
#define DIALOGFORTODOLIST_H

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
                               QWidget* parent = nullptr);
    ~dialogfortodolist();

   private:
    Ui::dialogfortodolist* ui;
    Manager* manager;
    QMenu* dropdownMenu;
    QPushButton* button;
    QPushButton* correct_button;

   private slots:
    void onItemClicked();
    void onItemSelectionChanged();
    void AddTask();
    void RemoveAll();
    void CorrectTask();
    void CrossOutTask();
    void RemoveTask();
};

#endif	// DIALOGFORTODOLIST_H
