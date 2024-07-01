#include "aihard.h"
#include "ui_aihard.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QElapsedTimer>
#include <QDebug>
#include "database.h"

aihard::aihard(QWidget *parent, QString username)
    : QDialog(parent),
    ui(new Ui::aihard),
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

    // Initialize board with empty spaces
    board = QVector<char>(9, ' ');

    // Connect all buttons to handlePlayerMove slot
    for (int i = 0; i < 9; ++i) {
        connect(pushButton_array[i], &QPushButton::clicked, [this, i]() {
            handlePlayerMove(i);
        });
        pushButton_array[i]->setStyleSheet("font-size: 24px; border: 1px solid black;");
    }

    // Connect all buttons to handlePlayerMove slot
    connectButtons(); // Connect button signals

    // Player always starts first


    qint64 initTime = timer.nsecsElapsed();
    qDebug() << "AIHard initialization took" << initTime << "nanoseconds";
}

aihard::~aihard()
{
    delete ui;
}

void aihard::handlePlayerMove(int index)
{
    QElapsedTimer timer;
    timer.start();

    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText("X"); // Set 'X' or 'O' based on player's turn
    button->setStyleSheet("color: blue; font-size: 24px; border: 1px solid black;"); // Set color to blue for player
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

void aihard::aiMove()
{
    QElapsedTimer timer;
    timer.start();

    int bestMove = findBestMove(); // Determine AI's move
    QPushButton* button = pushButton_array[bestMove];
    button->setText("O"); // Set 'X' or 'O' based on AI's turn
    button->setStyleSheet("color: red; font-size: 24px; border: 1px solid black;"); // Set color to red for AI
    board[bestMove] = 'O'; // Update the board state

    checkGameStatus(); // Check game status after AI's move

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "AI move took" << elapsed << "nanoseconds";
}

void aihard::checkGameStatus()
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

bool aihard::checkWinner(char player)
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

bool aihard::isBoardFull()
{
    // Check if the board is full
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

int aihard::findBestMove()
{
    // Simulate AI's move (simple random move for demo)
    srand(time(nullptr)); // Initialize random seed

    int index;
    do {
        index = rand() % 9; // Generate random index (0-8)
    } while (board[index] != ' '); // Keep generating if the cell is not empty
    movesarranged+=QString::number(index);
    return index;
}

void aihard::resetGame()
{
    QElapsedTimer timer;
    timer.start();

    disconnectButtons(); // Disconnect button signals

    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text on button
        board[i] = ' '; // Reset board state
    }
    playerX = true; // Assuming X starts first

    connectButtons(); // Reconnect button signals

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Game reset took" << elapsed << "nanoseconds";
}

void aihard::connectButtons()
{
    for (int i = 0; i < 9; ++i) {
        connect(pushButton_array[i], &QPushButton::clicked, [this, i]() {
            handlePlayerMove(i);
        });
    }
}

void aihard::disconnectButtons()
{
    for (int i = 0; i < 9; ++i) {
        disconnect(pushButton_array[i], &QPushButton::clicked, nullptr, nullptr);
    }
}

void aihard::saveGameHistory(const QString& username)
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
        winner = "Computer_easy";
    } else {
        winner = "Tie";
    }

    // Use username to save history in a user-specific way
    GameHistory gameHistory("game_history.txt");
    gameHistory.saveGameHistory(username.toStdString(), "Computer_easy", winner.toStdString(), moves);

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Saving game history took" << elapsed << "nanoseconds";
}
