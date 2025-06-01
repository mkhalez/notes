#include "dialogfortodolist.h"
#include <QFile>
#include <QMenu>
#include "ui_dialogfortodolist.h"

dialogfortodolist::dialogfortodolist(QPushButton* button, Manager* manager,
                                     QString folder, Crypto* crypto,
                                     QWidget* parent)
    : QWidget(parent), ui(new Ui::dialogfortodolist) {
    ui->setupUi(this);
    this->folder = folder;
    this->resize(700, 600);

    this->manager = manager;
    this->button = button;
    if (manager->isOpenPrivate) {
        file_manager = new PrivateFileManagerForNote(crypto);
    } else {
        file_manager = new FileManagerForNote();
    }
    this->setWindowTitle("To-Do List");
    this->setStyleSheet("QWidget#dialogfornote { font-size: 10pt; }");

    ui->titleEdit->setPlaceholderText("enter the title..");

    QStringList tasks =
        file_manager->ReadFileForToDoList(folder, manager->to_do_list[button]);

    for (int i = 0; i < tasks.length(); i++) {
        AddTask(tasks[i]);
    }

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(ui->removeAllButton);
    buttonsLayout->addWidget(ui->correctButton);
    buttonsLayout->setAlignment(Qt::AlignRight);

    ui->button_layout->addWidget(ui->titleEdit, 0, Qt::AlignLeft);
    ui->button_layout->addLayout(buttonsLayout);
    ui->titleEdit->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"
        "   border-radius: 5px;"
        "   padding: 3px;"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #4CAF50;"
        "}");
    if (manager->isOpenPrivate) {
        ui->titleEdit->setText(crypto->decryptAES(
            manager->NameForTitle(folder, manager->to_do_list[button])));
    } else {
        ui->titleEdit->setText(
            manager->NameForTitle(folder, manager->to_do_list[button]));
    }


    ui->txtTask->setPlaceholderText("enter the task..");
    ui->txtTask->setFocus();

    ui->txtTask->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"
        "   border-radius: 5px;"
        "   padding: 3px;"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #4CAF50;"
        "}");

    QFont font = ui->txtTask->font();
    font.setPointSize(18);
    ui->txtTask->setFont(font);

    ui->titleEdit->setFont(font);

    font.setPointSize(20);
    ui->listWidget->setFont(font);


    ui->addButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 5px;"
        "   padding: 0px;"
        "   border: none;"
        "   min-width: 65px;"
        "   min-height: 40px;"
        "   font-size: 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"
        "}");

    ui->removeAllButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 5px;"
        "   padding: 0px;"
        "   border: none;"
        "   min-width: 75px;"
        "   min-height: 45px;"
        "   font-size: 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"
        "}");

    ui->correctButton->setIcon(QIcon::fromTheme("document-edit"));
    ui->correctButton->setIconSize(QSize(32, 32));

    ui->correctButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   min-width: 45px;"
        "   min-height: 45px;"
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");

    ui->correctButton->setContextMenuPolicy(Qt::CustomContextMenu);
    dropdownMenu = new QMenu(this);
    dropdownMenu->setStyleSheet(
        "QMenu {"
        "    background-color: transparent;"
        "    padding: 5px;"
        "}"

        "QMenu::item {"
        "    background-color: #008000;"
        "    border: 2px solid #45a049;"
        "    border-radius: 15px;"
        "    margin: 4px 2px;"
        "    padding: 8px 20px 8px 15px;"
        "    min-width: 100px;"
        "    font-size: 17px;"
        "    text-align: left;"
        "    color: white;"
        "}"

        "QMenu::item:selected {"
        "    background-color: #006400;"
        "    border: 2px solid #2d7d32;"
        "}"

        "QMenu::item:pressed {"
        "    background-color: #004d00;"
        "}");

    ui->listWidget->setStyleSheet(
        "QListWidget {"
        "   border: 2px solid gray;"
        "   border-radius: 5px;"
        "   padding: 3px;"
        "}"
        "QListWidget:focus {"
        "   border: 2px solid #4CAF50;"
        "}"

        "QListWidget::item:selected {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "}"

        "QListWidget::item:selected:!active {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "}");


    QAction* СrossOutAction = dropdownMenu->addAction("cross out");
    QAction* RemoveAction = dropdownMenu->addAction("remove");

    connect(ui->txtTask, &QLineEdit::returnPressed, this,
            [this]() { AddTask(ui->txtTask->text()); });

    connect(ui->addButton, &QPushButton::clicked, this,
            [this]() { AddTask(); });
    connect(ui->correctButton, &QPushButton::clicked, this,
            &dialogfortodolist::CorrectTask);
    connect(СrossOutAction, &QAction::triggered, this,
            &dialogfortodolist::CrossOutTask);
    connect(RemoveAction, &QAction::triggered, this,
            &dialogfortodolist::RemoveTask);
    connect(ui->removeAllButton, &QPushButton::clicked, this,
            &dialogfortodolist::RemoveAll);
}

