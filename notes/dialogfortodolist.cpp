#include "dialogfortodolist.h"
#include <QFile>
#include <QMenu>
#include "ui_dialogfortodolist.h"

dialogfortodolist::dialogfortodolist(QPushButton* button, Manager* manager,
                                     QString folder, QWidget* parent)
    : QWidget(parent), ui(new Ui::dialogfortodolist) {
    ui->setupUi(this);
    this->folder = folder;
    this->resize(700, 600);
    this->setWindowTitle("To-Do List");
    this->manager = manager;
    this->button = button;
    this->setStyleSheet("QWidget#dialogfornote { font-size: 10pt; }");

    ui->titleEdit->setPlaceholderText("enter the title..");

    QStringList tasks =
        file_manager.ReadFileForToDoList(folder, manager->to_do_list[button]);

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
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    ui->titleEdit->setText(
        manager->NameForTitle(folder, manager->to_do_list[button]));

    ui->txtTask->setPlaceholderText("enter the task..");
    ui->txtTask->setFocus();

    ui->txtTask->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"  // Обычная рамка
        "   border-radius: 5px;"	  // Скругление углов
        "   padding: 3px;"			  // Отступ текста от краёв
        "}"
        "QLineEdit:focus {"				 // Стиль при фокусе
        "   border: 2px solid #4CAF50;"	 // Зелёная рамка
        "}");

    QFont font = ui->txtTask->font();
    font.setPointSize(18);
    ui->txtTask->setFont(font);

    ui->titleEdit->setFont(font);

    font.setPointSize(20);
    ui->listWidget->setFont(font);


    ui->addButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"	 // Светло-зеленый фон
        "   color: black;"				 // Черный текст
        "   border-radius: 5px;"  // Легкое закругление углов (меньше, чем было)
        "   padding: 0px;"
        "   border: none;"		// Нет границы
        "   min-width: 65px;"	// Минимальная ширина
        "   min-height: 40px;"	// Минимальная высота
        "   font-size: 20px;"	// Размер текста
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"	 // Темно-зеленый при наведении
        "}");

    ui->removeAllButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"	 // Светло-зеленый фон
        "   color: black;"				 // Черный текст
        "   border-radius: 5px;"  // Легкое закругление углов (меньше, чем было)
        "   padding: 0px;"
        "   border: none;"		// Нет границы
        "   min-width: 75px;"	// Минимальная ширина
        "   min-height: 45px;"	// Минимальная высота
        "   font-size: 20px;"	// Размер текста
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"	 // Темно-зеленый при наведении
        "}");

    ui->correctButton->setIcon(QIcon::fromTheme("document-edit"));
    ui->correctButton->setIconSize(
        QSize(32, 32));	 // Подберите подходящий размер

    ui->correctButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   min-width: 45px;"	// Минимальная ширина
        "   min-height: 45px;"	// Минимальная высота
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");

    ui->correctButton->setContextMenuPolicy(Qt::CustomContextMenu);
    dropdownMenu = new QMenu(this);
    dropdownMenu->setStyleSheet(
        "QMenu {"
        "    background-color: transparent;"  // Прозрачный фон самого меню
        "    padding: 5px;"					  // Отступ вокруг всего меню
        "}"

        "QMenu::item {"
        "    background-color: #008000;"  // Зелёный цвет фона
        "    border: 2px solid #45a049;"  // Контур
        "    border-radius: 15px;"	// Сильное закругление (цилиндрический эффект)
        "    margin: 4px 2px;"		// Вертикальные отступы между пунктами
        "    padding: 8px 20px 8px 15px;"  // Большие внутренние отступы (вытянутость)
        "    min-width: 100px;"			   // Минимальная ширина
        "    font-size: 17px;"			   // Размер шрифта
        "    text-align: left;"
        "    color: white;"	 // Цвет текста
        "}"

        "QMenu::item:selected {"
        "    background-color: #006400;"  // Темнее при выборе
        "    border: 2px solid #2d7d32;"  // Контур при выборе
        "}"

        "QMenu::item:pressed {"
        "    background-color: #004d00;"  // Ещё темнее при нажатии
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
        "   background-color: #4CAF50;"	 // Зеленый цвет фона
        "   color: white;"				 // Цвет текста
        "}"

        "QListWidget::item:selected:!active {"
        "   background-color: #4CAF50;"	 // Зеленый цвет, даже если виджет не в фокусе
        "   color: white;"
        "}");


    QAction* СrossOutAction = dropdownMenu->addAction("cross out");
    QAction* RemoveAction = dropdownMenu->addAction("remove");

    connect(ui->listWidget, &QListWidget::itemClicked, this,
            &dialogfortodolist::onItemClicked);
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this,
            &dialogfortodolist::onItemSelectionChanged);

    connect(ui->txtTask, &QLineEdit::returnPressed, this,
            [this]() { AddTask(ui->txtTask->text()); });

    /*            connect(button, &QPushButton::clicked, this, [this, button]() {
                OpenFileWithContent(button, kToDoList);
            });*/
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
    file_manager.SaveTitle(folder, manager->to_do_list[button], text);

    QStringList tasks;
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (!item->text().isEmpty()) {
            QFont font = item->font();
            tasks << (font.strikeOut() ? QString(QChar(0xE000)) + item->text()
                                       : item->text());
        }
    }

    file_manager.SaveFileForToDoList(folder, manager->to_do_list[button],
                                     tasks);

    delete ui;
}

void dialogfortodolist::onItemClicked() {
    int current_row = ui->listWidget->currentRow();
    if (current_row >= 0) {
        /*QListWidgetItem* item = ui->listWidget->item(current_row);
        QFont font = item->font();

        if (!font.strikeOut()) {
            ui->btnCrossOut->setStyleSheet("background-color: white");
        }

        else {
            ui->btnCrossOut->setStyleSheet("background-color: gray");
        }
        */
    }
}

void dialogfortodolist::onItemSelectionChanged() {
    // Получаем список выбранных элементов
    QList<QListWidgetItem*> selected_items = ui->listWidget->selectedItems();

    /*if (selected_items.isEmpty()) {
        ui->btnCrossOut->setStyleSheet("background-color: white");
    }*/
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
    // 1. Получаем правый верхний угол кнопки в глобальных координатах
    QPoint buttonTopRight =
        ui->correctButton->mapToGlobal(QPoint(ui->correctButton->width(), 0));

    // 2. Вычисляем позицию меню:
    //    - Смещаем влево на ширину меню (чтобы не выходило за экран)
    //    - Смещаем вверх на высоту меню + дополнительный отступ
    int menuWidth = dropdownMenu->sizeHint().width();
    int menuHeight = dropdownMenu->sizeHint().height();
    QPoint menuPos(buttonTopRight.x() - menuWidth,	  // Смещение влево
                   buttonTopRight.y() - menuHeight);  // Смещение вверх

    // 3. Открываем меню с "ступенчатым" смещением
    dropdownMenu->exec(menuPos);
}

void dialogfortodolist::CrossOutTask() {
    int current_row = ui->listWidget->currentRow();
    if (current_row >= 0) {
        QListWidgetItem* item = ui->listWidget->item(current_row);
        QFont font = item->font();

        if (!font.strikeOut()) {
            font.setStrikeOut(true);
            //ui->btnCrossOut->setStyleSheet("background-color: gray");
        }

        else {
            font.setStrikeOut(false);
            //ui->btnCrossOut->setStyleSheet("background-color: white");
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
            //ui->btnCrossOut->setStyleSheet("background-color: gray");
        }

        else {
            font.setStrikeOut(false);
            //ui->btnCrossOut->setStyleSheet("background-color: white");
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
