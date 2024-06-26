/********************************************************************************
** Form generated from reading UI file 'gamehistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHISTORYDIALOG_H
#define UI_GAMEHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_GameHistoryDialog
{
public:
    QTableWidget *tableWidget_history;
    QPushButton *pushButton_replayGame;

    void setupUi(QDialog *GameHistoryDialog)
    {
        if (GameHistoryDialog->objectName().isEmpty())
            GameHistoryDialog->setObjectName("GameHistoryDialog");
        GameHistoryDialog->resize(729, 614);
        tableWidget_history = new QTableWidget(GameHistoryDialog);
        if (tableWidget_history->columnCount() < 3)
            tableWidget_history->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_history->rowCount() < 100)
            tableWidget_history->setRowCount(100);
        tableWidget_history->setObjectName("tableWidget_history");
        tableWidget_history->setGeometry(QRect(140, 20, 441, 471));
        tableWidget_history->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_history->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_history->setRowCount(100);
        tableWidget_history->setColumnCount(3);
        tableWidget_history->horizontalHeader()->setVisible(true);
        tableWidget_history->horizontalHeader()->setCascadingSectionResizes(false);
        pushButton_replayGame = new QPushButton(GameHistoryDialog);
        pushButton_replayGame->setObjectName("pushButton_replayGame");
        pushButton_replayGame->setGeometry(QRect(270, 520, 171, 41));

        retranslateUi(GameHistoryDialog);

        QMetaObject::connectSlotsByName(GameHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *GameHistoryDialog)
    {
        GameHistoryDialog->setWindowTitle(QCoreApplication::translate("GameHistoryDialog", "Game history", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_history->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GameHistoryDialog", "first player", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_history->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GameHistoryDialog", "second player", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_history->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GameHistoryDialog", "winner", nullptr));
        pushButton_replayGame->setText(QCoreApplication::translate("GameHistoryDialog", "show final board", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameHistoryDialog: public Ui_GameHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHISTORYDIALOG_H
