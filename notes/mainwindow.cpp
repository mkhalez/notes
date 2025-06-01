#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QStyle>
#include <QVBoxLayout>
#include "search.h"

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      manager("data_of_user"),


      private_manager(

          "data_of_user/private_data") {

    ui->setupUi(this);

    manager.isOpenPrivate = false;
    private_manager.isOpenPrivate = false;

    this->setWindowTitle("MIND STORAGE");

    main_container = new QWidget(this);
    main_layout = new QVBoxLayout(main_container);

    QWidget* searchWidget = new QWidget(this);
    QHBoxLayout* searchLayout = new QHBoxLayout(searchWidget);
    searchLayout->setContentsMargins(15, 0, 15, 0);
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Search...");
    searchLineEdit->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid gray;"
        "   border-radius: 5px;"
        "   padding: 3px;"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #4CAF50;"
        "}");
    QFont font = searchLineEdit->font();
    font.setPointSize(18);
    searchLineEdit->setFont(font);
    searchButton = new QPushButton(this);
    searchButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"

        "   padding: 0px;"
        "   border: none;"
        "   font-size: 25px;"
        "   padding-top: 10px;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    searchButton->setFixedSize(43, 43);
    searchButton->setText("🔍");
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);
    main_layout->addWidget(searchWidget);
    connect(searchButton, &QPushButton::clicked, this,
            &MainWindow::SearchInitialization);
    connect(searchLineEdit, &QLineEdit::returnPressed, this,
            [this]() { SearchInitialization(); });


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
    QPixmap pixmap("data_of_program/photo_for_private_button/new_var.webp");
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

    filter_button = new QPushButton(this);
    filter_button->setFixedSize(50, 50);
    filter_button->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    QPixmap pixmap_filter(
        "data_of_program/photo_for_private_button/filter.svg");
    QIcon icon_filter(pixmap_filter.scaled(70, 70, Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation));
    filter_button->setIcon(icon_filter);
    bottom_layout->addWidget(filter_button, 0, Qt::AlignRight);

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

    filterDropMenu = new QMenu(this);
    filterDropMenu->setStyleSheet(
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


    QAction* alphabetAction = filterDropMenu->addAction("alphabet");
    QAction* dataAction = filterDropMenu->addAction("data");

    connect(filter_button, &QPushButton::clicked, this,
            &MainWindow::FilterClick);
    connect(alphabetAction, &QAction::triggered, this,
            &MainWindow::ShowSortedByAlphabet);
    connect(dataAction, &QAction::triggered, this,
            &MainWindow::ShowSortedByData);


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

    dropdownMenu->setWindowFlags(dropdownMenu->windowFlags() |
                                 Qt::FramelessWindowHint);
    dropdownMenu->setAttribute(Qt::WA_TranslucentBackground);

    QAction* noteAction = dropdownMenu->addAction("note");
    QAction* todoAction = dropdownMenu->addAction("to-do list");

    main_layout->addLayout(bottom_layout);

    setCentralWidget(main_container);

    connect(private_button, &QPushButton::clicked, this,
            &MainWindow::PrivateClick);

    connect(add_button, &QPushButton::clicked, this, &MainWindow::AddClick);
    connect(noteAction, &QAction::triggered, this, &MainWindow::AddNoteHelper);
    connect(todoAction, &QAction::triggered, this,
            &MainWindow::AddToDoListHelper);
    /*connect(drawingAction, &QAction::triggered, this,
            &MainWindow::AddDrawingHelper);*/
    //qDebug() << manager.number_of_item;

    Initialization();

    /*if (manager.number_of_item > 0) {
        buttons_layout->addStretch();
    }

    for (int i = 0; i < manager.list_of_user_files.length(); i++) {

        int type_of_button = manager.ReadFirstLine(
            "data_of_user", manager.list_of_user_files[i]);
        if (type_of_button == -1)
            continue;

        QString name_for_button =
            manager.NameForTitle("data_of_user", manager.list_of_user_files[i]);
        QPushButton* button = nullptr;

        if (name_for_button.isEmpty() && type_of_button == 0) {
            button = new QPushButton(QString("New Note"), buttons_container);
            buttons_layout->insertWidget(buttons_layout->count() - 1, button);
            manager.AddNoteToManager(button, manager.list_of_user_files[i]);
        } else if (name_for_button.isEmpty() && type_of_button == 1) {
            button =
                new QPushButton(QString("New To-Do List"), buttons_container);
            buttons_layout->insertWidget(buttons_layout->count() - 1, button);
            manager.AddToDoListToManager(button, manager.list_of_user_files[i]);
        } else if (!name_for_button.isEmpty() && type_of_button == 0) {
            button =
                new QPushButton(QString(name_for_button), buttons_container);
            buttons_layout->insertWidget(buttons_layout->count() - 1, button);
            manager.AddNoteToManager(button, manager.list_of_user_files[i]);
        } else if (!name_for_button.isEmpty() && type_of_button == 1) {
            button =
                new QPushButton(QString(name_for_button), buttons_container);
            buttons_layout->insertWidget(buttons_layout->count() - 1, button);
            manager.AddToDoListToManager(button, manager.list_of_user_files[i]);
        }


        button->setContextMenuPolicy(Qt::CustomContextMenu);

        button->setStyleSheet(
            "QPushButton {"
            "   font-size: 20px;"
            "}");


        connect(button, &QPushButton::customContextMenuRequested, this,
                &MainWindow::showContextMenu);
        if (type_of_button == 0) {
            connect(button, &QPushButton::clicked, this, [this, button]() {
                OpenFileWithContent(button, manager.notes[button]);
            });

            manager.FillIsOpenButton(button, false);
        } else if (type_of_button == 1) {
            connect(button, &QPushButton::clicked, this, [this, button]() {
                OpenFileWithContent(button, manager.to_do_list[button]);
            });

            manager.FillIsOpenButton(button, false);
        }
    }*/

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

    QWidget* container = qobject_cast<QWidget*>(button->parent());
    if (!container)
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

        auto& current_manager =
            private_manager.isOpenPrivate ? private_manager : manager;


        if (!current_manager.is_open_button[button]) {

            int containerIndex = buttons_layout->indexOf(container);
            if (containerIndex != -1) {
                // 2. Удаляем контейнер из layout
                QLayoutItem* item = buttons_layout->takeAt(containerIndex);

                // 3. Удаляем файл
                QString name_of_file =
                    current_manager.GetNameOfFileThanksPtr(button);
                manager.DeleteFile(private_manager.isOpenPrivate
                                       ? "data_of_user/private_data"
                                       : "data_of_user",
                                   name_of_file);

                // 4. Удаляем контейнер и все его дочерние виджеты
                if (item) {
                    item->widget()->deleteLater();
                    delete item;
                }
            }
        }
    }
}

