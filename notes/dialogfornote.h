#ifndef DIALOGFORNOTE_H
#define DIALOGFORNOTE_H

#include <QPushButton>
#include <QWidget>
#include "manager.h"

namespace Ui {
class dialogfornote;
}

class dialogfornote : public QWidget {
    Q_OBJECT

   public:
    explicit dialogfornote(QWidget* parent = nullptr);
    ~dialogfornote();
    QPushButton* button;
    void SetManager(Manager* manager);

   private:
    Ui::dialogfornote* ui;
    Manager* manager;

   private slots:
    void onCrossOutClicked();
    void onUnderlinedClicked();
    void onRedClicked();
};

#endif	// DIALOGFORNOTE_H
