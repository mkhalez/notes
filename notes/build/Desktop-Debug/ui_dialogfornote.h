/********************************************************************************
** Form generated from reading UI file 'dialogfornote.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORNOTE_H
#define UI_DIALOGFORNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogfornote
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *titleEdit;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *underlinedButton;
    QPushButton *redButton;
    QPushButton *crossOutButton;

    void setupUi(QWidget *dialogfornote)
    {
        if (dialogfornote->objectName().isEmpty())
            dialogfornote->setObjectName("dialogfornote");
        dialogfornote->resize(400, 300);
        gridLayout = new QGridLayout(dialogfornote);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        titleEdit = new QLineEdit(dialogfornote);
        titleEdit->setObjectName("titleEdit");

        verticalLayout->addWidget(titleEdit);

        textEdit = new QTextEdit(dialogfornote);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        underlinedButton = new QPushButton(dialogfornote);
        underlinedButton->setObjectName("underlinedButton");
        QFont font;
        font.setPointSize(18);
        underlinedButton->setFont(font);

        horizontalLayout->addWidget(underlinedButton);

        redButton = new QPushButton(dialogfornote);
        redButton->setObjectName("redButton");
        redButton->setFont(font);

        horizontalLayout->addWidget(redButton);

        crossOutButton = new QPushButton(dialogfornote);
        crossOutButton->setObjectName("crossOutButton");
        crossOutButton->setFont(font);

        horizontalLayout->addWidget(crossOutButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(dialogfornote);

        QMetaObject::connectSlotsByName(dialogfornote);
    } // setupUi

    void retranslateUi(QWidget *dialogfornote)
    {
        dialogfornote->setWindowTitle(QCoreApplication::translate("dialogfornote", "Form", nullptr));
        underlinedButton->setText(QCoreApplication::translate("dialogfornote", "A", nullptr));
        redButton->setText(QCoreApplication::translate("dialogfornote", "K", nullptr));
        crossOutButton->setText(QCoreApplication::translate("dialogfornote", "N", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogfornote: public Ui_dialogfornote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORNOTE_H
