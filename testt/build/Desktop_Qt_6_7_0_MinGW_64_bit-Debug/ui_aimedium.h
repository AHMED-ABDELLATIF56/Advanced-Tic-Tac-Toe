/********************************************************************************
** Form generated from reading UI file 'aimedium.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIMEDIUM_H
#define UI_AIMEDIUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AImedium
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QDialog *AImedium)
    {
        if (AImedium->objectName().isEmpty())
            AImedium->setObjectName("AImedium");
        AImedium->resize(731, 446);
        groupBox = new QGroupBox(AImedium);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(120, 70, 511, 281));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);


        retranslateUi(AImedium);

        QMetaObject::connectSlotsByName(AImedium);
    } // setupUi

    void retranslateUi(QDialog *AImedium)
    {
        AImedium->setWindowTitle(QCoreApplication::translate("AImedium", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AImedium", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("AImedium", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AImedium: public Ui_AImedium {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIMEDIUM_H
