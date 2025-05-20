/********************************************************************************
** Form generated from reading UI file 'dialogfortodolist.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORTODOLIST_H
#define UI_DIALOGFORTODOLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogfortodolist
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtTask;
    QPushButton *addButton;
    QListWidget *listWidget;
    QHBoxLayout *button_layout;
    QPushButton *removeAllButton;
    QPushButton *pushButton;

    void setupUi(QWidget *dialogfortodolist)
    {
        if (dialogfortodolist->objectName().isEmpty())
            dialogfortodolist->setObjectName("dialogfortodolist");
        dialogfortodolist->resize(391, 431);
        gridLayout = new QGridLayout(dialogfortodolist);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        txtTask = new QLineEdit(dialogfortodolist);
        txtTask->setObjectName("txtTask");
        QFont font;
        font.setPointSize(14);
        txtTask->setFont(font);

        horizontalLayout->addWidget(txtTask);

        addButton = new QPushButton(dialogfortodolist);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(dialogfortodolist);
        listWidget->setObjectName("listWidget");
        listWidget->setFont(font);

        verticalLayout->addWidget(listWidget);

        button_layout = new QHBoxLayout();
        button_layout->setObjectName("button_layout");
        removeAllButton = new QPushButton(dialogfortodolist);
        removeAllButton->setObjectName("removeAllButton");
        removeAllButton->setFont(font);

        button_layout->addWidget(removeAllButton);

        pushButton = new QPushButton(dialogfortodolist);
        pushButton->setObjectName("pushButton");

        button_layout->addWidget(pushButton);


        verticalLayout->addLayout(button_layout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(dialogfortodolist);

        QMetaObject::connectSlotsByName(dialogfortodolist);
    } // setupUi

    void retranslateUi(QWidget *dialogfortodolist)
    {
        dialogfortodolist->setWindowTitle(QCoreApplication::translate("dialogfortodolist", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("dialogfortodolist", "add", nullptr));
        removeAllButton->setText(QCoreApplication::translate("dialogfortodolist", "remove all", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialogfortodolist: public Ui_dialogfortodolist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORTODOLIST_H
