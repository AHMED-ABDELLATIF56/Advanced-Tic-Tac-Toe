#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <vector>

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

class TicTacToe : public QWidget {
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = nullptr);
    void checkWinner();
    void makeMove(int index);

private:
    std::vector<QPushButton*> buttons;
    std::vector<char> board;
    char currentPlayer;
    void resetGame();

private slots:
    void handleButtonClick(int index);
};

#endif // TICTACTOE_H
