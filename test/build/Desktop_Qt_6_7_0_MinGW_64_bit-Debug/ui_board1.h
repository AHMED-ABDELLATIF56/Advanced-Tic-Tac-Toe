/********************************************************************************
** Form generated from reading UI file 'board1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD1_H
#define UI_BOARD1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board1
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;

    void setupUi(QDialog *board1)
    {
        if (board1->objectName().isEmpty())
            board1->setObjectName("board1");
        board1->resize(981, 674);
        groupBox = new QGroupBox(board1);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(160, 100, 591, 441));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(40, 40, 521, 361));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(layoutWidget_2);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout_2->addWidget(pushButton_10, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget_2);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout_2->addWidget(pushButton_11, 0, 2, 1, 1);

        pushButton_12 = new QPushButton(layoutWidget_2);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout_2->addWidget(pushButton_12, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(layoutWidget_2);
        pushButton_13->setObjectName("pushButton_13");

        gridLayout_2->addWidget(pushButton_13, 0, 1, 1, 1);

        pushButton_14 = new QPushButton(layoutWidget_2);
        pushButton_14->setObjectName("pushButton_14");

        gridLayout_2->addWidget(pushButton_14, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(layoutWidget_2);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout_2->addWidget(pushButton_15, 1, 1, 1, 1);

        pushButton_16 = new QPushButton(layoutWidget_2);
        pushButton_16->setObjectName("pushButton_16");

        gridLayout_2->addWidget(pushButton_16, 2, 1, 1, 1);

        pushButton_17 = new QPushButton(layoutWidget_2);
        pushButton_17->setObjectName("pushButton_17");

        gridLayout_2->addWidget(pushButton_17, 2, 2, 1, 1);

        pushButton_18 = new QPushButton(layoutWidget_2);
        pushButton_18->setObjectName("pushButton_18");

        gridLayout_2->addWidget(pushButton_18, 2, 0, 1, 1);


        retranslateUi(board1);

        QMetaObject::connectSlotsByName(board1);
    } // setupUi

    void retranslateUi(QDialog *board1)
    {
        board1->setWindowTitle(QCoreApplication::translate("board1", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("board1", "GroupBox", nullptr));
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
        pushButton_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class board1: public Ui_board1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD1_H
