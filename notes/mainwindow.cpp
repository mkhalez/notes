#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QStyle>
#include <QVBoxLayout>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), manager() {
    ui->setupUi(this);

    main_container = new QWidget(this);
    main_layout = new QVBoxLayout(main_container);

    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);

    buttons_container = new QWidget();
    buttons_layout = new QVBoxLayout(buttons_container);

    buttons_layout->setSpacing(10);
    buttons_layout->setContentsMargins(20, 20, 20, 20);

    scrollArea->setWidget(buttons_container);

    main_layout->addWidget(scrollArea);

    bottom_layout = new QHBoxLayout();

    private_button = new QPushButton(this);
    // Загрузка иконки
    QPixmap pixmap("/home/mkh-alez/Downloads/new_var.webp");
    // Масштабирование изображения под размер кнопки (сохраняя пропорции)
    QIcon icon(
        pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    private_button->setIcon(icon);
    // Устанавливаем размер кнопки
    private_button->setFixedSize(50, 50);
    // Убираем внутренние отступы кнопки
    private_button->setStyleSheet(
        "QPushButton { padding: 0px; border: none; }");
    // Устанавливаем размер иконки равным размеру кнопки
    private_button->setIconSize(QSize(50, 50));


    bottom_layout->addWidget(private_button, 0, Qt::AlignLeft);

    bottom_layout->addStretch();

    add_button = new QPushButton(this);
    add_button->setFixedSize(50, 50);
    add_button->setText("+");
    add_button->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    bottom_layout->addWidget(add_button, 0, Qt::AlignRight);

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

    QAction* noteAction = dropdownMenu->addAction("note");
    QAction* todoAction = dropdownMenu->addAction("to-do list");
    QAction* drawingAction = dropdownMenu->addAction("drawing");

    main_layout->addLayout(bottom_layout);

    setCentralWidget(main_container);

    connect(private_button, &QPushButton::clicked, this,
            &MainWindow::PrivateClick);

    connect(add_button, &QPushButton::clicked, this, &MainWindow::AddClick);

    connect(noteAction, &QAction::triggered, this, &MainWindow::AddNoteHelper);
    /*connect(todoAction, &QAction::triggered, this,
            &MainWindow::AddToDoListHelper);
    connect(drawingAction, &QAction::triggered, this,
            &MainWindow::AddDrawingHelper);*/
    qDebug() << manager.number_of_item;
    if (manager.number_of_item > 0) {
        buttons_layout->addStretch();
    }


    for (int i = 0; i < manager.list_of_user_files.length(); i++) {
        QPushButton* button =
            new QPushButton(QString("New Note"), buttons_container);
        buttons_layout->insertWidget(buttons_layout->count() - 1, button);
        manager.AddNoteToManager(button, manager.list_of_user_files[i]);


        button->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(button, &QPushButton::customContextMenuRequested, this,
                &MainWindow::showContextMenu);

        connect(button, &QPushButton::clicked, this,
                [this, button]() { OpenFileWithContent(button); });
        /*(button, &QPushButton::clicked, this,
                [this, button]() { manager.OpenFileWithContent(button); });*/
        manager.FillIsOpenButton(button, false);
    }

    /*for (int i = 0; i < manager.number_of_item; i++) {
        if (manager.DoHaveFile("data_of_user",

                               QString::number(i) + "data.txt")) {


            QPushButton* button =
                new QPushButton(QString("New Note"), buttons_container);
            buttons_layout->insertWidget(buttons_layout->count() - 1, button);
            manager.AddNoteToManager(button);


            button->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(button, &QPushButton::customContextMenuRequested, this,
                    &MainWindow::showContextMenu);

            connect(button, &QPushButton::clicked, this, [this, i]() {
                manager.OpenFileWithContent(QString::number(i) + "data.txt");
            });
            //manager.print();
        }
    }*/
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showContextMenu(const QPoint& pos) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    QMenu contextMenu(this);

    // Установка стиля для меню
    contextMenu.setStyleSheet(
        "QMenu {"
        "    background-color: transparent;"  // Прозрачный фон самого меню
        "    padding: 5px;"					  // Отступ вокруг всего меню
        "}"
        ""

        "QMenu::item {"
        "    background-color: #008000;"   // Зелёный цвет фона
        "    border: 2px solid #45a049;"   // Контур
        "    border-radius: 15px;"		   // Сильное закругление
        "    margin: 4px 2px;"			   // Вертикальные отступы
        "    padding: 8px 20px 8px 15px;"  // Внутренние отступы
        "    min-width: 100px;"			   // Минимальная ширина
        "    font-size: 17px;"			   // Размер шрифта
        "    text-align: left;"
        "    color: white;"	 // Цвет текста
        "}"
        ""

        "QMenu::item:selected {"
        "    background-color: #006400;"  // Темнее при выборе
        "    border: 2px solid #2d7d32;"  // Контур при выборе
        "}"
        ""

        "QMenu::item:pressed {"
        "    background-color: #004d00;"  // Ещё темнее при нажатии
        "}");

    // Добавление действий
    QAction* deleteAction = contextMenu.addAction("delete");

    // Отображаем меню и обрабатываем выбор
    QAction* selectedAction = contextMenu.exec(button->mapToGlobal(pos));
    if (selectedAction == deleteAction) {

        int buttonIndex = buttons_layout->indexOf(button);
        if (buttonIndex != -1) {
            // 2. Удалить кнопку из layout
            buttons_layout->takeAt(buttonIndex);

            // 3. Удалить саму кнопку
            button->deleteLater();

            QString name_of_file = manager.GetNameOfFileThanksPtr(button);
            manager.DeleteFile("data_of_user", name_of_file);
        }
    }
}

