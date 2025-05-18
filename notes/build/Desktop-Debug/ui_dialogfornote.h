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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogfornote
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *dialogfornote)
    {
        if (dialogfornote->objectName().isEmpty())
            dialogfornote->setObjectName("dialogfornote");
        dialogfornote->resize(400, 300);
        gridLayout = new QGridLayout(dialogfornote);
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(dialogfornote);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        textEdit = new QTextEdit(dialogfornote);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(dialogfornote);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(dialogfornote);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        pushButton_3 = new QPushButton(dialogfornote);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_3->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(dialogfornote);

        QMetaObject::connectSlotsByName(dialogfornote);
    } // setupUi

    void retranslateUi(QWidget *dialogfornote)
    {
        dialogfornote->setWindowTitle(QCoreApplication::translate("dialogfornote", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("dialogfornote", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dialogfornote", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dialogfornote", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogfornote: public Ui_dialogfornote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORNOTE_H
