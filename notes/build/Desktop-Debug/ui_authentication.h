/********************************************************************************
** Form generated from reading UI file 'authentication.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATION_H
#define UI_AUTHENTICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authentication
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *passwordEdit;
    QPushButton *continueButton;
    QPushButton *closeButton;
    QLabel *label_3;
    QPushButton *checkPasswordButton;

    void setupUi(QWidget *authentication)
    {
        if (authentication->objectName().isEmpty())
            authentication->setObjectName("authentication");
        authentication->resize(410, 277);
        layoutWidget = new QWidget(authentication);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 110, 271, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout->addWidget(label);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMinimumSize(QSize(0, 30));
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        continueButton = new QPushButton(authentication);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(280, 230, 111, 31));
        QFont font1;
        font1.setPointSize(18);
        continueButton->setFont(font1);
        closeButton = new QPushButton(authentication);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(10, 230, 111, 31));
        closeButton->setFont(font1);
        label_3 = new QLabel(authentication);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 20, 231, 61));
        QFont font2;
        font2.setPointSize(25);
        label_3->setFont(font2);
        checkPasswordButton = new QPushButton(authentication);
        checkPasswordButton->setObjectName("checkPasswordButton");
        checkPasswordButton->setGeometry(QRect(340, 150, 41, 31));
        checkPasswordButton->setFont(font2);

        retranslateUi(authentication);

        QMetaObject::connectSlotsByName(authentication);
    } // setupUi

    void retranslateUi(QWidget *authentication)
    {
        authentication->setWindowTitle(QCoreApplication::translate("authentication", "Form", nullptr));
        label->setText(QCoreApplication::translate("authentication", "enter password:", nullptr));
        continueButton->setText(QCoreApplication::translate("authentication", "continue", nullptr));
        closeButton->setText(QCoreApplication::translate("authentication", "close", nullptr));
        label_3->setText(QCoreApplication::translate("authentication", "authentication", nullptr));
        checkPasswordButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class authentication: public Ui_authentication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATION_H
