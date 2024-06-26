#include "hard1.h"
#include "ui_hard1.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

hard1::hard1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hard1),
    playerX(true)
{
    ui->setupUi(this);

    // Initialize pushButton_array with UI buttons
    pushButton_array = {
        ui->pushButton, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
        ui->pushButton_7, ui->pushButton_8, ui->pushButton_9
    };

    // Initialize board with empty spaces
    board = QVector<char>(9, ' ');

    // Connect all buttons to handlePlayerMove slot
    for (int i = 0; i < 9; ++i) {
        connect(pushButton_array[i], &QPushButton::clicked, [this, i]() {
            handlePlayerMove(i);
        });
    }

    resetGame(); // Initialize/reset game state
}

hard1::~hard1()
{
    delete ui;
}

void hard1::handlePlayerMove(int index)
{
    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText(playerX ? "X" : "O"); // Set 'X' or 'O' based on player's turn
    board[index] = playerX ? 'X' : 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after each move

    // AI move after player's move
    if (!checkWinner('X') && !checkWinner('O') && !isBoardFull()) {
        aiMove();
    }
}

void hard1::aiMove()
{
    int bestMove = findBestMove(); // Determine AI's move
    QPushButton* button = pushButton_array[bestMove];
    button->setText(playerX ? "X" : "O"); // Set 'X' or 'O' based on AI's turn
    board[bestMove] = playerX ? 'X' : 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after AI's move
}

void hard1::checkGameStatus()
{
    if (checkWinner('X')) {
        QMessageBox::information(this, "Game Over", "Player X wins!");
        resetGame();
    } else if (checkWinner('O')) {
        QMessageBox::information(this, "Game Over", "Player O wins!");
        resetGame();
    } else if (isBoardFull()) {
        QMessageBox::information(this, "Game Over", "It's a tie!");
        resetGame();
    }
}

bool hard1::checkWinner(char player)
{
    // Check all winning conditions
    return (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
        );
}

bool hard1::isBoardFull()
{
    // Check if the board is full
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

int hard1::minimax(char player, int depth, int alpha, int beta, bool maximizingPlayer)
{
    // Base cases: evaluate the score
    if (checkWinner('X')) return -10; // Player X wins
    if (checkWinner('O')) return 10; // Player O wins
    if (isBoardFull()) return 0; // It's a tie

    // Maximizing player (AI, 'O')
    if (maximizingPlayer) {
        int best = -1000;
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = 'O'; // AI makes a move
                best = std::max(best, minimax(player, depth + 1, alpha, beta, false));
                alpha = std::max(alpha, best);
                board[i] = ' '; // Undo move
                if (beta <= alpha)
                    break; // Beta cut-off
            }
        }
        return best;
    }
    // Minimizing player (human, 'X')
    else {
        int best = 1000;
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = 'X'; // Player makes a move
                best = std::min(best, minimax(player, depth + 1, alpha, beta, true));
                beta = std::min(beta, best);
                board[i] = ' '; // Undo move
                if (beta <= alpha)
                    break; // Alpha cut-off
            }
        }
        return best;
    }
}

int hard1::findBestMove()
{
    int bestMove = -1;
    int bestVal = -1000; // Initial value for maximizing player

    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = 'O'; // AI makes a move
            int moveVal = minimax('O', 0, -1000, 1000, false);
            board[i] = ' '; // Undo move

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
}

void hard1::resetGame()
{
    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text on button
        board[i] = ' '; // Reset board state
    }
    playerX = true; // Assuming X starts first
}
