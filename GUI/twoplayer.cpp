#include "twoplayer.h"
#include "ui_twoplayer.h"
#include <QMessageBox>
#include "database.h"
#include "mainwindow.h"
#include <QElapsedTimer>
#include <QDebug>

twoplayer::twoplayer(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::twoplayer),
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
    connectButtons();

    // Player X always starts first
    playerX = true;

    qint64 initTime = timer.nsecsElapsed();
    qDebug() << "TwoPlayer initialization took" << initTime << "nanoseconds";
}

twoplayer::~twoplayer()
{
    delete ui;
}

void twoplayer::handlePlayerMove(int index)
{
    QElapsedTimer timer;
    timer.start();

    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText(playerX ? "X" : "O"); // Set 'X' or 'O' based on player's turn
    board[index] = playerX ? 'X' : 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn
    button->setStyleSheet(playerX ? "color: blue; font-size: 24px; border: 1px solid black;":
                         "color: red; font-size: 24px; border: 1px solid black;" ); // Set color to blue for player
    checkGameStatus(); // Check game status after each move
movesarranged+=QString::number(index);
    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Player move took" << elapsed << "nanoseconds";
}

void twoplayer::checkGameStatus()
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

bool twoplayer::checkWinner(char player)
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

bool twoplayer::isBoardFull()
{
    // Check if the board is full
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

void twoplayer::resetGame()
{
    QElapsedTimer timer;
    timer.start();

    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text on button
        board[i] = ' '; // Reset board state
    }
    playerX = true; // X starts first

    connectButtons(); // Reconnect button signals

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Game reset took" << elapsed << "nanoseconds";
}

void twoplayer::connectButtons()
{
    for (int i = 0; i < 9; ++i) {
        connect(pushButton_array[i], &QPushButton::clicked, [this, i]() {
            handlePlayerMove(i);
        });
    }
}

void twoplayer::disconnectButtons()
{
    for (int i = 0; i < 9; ++i) {
        disconnect(pushButton_array[i], &QPushButton::clicked, nullptr, nullptr);
    }
}

void twoplayer::saveGameHistory(const QString& username)
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
        winner = "user2";
    } else {
        winner = "Tie";
    }

    // Use username to save history in a user-specific way
    GameHistory gameHistory("game_history.txt");
    gameHistory.saveGameHistory(username.toStdString(), "user2", winner.toStdString(), moves);

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Saving game history took" << elapsed << "nanoseconds";
}
