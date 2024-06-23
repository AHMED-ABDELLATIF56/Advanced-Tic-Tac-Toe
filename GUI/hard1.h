#ifndef HARD1_H
#define HARD1_H

#include <QDialog>
#include <QPushButton>
#include <QVector>

namespace Ui {
class hard1;
}

class hard1 : public QDialog
{
    Q_OBJECT

public:
    explicit hard1(QWidget *parent = nullptr);
    ~hard1();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int minimax(char player, int depth, int alpha, int beta, bool maximizingPlayer);
    int findBestMove();
    void resetGame(); // Declaration of resetGame function

private:
    Ui::hard1 *ui;
    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX; // true for Player X, false for Player O
};

#endif // HARD1_H
