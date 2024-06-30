/********************************************************************************
** Form generated from reading UI file 'playermakemove.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERMAKEMOVE_H
#define UI_PLAYERMAKEMOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_playerMakeMove
{
public:

    void setupUi(QDialog *playerMakeMove)
    {
        if (playerMakeMove->objectName().isEmpty())
            playerMakeMove->setObjectName("playerMakeMove");
        playerMakeMove->resize(400, 300);

        retranslateUi(playerMakeMove);

        QMetaObject::connectSlotsByName(playerMakeMove);
    } // setupUi

    void retranslateUi(QDialog *playerMakeMove)
    {
        playerMakeMove->setWindowTitle(QCoreApplication::translate("playerMakeMove", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playerMakeMove: public Ui_playerMakeMove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERMAKEMOVE_H
