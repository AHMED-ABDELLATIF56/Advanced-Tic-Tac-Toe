/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_accept;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(947, 409);
        lineEdit_username = new QLineEdit(Dialog);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(260, 90, 191, 28));
        lineEdit_password = new QLineEdit(Dialog);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(260, 150, 191, 28));
        pushButton_accept = new QPushButton(Dialog);
        pushButton_accept->setObjectName("pushButton_accept");
        pushButton_accept->setGeometry(QRect(310, 220, 83, 29));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 90, 81, 20));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 150, 81, 20));
        pushButton_cancel = new QPushButton(Dialog);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(310, 350, 83, 29));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("Dialog", "register", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "username", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "password", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
