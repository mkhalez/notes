#include "registration.h"
#include <QMessageBox>
#include <QTimer>
#include "ui_registration.h"

registration::registration(QWidget* parent)
    : QWidget(parent), ui(new Ui::registration) {
    ui->setupUi(this);
    this->setFixedSize(400, 300);
    this->setWindowTitle("Registration");


    ui->firstPassword->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    ui->secondPassword->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    QFont font = ui->secondPassword->font();
    font.setPointSize(18);
    ui->firstPassword->setFont(font);
    ui->secondPassword->setFont(font);

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

    connect(ui->closeButton, &QPushButton::clicked, this, [this] { close(); });
    connect(ui->continueButton, &QPushButton::clicked, this,
            &registration::SetPassword);
}

registration::~registration() {
    delete ui;
}

bool registration::CheckPassword(QString password) {
    if (password.length() < 8)
        return false;

    int number_of_letters = 0;
    int number_of_digit = 0;
    int number_of_symbols = 0;
    int number_of_uppercase = 0;
    int number_of_lowercase = 0;

    for (int i = 0; i < password.length(); i++) {
        if (password[i].isDigit())
            ++number_of_digit;
        if (password[i].isLower())
            ++number_of_lowercase;
        if (password[i].isUpper())
            ++number_of_uppercase;
        if (password[i].isLetter())
            ++number_of_letters;
        if (password[i].isSymbol() || password[i].isPunct())
            ++number_of_symbols;
    }
    if (number_of_digit < 1 || number_of_lowercase < 1 ||
        number_of_uppercase < 1 || number_of_letters < 1 ||
        number_of_symbols < 1) {
        return false;
    }
    return true;
}

QString registration::hashPassword(const QString& password) {
    QByteArray password_data = password.toUtf8();

    QByteArray hash =
        QCryptographicHash::hash(password_data, QCryptographicHash::Sha256);

    return QString(hash.toHex());
}

void registration::SetPassword() {
    QString firsrt_password = ui->firstPassword->text();
    QString second_password = ui->secondPassword->text();
    if (firsrt_password != second_password) {
        QMessageBox::warning(this, "Password Error", "passwords do not match",
                             QMessageBox::Ok);
        ui->firstPassword->clear();
        ui->secondPassword->clear();
        return;
    }

    if (!CheckPassword(firsrt_password)) {
        QMessageBox::warning(this, "Password Error",
                             "Password need to constist of digits, symbols, "
                             "letters. It must have lower case "
                             "and upper case and length of password > 7",
                             QMessageBox::Ok);
        ui->firstPassword->clear();
        ui->secondPassword->clear();
        return;
    }

    file_manager.WriteStation("data_of_program", "first_using",
                              hashPassword(firsrt_password));
    this->close();
}
