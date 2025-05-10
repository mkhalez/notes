#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include "manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;
    QWidget* main_container;
    QVBoxLayout* main_layout;
    QScrollArea* scrollArea;
    QWidget* buttons_container;
    QVBoxLayout* buttons_layout;
    QHBoxLayout* bottom_layout;


    Manager manager;

    bool isPrivate = false;
    QPushButton* private_button;

    bool isAdditing = false;
    QPushButton* add_button;
    QMenu* dropdownMenu;


   private slots:
    void PrivateClick();
    void AddClick();
    void AddNoteHelper();
    /*void AddToDoListHelper();
    void AddDrawingHelper();*/
};
#endif	// MAINWINDOW_H
