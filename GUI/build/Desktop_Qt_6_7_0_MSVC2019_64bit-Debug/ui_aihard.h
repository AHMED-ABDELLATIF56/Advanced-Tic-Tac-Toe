/********************************************************************************
** Form generated from reading UI file 'aihard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIHARD_H
#define UI_AIHARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aihard
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

    void setupUi(QDialog *aihard)
    {
        if (aihard->objectName().isEmpty())
            aihard->setObjectName("aihard");
        aihard->resize(721, 542);
        groupBox = new QGroupBox(aihard);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(140, 90, 241, 221));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 40, 71, 51));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 40, 71, 51));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(150, 40, 71, 51));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 90, 71, 51));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(80, 90, 71, 51));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(150, 90, 71, 51));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 140, 71, 51));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(80, 140, 71, 51));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(150, 140, 71, 51));

        retranslateUi(aihard);

        QMetaObject::connectSlotsByName(aihard);
    } // setupUi

    void retranslateUi(QDialog *aihard)
    {
        aihard->setWindowTitle(QCoreApplication::translate("aihard", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("aihard", "AI_Easy", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class aihard: public Ui_aihard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIHARD_H
