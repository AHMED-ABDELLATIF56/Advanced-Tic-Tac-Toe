/********************************************************************************
** Form generated from reading UI file 'ai.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AI_H
#define UI_AI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AI
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_5;
    QPushButton *pushButton_13;

    void setupUi(QDialog *AI)
    {
        if (AI->objectName().isEmpty())
            AI->setObjectName("AI");
        AI->resize(725, 522);
        groupBox = new QGroupBox(AI);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 50, 511, 361));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(300, 130, 80, 80));
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(170, 120, 80, 80));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 120, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(170, 250, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(290, 240, 80, 80));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 240, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(160, 30, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 20, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(290, 40, 80, 80));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);

        retranslateUi(AI);

        QMetaObject::connectSlotsByName(AI);
    } // setupUi

    void retranslateUi(QDialog *AI)
    {
        AI->setWindowTitle(QCoreApplication::translate("AI", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AI", "GroupBox", nullptr));
        pushButton_7->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_8->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("AI", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AI: public Ui_AI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AI_H
