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
    bool is_success_authentication = false;
    QString correct_password = "";

   protected:
    void closeEvent(QCloseEvent* event) override;

   private slots:
    void CheckUser();

   signals:
    void finishAuthenticationDialogWork(bool success, const QString& password);
};

#endif	// AUTHENTICATION_H
