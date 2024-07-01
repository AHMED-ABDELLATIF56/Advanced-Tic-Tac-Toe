#include "hard1.h"
#include "gamehistorydialog.h"
#include "ui_hard1.h"
#include "database.h"
#include "gamehistory.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <string>
#include <QElapsedTimer>
#include <QDebug>

hard1::hard1(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::hard1),
    username(username),
    playerX(true)
{
    QElapsedTimer timer;
    timer.start();

    ui->setupUi(this);

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
        pushButton_array[i]->setStyleSheet("font-size: 24px; border: 1px solid black;");
    }

    resetGame(); // Initialize/reset game state

    qint64 initTime = timer.nsecsElapsed();
    qDebug() << "Hard1 initialization took" << initTime << "nanoseconds";
}

hard1::~hard1()
{
    delete ui;
}

void hard1::handlePlayerMove(int index)
{
    QElapsedTimer timer;

    timer.start();

    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText("X"); // Set 'X' or 'O' based on player's turn
    button->setStyleSheet("color: blue; font-size: 24px; border: 1px solid black;"); // Set color to blue for player
    board[index] = 'X'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after each move
    movesarranged += QString::number(index);

    // AI move after player's move
    if (!checkWinner('X') && !checkWinner('O') && !isBoardFull()) {
        aiMove();
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Player move took" << elapsed << "nanoseconds";
}

void hard1::aiMove()
{
    QElapsedTimer timer;
    timer.start();

    int bestMove = findBestMove(); // Determine AI's move
    QPushButton* button = pushButton_array[bestMove];
    button->setText("O"); // Set 'X' or 'O' based on AI's turn
    button->setStyleSheet("color: red; font-size: 24px; border: 1px solid black;"); // Set color to red for AI
    board[bestMove] = 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after AI's move

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "AI move took" << elapsed << "nanoseconds";
}

void hard1::checkGameStatus()
{
    QElapsedTimer timer;
    timer.start();

    if (checkWinner('X')) {
        QMessageBox::information(this, "Game Over", "Player X wins!");
        saveGameHistory(username); // Save game history
        resetGame();
    } else if (checkWinner('O')) {
        QMessageBox::information(this, "Game Over", "Player O wins!");
        saveGameHistory(username); // Save game history
        resetGame();
    } else if (isBoardFull()) {
        QMessageBox::information(this, "Game Over", "It's a tie!");
        saveGameHistory(username); // Save game history
        resetGame();
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Game status check took" << elapsed << "nanoseconds";
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
    QElapsedTimer timer;
    timer.start();

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
    movesarranged += QString::number(bestMove);

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Finding best move took" << elapsed << "nanoseconds";

    return bestMove;
}

void hard1::resetGame()
{
    QElapsedTimer timer;
    timer.start();

    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text
        pushButton_array[i]->setStyleSheet("font-size: 24px; border: 1px solid black;"); // Reset button style
        board[i] = ' '; // Reset board state
    }
    playerX = true; // Assuming X starts first

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Game reset took" << elapsed << "nanoseconds";
}

void hard1::saveGameHistory(const QString& username)
{
    QElapsedTimer timer;
    timer.start();

    std::vector<std::string> moves;

    for (const QString& move : movesarranged) {
        moves.push_back(move.toStdString());
    }


    QString winner;
    if (checkWinner('X')) {
        winner = username;
    } else if (checkWinner('O')) {
        winner = "Computer_hard";
    } else {
        winner = "Tie";
    }

    // Use username to save history in a user-specific way
    GameHistory gameHistory("game_history.txt");
    gameHistory.saveGameHistory(username.toStdString(), "Computer_hard", winner.toStdString(), moves);

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Saving game history took" << elapsed << "nanoseconds";
}
