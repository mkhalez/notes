#include "dialogfornote.h"
#include "ui_dialogfornote.h"


dialogfornote::dialogfornote(QPushButton* button, Manager* manager,
                             QString folder, QWidget* parent)
    : QWidget(parent), ui(new Ui::dialogfornote) {
    ui->setupUi(this);
    this->folder = folder;
    //qDebug() << folder;
    this->manager = manager;
    /*for (int i = 0; i < manager->list_of_user_files.length(); i++) {

        qDebug() << manager->list_of_user_files[i];
    }*/
    this->button = button;
    this->resize(700, 600);
    this->setWindowTitle("Note");
    this->setStyleSheet("QWidget#dialogfornote { font-size: 10pt; }");
    ui->titleEdit->setPlaceholderText("the title of note..");
    ui->textEdit->setPlaceholderText("the text of note..");
    int size = 50;

    ui->textEdit->setHtml(
        file_manager.ReadFile(folder, manager->notes[button]));

    ui->titleEdit->setText(
        manager->NameForTitle(folder, manager->notes[button]));
    if (ui->titleEdit->text().isEmpty()) {
        ui->titleEdit->setFocus();
    } else {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(cursor);
        ui->textEdit->setFocus();
    }

    QFont font = ui->textEdit->font();
    font.setPointSize(18);
    ui->textEdit->setFont(font);

    font.setPointSize(24);
    ui->titleEdit->setFont(font);

    ui->underlinedButton->setFixedSize(size, size);
    ui->crossOutButton->setFixedSize(size, size);
    ui->redButton->setFixedSize(size, size);
    ui->horizontalLayout->setAlignment(Qt::AlignRight);

    connect(ui->underlinedButton, &QPushButton::clicked, this,
            &dialogfornote::onUnderlinedClicked);
    connect(ui->crossOutButton, &QPushButton::clicked, this,
            &dialogfornote::onCrossOutClicked);
    connect(ui->redButton, &QPushButton::clicked, this,
            &dialogfornote::onRedClicked);

    ui->underlinedButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "   text-decoration: underline;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    ui->redButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: red;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    ui->crossOutButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "   text-decoration: line-through;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");

    ui->titleEdit->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    ui->textEdit->setStyleSheet(
        "QTextEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QTextEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");
}

dialogfornote::~dialogfornote() {
    QString text;
    text = ui->titleEdit->text();
    file_manager.SaveTitle(folder, manager->notes[button], text);
    text = ui->textEdit->toHtml();
    file_manager.SaveFile(folder, manager->notes[button], text);


    delete ui;
}

void dialogfornote::onCrossOutClicked() {
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;

    format.setFontStrikeOut(!cursor.charFormat().fontStrikeOut());
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

void dialogfornote::onUnderlinedClicked() {
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;

    format.setFontUnderline(!cursor.charFormat().fontUnderline());
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

void dialogfornote::onRedClicked() {
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;

    if (cursor.charFormat().foreground().color() == Qt::red) {
        format.setForeground(Qt::white);
    } else {
        format.setForeground(Qt::red);
    }
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}
