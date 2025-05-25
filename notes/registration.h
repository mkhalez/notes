#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <QCryptographicHash>
#include "filemanagerforregistration.h"

#include <QWidget>

namespace Ui {
class registration;
}

class registration : public QWidget {
    Q_OBJECT

   public:
    explicit registration(QWidget* parent = nullptr);
    ~registration();

   private:
    Ui::registration* ui;

    bool CheckPassword(QString password);
    QString hashPassword(const QString& password);

    FileManagerForRegistration file_manager;
   private slots:
    void SetPassword();
};

#endif	// REGISTRATION_H
