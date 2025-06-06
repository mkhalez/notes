#ifndef DIALOGFORNOTE_H
#define DIALOGFORNOTE_H

#include <QPushButton>
#include <QWidget>
#include "crypto.h"
#include "filemanagerfornote.h"
#include "manager.h"
#include "privatefilemanagerfornote.h"

namespace Ui {
class dialogfornote;
}

class dialogfornote : public QWidget {
    Q_OBJECT

   public:
    explicit dialogfornote(QPushButton* button, Manager* manager,
                           QString folder, Crypto* crypto,
                           QWidget* parent = nullptr);
    ~dialogfornote();

   private:
    Ui::dialogfornote* ui;
    Manager* manager;
    PrivateFileManagerForNote* private_file_manager;
    FileManagerForNote* file_manager;
    QPushButton* button;
    QString folder;

   private slots:
    void onCrossOutClicked();
    void onUnderlinedClicked();
    void onRedClicked();
};

#endif	// DIALOGFORNOTE_H