void MainWindow::PrivateClick() {
    if (isPrivate) {
        // Загружаем первую иконку
        QPixmap pixmap1("/home/mkh-alez/Downloads/new_var.webp");
        QIcon icon1(pixmap1.scaled(50, 50, Qt::KeepAspectRatio,
                                   Qt::SmoothTransformation));
        private_button->setIcon(icon1);
    } else {
        // Загружаем вторую иконку
        QPixmap pixmap2("/home/mkh-alez/Downloads/open_yey.svg");
        QIcon icon2(pixmap2.scaled(50, 50, Qt::KeepAspectRatio,
                                   Qt::SmoothTransformation));
        private_button->setIcon(icon2);
    }

    // Инвертируем состояние
    isPrivate = !isPrivate;
}

void MainWindow::AddClick() {
    // 1. Получаем правый верхний угол кнопки в глобальных координатах
    QPoint buttonTopRight =
        add_button->mapToGlobal(QPoint(add_button->width(), 0));

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

void MainWindow::AddNoteHelper() {
    if (manager.number_of_item == 0) {
        buttons_layout->addStretch();
    }

    QPushButton* button =
        new QPushButton(QString("New Note"), buttons_container);
    buttons_layout->insertWidget(buttons_layout->count() - 1, button);

    int currentNumber = manager.number_of_item;
    currentNumber++;

    manager.AddNoteToManager(button,
                             QString::number(currentNumber) + "data.txt");

    connect(button, &QPushButton::clicked, this,
            [this, button]() { OpenFileWithContent(button); });
    /*connect(button, &QPushButton::clicked, this,
            [this, button]() { manager.OpenFileWithContent(button); });*/

    button->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(button, &QPushButton::customContextMenuRequested, this,
            &MainWindow::showContextMenu);
    manager.FillIsOpenButton(button, false);

    manager.CreateFile(currentNumber);
    manager.number_of_item++;
    //manager.print();
}

void MainWindow::OpenFileWithContent(QPushButton* button) {
    if (manager.is_open_button[button]) {
        return;
    }

    dialog = new dialogfornote();
    manager.is_open_button[button] = true;
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
    dialog->button = button;
    Manager* ptr = &manager;
    dialog->SetManager(ptr);

    connect(dialog, &dialogfornote::destroyed, this,
            [this, button]() { manager.is_open_button[button] = false; });
}

/*void MainWindow::AddToDoListHelper() {
    if (number_of_item == 0) {
        buttons_layout->addStretch();
    }

    QPushButton* button =
        new QPushButton(QString("New To-do list"), buttons_container);
    buttons_layout->insertWidget(buttons_layout->count() - 1, button);
    manager.AddToDoListToManager(button);
    number_of_item++;
    manager.print();
}

void MainWindow::AddDrawingHelper() {
    if (number_of_item == 0) {
        buttons_layout->addStretch();
    }

    QPushButton* button =
        new QPushButton(QString("New To-do list"), buttons_container);
    buttons_layout->insertWidget(buttons_layout->count() - 1, button);
    manager.AddDRrawingToManager(button);
    number_of_item++;
    manager.print();
}*/
