#include "medium.h"
#include "hard1.h"
#include "ui_medium.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QElapsedTimer>
#include <QDebug>

medium::medium(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::medium),
    username(username),
    playerX(true)
{
    QElapsedTimer timer;
    timer.start();

    ui->setupUi(this);

    // Initialize pushButton_array with UI buttons
    pushButton_array = {
        ui->pushButton, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
        ui->pushButton_7, ui->pushButton_8, ui->pushButton_9
    };

    // Ensure buttons are not null
    for (QPushButton* button : pushButton_array) {
        if (button == nullptr) {
            QMessageBox::critical(this, "Initialization Error", "One or more buttons are not properly initialized.");
            return;
        }
    }

    // Initialize board with empty spaces
    board = QVector<char>(9, ' ');

    // Connect all buttons to handlePlayerMove slot
    for (int i = 0; i < 9; ++i) {
        connect(pushButton_array[i], &QPushButton::clicked, [this, i]() {
            handlePlayerMove(i);
        });
    }

    // Seed the random number generator once
    srand(static_cast<unsigned>(time(nullptr)));

    resetGame(); // Initialize/reset game state

    qint64 initTime = timer.nsecsElapsed();
    qDebug() << "Medium initialization took" << initTime << "nanoseconds";
}

medium::~medium()
{
    delete ui;
}

void medium::handlePlayerMove(int index)
{
    QElapsedTimer timer;
    timer.start();

    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText("X"); // Set 'X' or 'O' based on player's turn
    board[index] = 'X'; // Update the board state
    playerX = !playerX; // Toggle player turn
movesarranged+=QString::number(index);
    checkGameStatus(); // Check game status after each move

    // Check if the game is over
    if (!checkWinner('X') && !checkWinner('O') && !isBoardFull()) {
        aiMove(); // AI move after player's move
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Player move took" << elapsed << "nanoseconds";
}

void medium::aiMove()
{
    QElapsedTimer timer;
    timer.start();

    int bestMove = findBestMove(); // Determine AI's move
    if (bestMove == -1) {
        QMessageBox::critical(this, "Error", "AI cannot find a valid move.");
        return;
    }
    QPushButton* button = pushButton_array[bestMove];
    button->setText("O"); // Set 'X' or 'O' based on AI's turn
    board[bestMove] = 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after AI's move

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "AI move took" << elapsed << "nanoseconds";
}

void medium::checkGameStatus()
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

bool medium::checkWinner(char player)
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

bool medium::isBoardFull()
{
    // Check if the board is full
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

int medium::findBestMove()
{
    QElapsedTimer timer;
    timer.start();

    if (isBoardFull()) {
        return -1; // Board is full, no valid moves
    }

    int index;
    do {
        int chance = rand() % 100; // Random chance between 0 and 99
        if (chance <= 25) {
            index = rand() % 9; // Random move if chance is <= 25
        } else {
            hard1 obj1(this); // Assuming PLAYER_O is opponent symbol
            index = obj1.findBestMove(); // Let AIPlayer make move
        }
    } while (board[index] != ' ');

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Finding best move took" << elapsed << "nanoseconds";
movesarranged+=QString::number(index);
    return index;
}

void medium::resetGame()
{
    QElapsedTimer timer;
    timer.start();

    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text on button
        board[i] = ' '; // Reset board state
    }
    playerX = true; // Assuming X starts first

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Game reset took" << elapsed << "nanoseconds";
}

void medium::saveGameHistory(const QString& username)
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
        winner = "Computer_medium";
    } else {
        winner = "Tie";
    }

    // Use username to save history in a user-specific way
    GameHistory gameHistory("game_history.txt");
    gameHistory.saveGameHistory(username.toStdString(), "Computer_medium", winner.toStdString(), moves);

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Saving game history took" << elapsed << "nanoseconds";
}
