#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <authentication.h>
#include <registration.h>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include "crypto.h"
#include "dialogfornote.h"
#include "dialogfortodolist.h"
#include "filemanagerforregistration.h"
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
    FileManagerForRegistration registration_file_manager;
    QWidget* main_container;
    QVBoxLayout* main_layout;
    QScrollArea* scrollArea;
    QWidget* buttons_container;
    QVBoxLayout* buttons_layout;
    QHBoxLayout* bottom_layout;
    dialogfornote* dialog = nullptr;
    dialogfortodolist* dialog_for_to_do_list = nullptr;
    registration* dialog_registration = nullptr;
    authentication* dialog_authentication = nullptr;
    Crypto crypto;

    QLineEdit* searchLineEdit;

    void showContextMenu(const QPoint& pos);
    void ClearButton();
    void Initialization();


    Manager manager;
    Manager private_manager;
    //PrivateManager private_manager;

    bool isOpenPrivateDialog = false;
    bool isSortedByData = true;
    bool isSearching = false;

    QPushButton* private_button;
    QPushButton* searchButton;

    bool isAdditing = false;
    QPushButton* add_button;
    QPushButton* filter_button;
    QMenu* dropdownMenu;
    QMenu* filterDropMenu;

   protected:
    void closeEvent(QCloseEvent* event) override;


   private slots:
    void PrivateClick();
    void AddClick();
    void AddNoteHelper();
    void OpenFileWithContent(QPushButton* button, QString name_of_file);
    void AddToDoListHelper();
    void SearchInitialization();
    void FilterClick();
    void ShowSortedByAlphabet();
    void ShowSortedByData();
    /*void AddDrawingHelper();*/
};
#endif	// MAINWINDOW_H