void MainWindow::ClearButton() {
    QLayoutItem* item;
    while ((item = buttons_layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            // Пытаемся получить контейнер (QWidget)
            QWidget* container = qobject_cast<QWidget*>(item->widget());
            if (container) {
                // Ищем кнопку внутри контейнера
                QPushButton* button = container->findChild<QPushButton*>();

                // Проверяем, не является ли это системной кнопкой
                if (button && button != private_button &&
                    button != add_button && button != searchButton) {
                    // Удаляем контейнер и все его содержимое
                    container->deleteLater();
                }
                // Если это системная кнопка, не удаляем её
            }
        }
        delete item;  // Удаляем QLayoutItem
    }
}

void MainWindow::Initialization() {
    ClearButton();
    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    current_manager.Update(isSortedByData, private_manager.isOpenPrivate,
                           crypto.GetKey());
    if (current_manager.number_of_item > 0) {
        buttons_layout->addStretch();
    }

    for (int i = 0; i < current_manager.list_of_user_files.length(); i++) {

        int type_of_button = current_manager.ReadFirstLine(
            private_manager.isOpenPrivate ? "data_of_user/private_data"
                                          : "data_of_user",
            current_manager.list_of_user_files[i]);
        if (type_of_button == -1)
            continue;


        QString name_for_button = current_manager.NameForTitle(
            current_manager.isOpenPrivate ? "data_of_user/private_data"
                                          : "data_of_user",
            current_manager.list_of_user_files[i]);
        if (current_manager.isOpenPrivate) {
            name_for_button = crypto.decryptAES(name_for_button);
        }

        // Создаем контейнер для кнопки с зеленой полосой
        QWidget* button_container = new QWidget(buttons_container);
        QHBoxLayout* container_layout = new QHBoxLayout(button_container);
        container_layout->setContentsMargins(0, 0, 0, 0);
        container_layout->setSpacing(0);

        // Зеленая полоса слева (3 пикселя шириной)
        QWidget* green_space = new QWidget(button_container);
        green_space->setFixedWidth(5);

        container_layout->addWidget(green_space);

        QPushButton* button = nullptr;

        if (name_for_button.isEmpty() && type_of_button == 0) {
            button = new QPushButton(QString("New Note"), button_container);
            green_space->setStyleSheet("background-color: #006400;");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            container_layout->addWidget(button);

            // Добавляем контейнер в основной layout
            buttons_layout->insertWidget(buttons_layout->count() - 1,
                                         button_container);
            current_manager.AddNoteToManager(
                button, current_manager.list_of_user_files[i]);
        } else if (name_for_button.isEmpty() && type_of_button == 1) {
            button =
                new QPushButton(QString("New To-Do List"), button_container);
            green_space->setStyleSheet("background-color: #2E8B57;");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            container_layout->addWidget(button);

            // Добавляем контейнер в основной layout
            buttons_layout->insertWidget(buttons_layout->count() - 1,
                                         button_container);
            current_manager.AddToDoListToManager(
                button, current_manager.list_of_user_files[i]);
        } else if (!name_for_button.isEmpty() && type_of_button == 0) {
            button =
                new QPushButton(QString(name_for_button), button_container);
            green_space->setStyleSheet("background-color: #006400;");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            container_layout->addWidget(button);

            // Добавляем контейнер в основной layout
            buttons_layout->insertWidget(buttons_layout->count() - 1,
                                         button_container);
            current_manager.AddNoteToManager(
                button, current_manager.list_of_user_files[i]);
        } else if (!name_for_button.isEmpty() && type_of_button == 1) {
            button =
                new QPushButton(QString(name_for_button), button_container);
            green_space->setStyleSheet("background-color: #2E8B57;");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            container_layout->addWidget(button);

            // Добавляем контейнер в основной layout
            buttons_layout->insertWidget(buttons_layout->count() - 1,
                                         button_container);
            current_manager.AddToDoListToManager(
                button, current_manager.list_of_user_files[i]);
        }


        button->setContextMenuPolicy(Qt::CustomContextMenu);
        button->setStyleSheet(
            "QPushButton{"
            "   font-size: 20px;"
            "}");


        connect(button, &QPushButton::customContextMenuRequested, this,
                &MainWindow::showContextMenu);
        if (type_of_button == 0) {
            connect(button, &QPushButton::clicked, this,
                    [this, button, &current_manager]() {
                        OpenFileWithContent(button,
                                            current_manager.notes[button]);
                    });
            /*(button, &QPushButton::clicked, this,
                [this, button]() { current_manager.OpenFileWithContent(button); });*/
            current_manager.FillIsOpenButton(button,
                                             private_manager.isOpenPrivate
                                                 ? "data_of_user/private_data"
                                                 : "data_of_user",
                                             false);
        } else if (type_of_button == 1) {
            connect(button, &QPushButton::clicked, this,
                    [this, button, &current_manager]() {
                        OpenFileWithContent(button,
                                            current_manager.to_do_list[button]);
                    });
            /*(button, &QPushButton::clicked, this,
                [this, button]() { current_manager.OpenFileWithContent(button); });*/
            current_manager.FillIsOpenButton(button,
                                             private_manager.isOpenPrivate
                                                 ? "data_of_user/private_data"
                                                 : "data_of_user",
                                             false);
        }
    }
}

