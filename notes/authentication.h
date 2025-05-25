#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QWidget>
#include "filemanagerforregistration.h"

namespace Ui {
class authentication;
}

class authentication : public QWidget {
    Q_OBJECT

   public:
    explicit authentication(QWidget* parent = nullptr);
    ~authentication();

   private:
    Ui::authentication* ui;

    QString hashPassword(const QString& password);
    FileManagerForRegistration file_manager;


   private slots:
    void CheckUser();
};

#endif	// AUTHENTICATION_H
