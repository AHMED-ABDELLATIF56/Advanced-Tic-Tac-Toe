#include "gamehistorydialog.h"
#include "ui_gamehistorydialog.h"
#include "replaygamedialog.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include "database.h"
#include <QStringList> // Include QStringList for split function

GameHistoryDialog::GameHistoryDialog(QWidget *parent, QString username)
    : QDialog(parent)
    , ui(new Ui::GameHistoryDialog)
    , username(username)
    , gameHistory(new GameHistory("game_history.txt"))
{
    ui->setupUi(this);
    setupUIComponents(); // Initialize UI components
    displayHistory(username);    // Display initial game history

    connect(ui->pushButton_replayGame, &QPushButton::clicked, this, &GameHistoryDialog::on_pushButton_replayGame_clicked);
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
        QTableWidgetItem *itemMoves = new QTableWidgetItem(movesToString(record.moves));

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

void GameHistoryDialog::on_pushButton_replayGame_clicked()
{
    // Get the selected row
    int selectedRow = ui->tableWidget_history->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Replay Game", "Please select a game to replay.");
        return;
    }

    // Get the moves from the selected row
    QTableWidgetItem* itemMoves = ui->tableWidget_history->item(selectedRow, 3);
    if (!itemMoves) {
        qDebug() << "No moves found in the selected row";
        return;
    }

    // Extract moves string from QTableWidgetItem
    QString movesString = itemMoves->text();
    qDebug() << "Moves String:" << movesString;

    // Split movesString into individual moves based on commas
    QStringList moveList = movesString.split(',');

    // Convert QStringList to vector of std::string
    std::vector<std::string> moves;
    for (const QString& move : moveList) {
        moves.push_back(move.toStdString());
    }

    // Open the replay game dialog with the selected moves
    ReplayGameDialog replayDialog(this);
    replayDialog.setGameMoves(moves); // Set game moves in the dialog
    replayDialog.exec();
}

