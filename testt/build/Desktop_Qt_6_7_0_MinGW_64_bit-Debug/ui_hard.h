/********************************************************************************
** Form generated from reading UI file 'hard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARD_H
#define UI_HARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_hard
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;

    void setupUi(QDialog *hard)
    {
        if (hard->objectName().isEmpty())
            hard->setObjectName("hard");
        hard->resize(821, 619);
        groupBox = new QGroupBox(hard);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 100, 641, 481));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 4, 3, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 2);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 2);


        retranslateUi(hard);

        QMetaObject::connectSlotsByName(hard);
    } // setupUi

    void retranslateUi(QDialog *hard)
    {
        hard->setWindowTitle(QCoreApplication::translate("hard", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("hard", "GroupBox", nullptr));
        pushButton_7->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("hard", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hard: public Ui_hard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARD_H
