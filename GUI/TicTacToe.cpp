#include "tictactoe.h"
#include <QMessageBox>
#include <QGridLayout>

TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent), board(9, EMPTY), currentPlayer(PLAYER_X) {
    QGridLayout *layout = new QGridLayout(this);

    for (int i = 0; i < 9; ++i) {
        QPushButton *button = new QPushButton(" ");
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        buttons.push_back(button);
        layout->addWidget(button, i / 3, i % 3);
        connect(button, &QPushButton::clicked, [this, i]() { handleButtonClick(i); });
    }

    setLayout(layout);
    setWindowTitle("Tic Tac Toe");
}

void TicTacToe::makeMove(int index) {
    if (board[index] == EMPTY) {
        board[index] = currentPlayer;
        buttons[index]->setText(currentPlayer == PLAYER_X ? "X" : "O");
        checkWinner();
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

void TicTacToe::handleButtonClick(int index) {
    makeMove(index);
}

void TicTacToe::checkWinner() {
    const std::vector<std::vector<int>> WINNING_COMBOS = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (const auto& combo : WINNING_COMBOS) {
        if (board[combo[0]] != EMPTY && board[combo[0]] == board[combo[1]] && board[combo[1]] == board[combo[2]]) {
            QMessageBox::information(this, "Game Over", QString("Player %1 wins!").arg(board[combo[0]]));
            resetGame();
            return;
        }
    }

    bool tie = true;
    for (const auto& cell : board) {
        if (cell == EMPTY) {
            tie = false;
            break;
        }
    }

    if (tie) {
        QMessageBox::information(this, "Game Over", "It's a tie!");
        resetGame();
    }
}

void TicTacToe::resetGame() {
    board = std::vector<char>(9, EMPTY);
    currentPlayer = PLAYER_X;
    for (auto& button : buttons) {
        button->setText(" ");
    }
}


