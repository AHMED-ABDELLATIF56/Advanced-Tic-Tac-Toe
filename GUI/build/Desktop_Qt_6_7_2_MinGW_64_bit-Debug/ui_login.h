/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_AI_easy;
    QPushButton *pushButton_AI_medium;
    QPushButton *pushButton_AI_hard;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton_two_player;
    QPushButton *pushButton_history;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName("Dialog1");
        Dialog1->resize(412, 334);
        label = new QLabel(Dialog1);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 191, 20));
        layoutWidget = new QWidget(Dialog1);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(180, 40, 95, 103));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_AI_easy = new QPushButton(layoutWidget);
        pushButton_AI_easy->setObjectName("pushButton_AI_easy");

        verticalLayout->addWidget(pushButton_AI_easy);

        pushButton_AI_medium = new QPushButton(layoutWidget);
        pushButton_AI_medium->setObjectName("pushButton_AI_medium");

        verticalLayout->addWidget(pushButton_AI_medium);

        pushButton_AI_hard = new QPushButton(layoutWidget);
        pushButton_AI_hard->setObjectName("pushButton_AI_hard");

        verticalLayout->addWidget(pushButton_AI_hard);

        layoutWidget1 = new QWidget(Dialog1);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 170, 311, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        pushButton_two_player = new QPushButton(layoutWidget1);
        pushButton_two_player->setObjectName("pushButton_two_player");

        horizontalLayout->addWidget(pushButton_two_player);

        pushButton_history = new QPushButton(Dialog1);
        pushButton_history->setObjectName("pushButton_history");
        pushButton_history->setGeometry(QRect(150, 240, 93, 29));

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QCoreApplication::translate("Dialog1", "Choose mode", nullptr));
        label->setText(QCoreApplication::translate("Dialog1", "Against AI", nullptr));
        pushButton_AI_easy->setText(QCoreApplication::translate("Dialog1", "easy", nullptr));
        pushButton_AI_medium->setText(QCoreApplication::translate("Dialog1", "medium", nullptr));
        pushButton_AI_hard->setText(QCoreApplication::translate("Dialog1", "hard", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog1", "Two players", nullptr));
        pushButton_two_player->setText(QCoreApplication::translate("Dialog1", "click", nullptr));
        pushButton_history->setText(QCoreApplication::translate("Dialog1", "view history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