void MainWindow::SearchInitialization() {
    if (isSearching) {
        searchButton->setText("🔍");
        isSearching = false;
        searchButton->setStyleSheet(
            "QPushButton {"
            "   background-color: #90EE90;"
            "   color: black;"
            "   border-radius: 10px;"
            "   padding: 0px;"
            "   border: none;"
            "   font-size: 25px;"
            "   padding-top: 10px;"
            "}"
            "QPushButton:hover { background-color: #45a049; }");
        QFont font = searchLineEdit->font();
        font.setPointSize(18);
        searchLineEdit->setFont(font);
        searchLineEdit->clear();
        searchLineEdit->setFocus();
        Initialization();
        return;
    }

    QString text_to_search = searchLineEdit->text();
    if (text_to_search.isEmpty())
        return;

    Search search;
    int i = 0;
    while (i < buttons_layout->count()) {
        QLayoutItem* item = buttons_layout->itemAt(i);
        if (item && item->widget()) {
            // Получаем контейнер (QWidget), а не кнопку напрямую
            QWidget* container = qobject_cast<QWidget*>(item->widget());
            if (container) {
                // Находим кнопку внутри контейнера
                QPushButton* button = container->findChild<QPushButton*>();
                if (button && button != private_button &&
                    button != add_button && button != searchButton &&
                    (search.Distance(text_to_search, button->text()) > 3 ||
                     (search.Distance(text_to_search, button->text()) == 3 &&
                      !search.TheSameString(text_to_search, button->text())))) {

                    // Удаляем весь контейнер (с кнопкой и зеленой полосой)
                    QLayoutItem* itemToDelete = buttons_layout->takeAt(i);
                    if (itemToDelete) {
                        // Удаляем из менеджера, если нужно
                        auto& current_manager = private_manager.isOpenPrivate
                                                    ? private_manager
                                                    : manager;


                        itemToDelete->widget()->deleteLater();
                        delete itemToDelete;
                    }
                } else {
                    i++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
    }

    searchButton->setText("×");
    isSearching = true;
    searchButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #90EE90;"
        "   color: black;"
        "   border-radius: 10px;"
        "   padding: 0px;"
        "   border: none;"
        "   font-size: 25px;"
        "}"
        "QPushButton:hover { background-color: #45a049; }");
    QFont font = searchLineEdit->font();
    font.setPointSize(18);
    searchLineEdit->setFont(font);
    searchLineEdit->setFocus();
}

void MainWindow::FilterClick() {
    // 1. Получаем правый верхний угол кнопки в глобальных координатах
    QPoint buttonTopRight =
        add_button->mapToGlobal(QPoint(add_button->width(), 0));

    // 2. Вычисляем позицию меню:
    //    - Смещаем влево на ширину меню (чтобы не выходило за экран)
    //    - Смещаем вверх на высоту меню + дополнительный отступ
    int menuWidth = filterDropMenu->sizeHint().width();
    int menuHeight = filterDropMenu->sizeHint().height();
    QPoint menuPos(buttonTopRight.x() - menuWidth,	  // Смещение влево
                   buttonTopRight.y() - menuHeight);  // Смещение вверх

    // 3. Открываем меню с "ступенчатым" смещением
    filterDropMenu->exec(menuPos);
}

void MainWindow::ShowSortedByAlphabet() {
    if (!isSortedByData)
        return;


    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    current_manager.SortedByAlphabet(
        private_manager.isOpenPrivate ? "data_of_user/private_data"
                                      : "data_of_user",
        private_manager.isOpenPrivate, crypto.GetKey());
    isSortedByData = !isSortedByData;
    if (isSearching) {
        isSearching = !isSearching;
        Initialization();
        SearchInitialization();
    } else {
        Initialization();
    }
}

void MainWindow::ShowSortedByData() {
    if (isSortedByData)
        return;

    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    current_manager.SortedByData();
    isSortedByData = !isSortedByData;
    if (isSearching) {
        isSearching = !isSearching;
        Initialization();
        SearchInitialization();
    } else {
        Initialization();
    }
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if (dialog && dialog->isVisible()) {
        dialog->close();
    }
    if (dialog_registration) {
        dialog_registration->close();
    }
    if (dialog_authentication && isOpenPrivateDialog) {
        dialog_authentication->close();
    }

    QMainWindow::closeEvent(event);
}

void MainWindow::PrivateClick() {
    if (!isOpenPrivateDialog && !private_manager.isOpenPrivate) {

        registration_file_manager.CreateFile("data_of_program", "first_using");
        int first_line =
            manager.ReadFirstLine("data_of_program", "first_using");
        isOpenPrivateDialog = true;

        if (first_line == -1) {
            /*QPixmap pixmap1(
                "data_of_program/photo_for_private_button/open_yey.svg");
            QIcon icon1(pixmap1.scaled(50, 50, Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation));
            private_button->setIcon(icon1);*/
            dialog_registration = new registration();

            //private_manager.isOpenPrivate = true;
            dialog_registration->setAttribute(Qt::WA_DeleteOnClose);
            dialog_registration->show();
            connect(dialog_registration, &registration::destroyed, this,
                    [this]() {
                        //private_manager.isOpenPrivate = false;
                        dialog_registration = nullptr;
                        isOpenPrivateDialog = false;
                        /*QPixmap pixmap2(
                            "data_of_program/photo_for_private_button/"
                            "new_var.webp");
                        QIcon icon2(pixmap2.scaled(50, 50, Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));
                        private_button->setIcon(icon2);*/
                    });
        } else if (first_line == 0) {

            /*
            QPixmap pixmap1(
                "data_of_program/photo_for_private_button/open_yey.svg");
            QIcon icon1(pixmap1.scaled(50, 50, Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation));
            private_button->setIcon(icon1);
            private_manager.isOpenPrivate = true;*/

            isOpenPrivateDialog = true;

            dialog_authentication = new authentication();

            dialog_authentication->setAttribute(Qt::WA_DeleteOnClose);

            dialog_authentication->show();
            connect(
                dialog_authentication,
                &authentication::finishAuthenticationDialogWork, this,
                [this](bool success_authentication, QString correct_password) {
                    if (!success_authentication) {
                        //private_manager.isOpenPrivate = false;
                        dialog_authentication = nullptr;
                        isOpenPrivateDialog = false;
                        /*QPixmap pixmap2(
                            "data_of_program/photo_for_private_button/"
                            "new_var.webp");
                        QIcon icon2(pixmap2.scaled(50, 50, Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));
                        private_button->setIcon(icon2);*/
                    } else {
                        //qDebug() << correct_password;
                        // случай isPrivate = false; private_manager.isOpenPrivate = true;
                        isOpenPrivateDialog = false;
                        QPixmap pixmap1(
                            "data_of_program/photo_for_private_button/"
                            "open_yey.svg");
                        QIcon icon1(pixmap1.scaled(50, 50, Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));
                        private_button->setIcon(icon1);
                        private_manager.isOpenPrivate = true;

                        crypto.SetKey(correct_password);


                        Initialization();
                        searchLineEdit->setFocus();
                    }
                });
        }
    } else if (!isOpenPrivateDialog && private_manager.isOpenPrivate) {
        isOpenPrivateDialog = false;
        private_manager.isOpenPrivate = false;
        QPixmap pixmap2(
            "data_of_program/photo_for_private_button/"
            "new_var.webp");
        QIcon icon2(pixmap2.scaled(50, 50, Qt::KeepAspectRatio,
                                   Qt::SmoothTransformation));
        private_button->setIcon(icon2);

        Initialization();
        searchLineEdit->setFocus();
    }
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
    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    if (current_manager.number_of_item == 0) {
        buttons_layout->addStretch();
    }

    // Создаем контейнер для кнопки
    QWidget* button_container = new QWidget(buttons_container);
    QHBoxLayout* container_layout = new QHBoxLayout(button_container);
    container_layout->setContentsMargins(0, 0, 0, 0);
    container_layout->setSpacing(0);

    // Добавляем зеленую полосу слева
    QWidget* green_space = new QWidget(button_container);
    green_space->setFixedWidth(5);
    green_space->setStyleSheet("background-color: #006400;");
    container_layout->addWidget(green_space);

    // Создаем саму кнопку
    QPushButton* button = new QPushButton("New Note", button_container);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    container_layout->addWidget(button);

    // Добавляем контейнер в основной layout перед stretch
    buttons_layout->insertWidget(buttons_layout->count() - 1, button_container);

    int currentNumber = current_manager.number_of_item;
    currentNumber++;

    current_manager.AddNoteToManager(
        button, QString::number(currentNumber) + "data.txt");

    connect(button, &QPushButton::clicked, this,
            [this, button, &current_manager]() {
                OpenFileWithContent(button, current_manager.notes[button]);
            });
    /*connect(button, &QPushButton::clicked, this,
            [this, button]() { current_manager.OpenFileWithContent(button); });*/

    button->setContextMenuPolicy(Qt::CustomContextMenu);
    button->setStyleSheet(
        "QPushButton {"
        "   padding: 5px;"
        "   font-size: 20px;"
        "}");
    connect(button, &QPushButton::customContextMenuRequested, this,
            &MainWindow::showContextMenu);

    current_manager.FillIsOpenButton(button,
                                     private_manager.isOpenPrivate
                                         ? "data_of_user/private_data"
                                         : "data_of_user",
                                     false);

    current_manager.CreateFile(currentNumber, 0,
                               private_manager.isOpenPrivate
                                   ? "data_of_user/private_data"
                                   : "data_of_user");
    current_manager.number_of_item++;
}

void MainWindow::OpenFileWithContent(QPushButton* button,
                                     QString name_of_file) {
    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    if (current_manager.is_open_button[button]) {
        return;
    }
    int type_of_file = manager.ReadFirstLine(private_manager.isOpenPrivate
                                                 ? "data_of_user/private_data"
                                                 : "data_of_user",
                                             name_of_file);
    if (type_of_file == 0) {
        dialog = new dialogfornote(button, &current_manager,
                                   private_manager.isOpenPrivate
                                       ? "data_of_user/private_data"
                                       : "data_of_user",
                                   &crypto);

        current_manager.is_open_button[button] = true;
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();

        connect(dialog, &dialogfornote::destroyed, this,
                [this, button, &current_manager]() {
                    current_manager.is_open_button[button] = false;
                    dialog = nullptr;
                    QString name_of_button = current_manager.NameForTitle(
                        private_manager.isOpenPrivate
                            ? "data_of_user/private_data"
                            : "data_of_user",
                        current_manager.notes[button]);

                    if (!name_of_button.isEmpty()) {
                        if (private_manager.isOpenPrivate) {
                            button->setText(crypto.decryptAES(name_of_button));
                        } else {
                            button->setText(name_of_button);
                        }
                    } else {
                        button->setText("New Note");
                    }
                });
    }


    else if (type_of_file == 1) {
        auto& current_manager =
            private_manager.isOpenPrivate ? private_manager : manager;
        Manager* ptr = &current_manager;
        dialog_for_to_do_list = new dialogfortodolist(
            button, &current_manager,
            private_manager.isOpenPrivate ? "data_of_user/private_data"
                                          : "data_of_user",
            &crypto);
        current_manager.is_open_button[button] = true;
        dialog_for_to_do_list->setAttribute(Qt::WA_DeleteOnClose);
        dialog_for_to_do_list->show();

        connect(dialog_for_to_do_list, &dialogfortodolist::destroyed, this,
                [this, button, &current_manager]() {
                    current_manager.is_open_button[button] = false;
                    dialog_for_to_do_list = nullptr;
                    QString name_of_button = current_manager.NameForTitle(
                        private_manager.isOpenPrivate
                            ? "data_of_user/private_data"
                            : "data_of_user",
                        current_manager.to_do_list[button]);
                    if (!name_of_button.isEmpty()) {
                        if (private_manager.isOpenPrivate) {
                            button->setText(crypto.decryptAES(name_of_button));
                        } else {
                            button->setText(name_of_button);
                        }
                    } else {
                        button->setText("New To-Do List");
                    }
                });
    }
}

void MainWindow::AddToDoListHelper() {
    auto& current_manager =
        private_manager.isOpenPrivate ? private_manager : manager;
    if (current_manager.number_of_item == 0) {
        buttons_layout->addStretch();
    }

    // Создаем контейнер для кнопки
    QWidget* button_container = new QWidget(buttons_container);
    QHBoxLayout* container_layout = new QHBoxLayout(button_container);
    container_layout->setContentsMargins(0, 0, 0, 0);
    container_layout->setSpacing(0);

    // Добавляем зеленую полосу слева
    QWidget* green_space = new QWidget(button_container);
    green_space->setFixedWidth(5);
    green_space->setStyleSheet("background-color: #2E8B57;");
    container_layout->addWidget(green_space);

    // Создаем саму кнопку
    QPushButton* button = new QPushButton("New To-Do List", button_container);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    container_layout->addWidget(button);

    // Добавляем контейнер в основной layout перед stretch
    buttons_layout->insertWidget(buttons_layout->count() - 1, button_container);

    int currentNumber = current_manager.number_of_item;
    currentNumber++;

    current_manager.AddToDoListToManager(
        button, QString::number(currentNumber) + "data.txt");

    connect(button, &QPushButton::clicked, this,
            [this, button, &current_manager]() {
                OpenFileWithContent(button, current_manager.to_do_list[button]);
            });
    /*connect(button, &QPushButton::clicked, this,
            [this, button]() { current_manager.OpenFileWithContent(button); });*/

    button->setContextMenuPolicy(Qt::CustomContextMenu);

    button->setStyleSheet(
        "QPushButton {"
        "   padding: 5px;"
        "   font-size: 20px;"
        "}");
    connect(button, &QPushButton::customContextMenuRequested, this,
            &MainWindow::showContextMenu);
    current_manager.FillIsOpenButton(button,
                                     private_manager.isOpenPrivate
                                         ? "data_of_user/private_data"
                                         : "data_of_user",
                                     false);

    current_manager.CreateFile(currentNumber, 1,
                               private_manager.isOpenPrivate
                                   ? "data_of_user/private_data"
                                   : "data_of_user");
    current_manager.number_of_item++;
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
