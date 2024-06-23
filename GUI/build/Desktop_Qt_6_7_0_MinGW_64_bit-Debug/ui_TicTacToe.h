/********************************************************************************
** Form generated from reading UI file 'TicTacToe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_try
{
public:

    void setupUi(QDialog *try)
    {
        if (try->objectName().isEmpty())
            try->setObjectName("try");
        try->resize(400, 300);

        retranslateUi(try);

        QMetaObject::connectSlotsByName(try);
    } // setupUi

    void retranslateUi(QDialog *try)
    {
        try->setWindowTitle(QCoreApplication::translate("try", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class try: public Ui_try {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
