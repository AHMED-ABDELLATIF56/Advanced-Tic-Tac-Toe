/********************************************************************************
** Form generated from reading UI file 'mediumplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIUMPLAYER_H
#define UI_MEDIUMPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mediumPlayer
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QDialog *mediumPlayer)
    {
        if (mediumPlayer->objectName().isEmpty())
            mediumPlayer->setObjectName("mediumPlayer");
        mediumPlayer->resize(762, 547);
        gridLayout = new QGridLayout(mediumPlayer);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(mediumPlayer);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout_2->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_1 = new QPushButton(groupBox);
        pushButton_1->setObjectName("pushButton_1");

        gridLayout_2->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout_2->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout_2->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout_2->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout_2->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout_2->addWidget(pushButton_7, 4, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(mediumPlayer);

        QMetaObject::connectSlotsByName(mediumPlayer);
    } // setupUi

    void retranslateUi(QDialog *mediumPlayer)
    {
        mediumPlayer->setWindowTitle(QCoreApplication::translate("mediumPlayer", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mediumPlayer", "GroupBox", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_1->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("mediumPlayer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediumPlayer: public Ui_mediumPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIUMPLAYER_H
