#ifndef DIALOGFORNOTE_H
#define DIALOGFORNOTE_H

#include <QPushButton>
#include <QWidget>
#include "filemanagerfornote.h"
#include "manager.h"

namespace Ui {
class dialogfornote;
}

class dialogfornote : public QWidget {
    Q_OBJECT

   public:
    explicit dialogfornote(QPushButton* button, Manager* manager,
                           QWidget* parent = nullptr);
    ~dialogfornote();

   private:
    Ui::dialogfornote* ui;
    Manager* manager;
    FileManagerForNote file_manager;
    QPushButton* button;

   private slots:
    void onCrossOutClicked();
    void onUnderlinedClicked();
    void onRedClicked();
};

#endif	// DIALOGFORNOTE_H
