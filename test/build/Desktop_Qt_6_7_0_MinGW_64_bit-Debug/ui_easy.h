/********************************************************************************
** Form generated from reading UI file 'easy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASY_H
#define UI_EASY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_easy
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QDialog *easy)
    {
        if (easy->objectName().isEmpty())
            easy->setObjectName("easy");
        easy->resize(735, 482);
        groupBox = new QGroupBox(easy);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 30, 541, 311));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(12, 51, 93, 29));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(12, 161, 93, 29));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(12, 106, 93, 29));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(130, 50, 93, 29));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(130, 110, 93, 29));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(130, 170, 93, 29));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(250, 50, 93, 29));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(250, 100, 93, 29));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(250, 170, 93, 29));

        retranslateUi(easy);

        QMetaObject::connectSlotsByName(easy);
    } // setupUi

    void retranslateUi(QDialog *easy)
    {
        easy->setWindowTitle(QCoreApplication::translate("easy", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("easy", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("easy", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class easy: public Ui_easy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASY_H