dialogfortodolist::~dialogfortodolist() {
    QString text;
    text = ui->titleEdit->text();
    file_manager->SaveTitle(folder, manager->to_do_list[button], text);

    QStringList tasks;
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (!item->text().isEmpty()) {
            QFont font = item->font();
            tasks << (font.strikeOut() ? QString(QChar(0xE000)) + item->text()
                                       : item->text());
        }
    }

    file_manager->SaveFileForToDoList(folder, manager->to_do_list[button],
                                      tasks);

    delete ui;
}

void dialogfortodolist::AddTask(QString text) {
    if (!text.isEmpty()) {

        if (text.at(0) == QChar(0xE000)) {
            text.remove(0, 1);
            QListWidgetItem* item = new QListWidgetItem(text, ui->listWidget);
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->txtTask->clear();

            QListWidgetItem* space = new QListWidgetItem;
            space->setSizeHint(QSize(0, 2));
            space->setFlags(Qt::NoItemFlags);

            space->setBackground(Qt::gray);
            ui->listWidget->addItem(space);

            ConstructorCrossOutTask(ui->listWidget->row(item));
            return;
        } else {
            QListWidgetItem* item = new QListWidgetItem(text, ui->listWidget);
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->txtTask->clear();

            QListWidgetItem* space = new QListWidgetItem;
            space->setSizeHint(QSize(0, 2));
            space->setFlags(Qt::NoItemFlags);

            space->setBackground(Qt::gray);
            ui->listWidget->addItem(space);
            return;
        }
    }

    if (!(ui->txtTask->text().isEmpty())) {
        QListWidgetItem* item =
            new QListWidgetItem(ui->txtTask->text(), ui->listWidget);

        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->txtTask->clear();

        QListWidgetItem* space = new QListWidgetItem;
        space->setSizeHint(QSize(0, 2));
        space->setFlags(Qt::NoItemFlags);

        space->setBackground(Qt::gray);
        ui->listWidget->addItem(space);
    }

    ui->txtTask->setFocus();
}

void dialogfortodolist::RemoveAll() {
    ui->listWidget->clear();
}

void dialogfortodolist::CorrectTask() {
    QPoint buttonTopRight =
        ui->correctButton->mapToGlobal(QPoint(ui->correctButton->width(), 0));
    int menuWidth = dropdownMenu->sizeHint().width();
    int menuHeight = dropdownMenu->sizeHint().height();
    QPoint menuPos(buttonTopRight.x() - menuWidth,
                   buttonTopRight.y() - menuHeight);

    dropdownMenu->exec(menuPos);
}

void dialogfortodolist::CrossOutTask() {
    int current_row = ui->listWidget->currentRow();
    if (current_row >= 0) {
        QListWidgetItem* item = ui->listWidget->item(current_row);
        QFont font = item->font();

        if (!font.strikeOut()) {
            font.setStrikeOut(true);
        }

        else {
            font.setStrikeOut(false);
        }
        item->setFont(font);
    }
}

void dialogfortodolist::ConstructorCrossOutTask(int current_row) {
    if (current_row >= 0) {
        QListWidgetItem* item = ui->listWidget->item(current_row);
        QFont font = item->font();

        if (!font.strikeOut()) {
            font.setStrikeOut(true);
        }

        else {
            font.setStrikeOut(false);
        }
        item->setFont(font);
    }
}

void dialogfortodolist::RemoveTask() {
    QListWidgetItem* item_1 =
        ui->listWidget->takeItem(ui->listWidget->currentRow() + 1);

    QListWidgetItem* item_2 =
        ui->listWidget->takeItem(ui->listWidget->currentRow());

    delete item_1;
    delete item_2;
}
