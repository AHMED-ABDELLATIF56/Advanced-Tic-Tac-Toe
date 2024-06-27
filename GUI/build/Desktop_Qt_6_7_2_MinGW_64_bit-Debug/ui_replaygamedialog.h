/********************************************************************************
** Form generated from reading UI file 'replaygamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYGAMEDIALOG_H
#define UI_REPLAYGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplayGameDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_1;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_7;
    QPushButton *pushButton_next;
    QPushButton *pushButton_previous;

    void setupUi(QDialog *ReplayGameDialog)
    {
        if (ReplayGameDialog->objectName().isEmpty())
            ReplayGameDialog->setObjectName("ReplayGameDialog");
        ReplayGameDialog->resize(626, 627);
        gridLayoutWidget = new QWidget(ReplayGameDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(50, 60, 531, 431));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName("label_1");

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 2, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        pushButton_next = new QPushButton(ReplayGameDialog);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(380, 540, 121, 41));
        pushButton_previous = new QPushButton(ReplayGameDialog);
        pushButton_previous->setObjectName("pushButton_previous");
        pushButton_previous->setGeometry(QRect(120, 540, 131, 41));

        retranslateUi(ReplayGameDialog);

        QMetaObject::connectSlotsByName(ReplayGameDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplayGameDialog)
    {
        ReplayGameDialog->setWindowTitle(QCoreApplication::translate("ReplayGameDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("ReplayGameDialog", "TextLabel", nullptr));
        pushButton_next->setText(QCoreApplication::translate("ReplayGameDialog", "next move", nullptr));
        pushButton_previous->setText(QCoreApplication::translate("ReplayGameDialog", "previous move", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplayGameDialog: public Ui_ReplayGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYGAMEDIALOG_H
