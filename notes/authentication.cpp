#include "authentication.h"
#include <QCloseEvent>
#include <QCryptographicHash>
#include <QMessageBox>
#include "ui_authentication.h"


authentication::authentication(QWidget* parent)
    : QWidget(parent), ui(new Ui::authentication) {
    ui->setupUi(this);

    this->setFixedSize(400, 280);
    this->setWindowTitle("Authentication");

    ui->passwordEdit->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    QFont font = ui->passwordEdit->font();
    font.setPointSize(18);
    ui->passwordEdit->setFont(font);

    ui->continueButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"	 // Светло-зеленый фон
        "   color: black;"				 // Черный текст
        "   border-radius: 5px;"  // Легкое закругление углов (меньше, чем было)
        "   padding: 0px;"
        "   border: none;"	   // Нет границы
        "   font-size: 18px;"  // Размер текста
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"	 // Темно-зеленый при наведении
        "}");

    ui->closeButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"	 // Светло-зеленый фон
        "   color: black;"				 // Черный текст
        "   border-radius: 5px;"  // Легкое закругление углов (меньше, чем было)
        "   padding: 0px;"
        "   border: none;"	   // Нет границы
        "   font-size: 18px;"  // Размер текста
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"	 // Темно-зеленый при наведении
        "}");

    connect(ui->closeButton, &QPushButton::clicked, this, [this] {
        close();
        emit(finishAuthenticationDialogWork(is_success_authentication, ""));
    });
    connect(ui->continueButton, &QPushButton::clicked, this,
            &authentication::CheckUser);
}

authentication::~authentication() {
    delete ui;
}

QString authentication::hashPassword(const QString& password) {
    QByteArray password_data = password.toUtf8();

    QByteArray hash =
        QCryptographicHash::hash(password_data, QCryptographicHash::Sha256);

    return QString(hash.toHex());
}

void authentication::closeEvent(QCloseEvent* event) {
    emit finishAuthenticationDialogWork(is_success_authentication,
                                        correct_password);
    event->accept();
}

void authentication::CheckUser() {
    QString try_guess = ui->passwordEdit->text();
    QString hash_of_guess = hashPassword(try_guess);

    QString true_hash =
        file_manager.ReadSecondLine("data_of_program", "first_using");
    if (true_hash != hash_of_guess) {
        QMessageBox::warning(this,
                             "Password E"
                             "rror",
                             "password is not correct", QMessageBox::Ok);
        ui->passwordEdit->clear();
    } else {

        is_success_authentication = true;
        correct_password = try_guess;
        this->close();
    }
}
