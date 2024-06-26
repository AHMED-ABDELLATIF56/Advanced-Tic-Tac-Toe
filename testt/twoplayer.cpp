#include "twoplayer.h"
#include "ui_twoplayer.h"
#include <QMessageBox>
#include "database.h"
#include "mainwindow.h"



twoplayer::twoplayer(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::twoplayer),
    username(username),
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
    connectButtons();

    // Player X always starts first
    playerX = true;
}


twoplayer::~twoplayer()
{
    delete ui;
}

void twoplayer::handlePlayerMove(int index)
{
    QPushButton* button = pushButton_array[index];
    if (!button->text().isEmpty()) return; // If the button already has text, do nothing

    button->setText(playerX ? "X" : "O"); // Set 'X' or 'O' based on player's turn
    board[index] = playerX ? 'X' : 'O'; // Update the board state
    playerX = !playerX; // Toggle player turn

    checkGameStatus(); // Check game status after each move
}

void twoplayer::checkGameStatus()
{
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
    // Clear all buttons and reset board and player turn
    for (int i = 0; i < 9; ++i) {
        pushButton_array[i]->setText(""); // Clear text on button
        board[i] = ' '; // Reset board state
    }
    playerX = true; // X starts first

    connectButtons(); // Reconnect button signals
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

    std::vector<std::string> movesVector;
    for (char cell : board) {
        if (cell != ' ') {
            movesVector.push_back(std::string(1, cell));
        } else {
            movesVector.push_back("-");
        }
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
    gameHistory.saveGameHistory(username.toStdString(), "user2", winner.toStdString(), movesVector);
}

