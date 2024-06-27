#ifndef HARD1_H
#define HARD1_H

#include <QDialog>
#include <QPushButton>
#include <QVector>
#include "database.h"

namespace Ui {
class hard1;
}

class hard1 : public QDialog
{
    Q_OBJECT

public:
    explicit hard1(QWidget *parent = nullptr,QString username = "");
    ~hard1();
    int findBestMove();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int minimax(char player, int depth, int alpha, int beta, bool maximizingPlayer);
    void resetGame(); // Declaration of resetGame function
    void saveGameHistory(const QString& username);
private:
    Ui::hard1 *ui;
     QString username;
    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX; // true for Player X, false for Player O
    QString movesarranged;
    Database *database;
};

#endif // HARD1_H
