/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *firstPassword;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *secondPassword;
    QPushButton *continueButton;
    QLabel *label_3;
    QPushButton *closeButton;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(400, 300);
        layoutWidget = new QWidget(registration);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 70, 271, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout->addWidget(label);

        firstPassword = new QLineEdit(layoutWidget);
        firstPassword->setObjectName("firstPassword");

        verticalLayout->addWidget(firstPassword);

        layoutWidget_2 = new QWidget(registration);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 140, 271, 60));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        secondPassword = new QLineEdit(layoutWidget_2);
        secondPassword->setObjectName("secondPassword");

        verticalLayout_2->addWidget(secondPassword);

        continueButton = new QPushButton(registration);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(280, 260, 111, 31));
        QFont font1;
        font1.setPointSize(18);
        continueButton->setFont(font1);
        label_3 = new QLabel(registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 10, 181, 61));
        QFont font2;
        font2.setPointSize(25);
        label_3->setFont(font2);
        closeButton = new QPushButton(registration);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(10, 260, 111, 31));
        closeButton->setFont(font1);

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Form", nullptr));
        label->setText(QCoreApplication::translate("registration", "new password:", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "confirm:", nullptr));
        continueButton->setText(QCoreApplication::translate("registration", "continue", nullptr));
        label_3->setText(QCoreApplication::translate("registration", "registration", nullptr));
        closeButton->setText(QCoreApplication::translate("registration", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
