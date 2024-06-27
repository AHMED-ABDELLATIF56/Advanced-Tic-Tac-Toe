#ifndef AIHARD_H
#define AIHARD_H

#include <QDialog>
#include <QVector>
#include <QPushButton>
#include "database.h"

namespace Ui {
class aihard;
}

class aihard : public QDialog
{
    Q_OBJECT
    friend class test ;
public:
    explicit aihard(QWidget *parent = nullptr,QString username = "");
    ~aihard();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int findBestMove();
    void resetGame();
    void saveGameHistory(const QString& username);


private:
    Ui::aihard *ui;
     QString username;

    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX;

    void connectButtons();
    void disconnectButtons();
    Database *database;
};

#endif // AIHARD_H


