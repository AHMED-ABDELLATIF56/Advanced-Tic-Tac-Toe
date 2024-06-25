#include "gamehistory.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

GameHistory::GameHistory(const QString& gameHistoryFile, QObject *parent)
    : QObject(parent), gameHistoryFile(gameHistoryFile) {
    // Constructor initializes with files
}

void GameHistory::saveGameHistory( const QString& winner, const QString& moves) {
    QFile file(gameHistoryFile);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open game history file for writing.";
        return;
    }

    QTextStream out(&file);
    out <<  winner << ":" << moves << '\n';
    file.close();
}

QVector<GameRecord> GameHistory::parseGameHistory() {
    QVector<GameRecord> gameRecords;
    QFile file(gameHistoryFile);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open game history file for reading.";
        return gameRecords;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.length() == 4) {
            QString player1 = parts[0];
            QString player2 = parts[1];
            QString winner = parts[2];
            QStringList moves_list = parts[3].split(',');

            QVector<QString> moves = moves_list.toVector();
            gameRecords.append({player1, player2, winner, moves});
        }
    }

    file.close();
    return gameRecords;
}

QVector<GameRecord> GameHistory::viewGameHistory(const QString& username) {
    QVector<GameRecord> gameHistory = parseGameHistory();
    QVector<GameRecord> userGameHistory;

    for (const auto& game : gameHistory) {
        if (game.player1 == username || game.player2 == username) {
            userGameHistory.append(game);
        }
    }

    return userGameHistory;
}

void GameHistory::displayBoard(const QVector<QString>& moves) {
    QVector<char> board(9, ' ');

    for (int i = 0; i < moves.size(); ++i) {
        char playerSymbol = (i % 2 == 0) ? 'X' : 'O';
        board[moves[i].toInt()] = playerSymbol;
    }

    qDebug() << "-------------";
    for (int i = 0; i < 9; ++i) {
        qDebug() << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            qDebug() << "|";
            qDebug() << "-------------";
        }
    }
}
