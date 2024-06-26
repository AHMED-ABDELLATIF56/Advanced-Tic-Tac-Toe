// gamehistorydialog.cpp
#include "gamehistorydialog.h"
#include "ui_gamehistorydialog.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include "database.h"

GameHistoryDialog::GameHistoryDialog(QWidget *parent, QString username)
    : QDialog(parent)
    , ui(new Ui::GameHistoryDialog)
    , username(username)
    , gameHistory(new GameHistory("game_history.txt"))
{
    ui->setupUi(this);
    setupUIComponents(); // Initialize UI components
    displayHistory(username);    // Display initial game history
}

GameHistoryDialog::~GameHistoryDialog()
{
    delete ui;
    delete gameHistory;
}

void GameHistoryDialog::setupUIComponents()
{
    // Set up the table widget for displaying game history
    ui->tableWidget_history->setColumnCount(4); // Assuming 4 columns: Player 1, Player 2, Winner, Moves
    QStringList headers = {"Player 1", "Player 2", "Winner", "Moves"};
    ui->tableWidget_history->setHorizontalHeaderLabels(headers);

}

void GameHistoryDialog::displayHistory(const QString& username) {
    std::vector<GameRecord> gameRecords = gameHistory->parseGameHistory();
    if (gameRecords.empty()) {
        QMessageBox::information(this, "Game History", "No game history found.");
        return;
    }

    // Clear previous data in the table widget
    ui->tableWidget_history->clearContents();

    // Filter game records to include only those where player1 matches the current username
    std::vector<GameRecord> filteredRecords;
    for (const auto& record : gameRecords) {
        if (record.player1 == username.toStdString()) {
            filteredRecords.push_back(record);
        }
    }

    if (filteredRecords.empty()) {
        QMessageBox::information(this, "Game History", "No game history found for the current user.");
        return;
    }

    // Set row count to the number of filtered records
    ui->tableWidget_history->setRowCount(filteredRecords.size());

    // Display filtered records
    int row = 0;
    for (const auto& record : filteredRecords) {
        QTableWidgetItem *itemPlayer1 = new QTableWidgetItem(QString::fromStdString(record.player1));
        QTableWidgetItem *itemPlayer2 = new QTableWidgetItem(QString::fromStdString(record.player2));
        QTableWidgetItem *itemWinner = new QTableWidgetItem(QString::fromStdString(record.winner));
        QTableWidgetItem *itemMoves = new QTableWidgetItem(GameHistoryDialog::movesToString(record.moves));

        ui->tableWidget_history->setItem(row, 0, itemPlayer1);
        ui->tableWidget_history->setItem(row, 1, itemPlayer2);
        ui->tableWidget_history->setItem(row, 2, itemWinner);
        ui->tableWidget_history->setItem(row, 3, itemMoves);

        row++;
    }
}


void GameHistoryDialog::on_pushButton_viewHistory_clicked()
{
    displayHistory(username);
}

QString GameHistoryDialog::movesToString(const std::vector<std::string>& moves) {
    QString result;
    for (const std::string& move : moves) {
        result += QString::fromStdString(move) + ","; // Convert std::string to QString and concatenate
    }
    // Remove the last comma if needed
    if (!result.isEmpty()) {
        result.chop(1); // Remove the last character (comma)
    }
    return result;
}
