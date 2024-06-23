#ifndef HARD_H
#define HARD_H

#include <QVector>
#include "GameBoard.h" // Assuming GameBoard class is defined here

class hard
{
public:
    hard(char symbol, GameBoard *gameBoard);
    int makeMove();

private:
    char m_playerSymbol;
    char m_opponentSymbol;
    GameBoard *m_gameBoard;

    int minimax(const QVector<char> &board, bool isMaximizing, int depth);
    bool checkWinner(char player, const QVector<char> &board); // Declaration of checkWinner
    bool isBoardFull(const QVector<char> &board);              // Declaration of isBoardFull
};

#endif // HARD_H
