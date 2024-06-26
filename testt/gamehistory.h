/*
#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>
#include <QString>
#include "database.h"

namespace Ui {
class GameHistory;
}

class GameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistory(QWidget *parent = nullptr,const QString& gamehistory_File = "game_history.txt", QString username = "");
    ~GameHistory();

private:
    Ui::GameHistory *ui;
    QString username;

    GameHistory *gameHistory;
    void displayHistory();
};

#endif // GAMEHISTORY_H
*/
