#include "dialogfortodolist.h"
#include <QMenu>
#include "ui_dialogfortodolist.h"

dialogfortodolist::dialogfortodolist(QPushButton* button, Manager* manager,
                                     QWidget* parent)
    : QWidget(parent), ui(new Ui::dialogfortodolist) {
    ui->setupUi(this);
    this->setWindowTitle("to-do list");

    ui->pushButton->setIcon(QIcon::fromTheme("document-edit"));

    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    ui->pushButton->setContextMenuPolicy(Qt::CustomContextMenu);
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

    ui->button_layout->setAlignment(Qt::AlignRight);

    QAction* СrossOutAction = dropdownMenu->addAction("cross out");
    QAction* RemoveAction = dropdownMenu->addAction("remove");

    connect(ui->listWidget, &QListWidget::itemClicked, this,
            &dialogfortodolist::onItemClicked);
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this,
            &dialogfortodolist::onItemSelectionChanged);
    connect(ui->addButton, &QPushButton::clicked, this,
            &dialogfortodolist::AddTask);
    connect(ui->pushButton, &QPushButton::clicked, this,
            &dialogfortodolist::CorrectTask);
    connect(СrossOutAction, &QAction::triggered, this,
            &dialogfortodolist::CrossOutTask);
    connect(RemoveAction, &QAction::triggered, this,
            &dialogfortodolist::RemoveTask);
}

dialogfortodolist::~dialogfortodolist() {
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

void dialogfortodolist::AddTask() {
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
        ui->pushButton->mapToGlobal(QPoint(ui->pushButton->width(), 0));

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

void dialogfortodolist::RemoveTask() {
    QListWidgetItem* item_1 =
        ui->listWidget->takeItem(ui->listWidget->currentRow() + 1);

    QListWidgetItem* item_2 =
        ui->listWidget->takeItem(ui->listWidget->currentRow());

    delete item_1;
    delete item_2;
}
