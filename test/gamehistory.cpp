// gamehistory.cpp
#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <QDebug>

GameHistory::GameHistory(const std::string& gameHistoryFile)
    : gameHistoryFile(gameHistoryFile)
{
    std::filesystem::path filePath(gameHistoryFile);

    // Check if the file exists
    if (!std::filesystem::exists(filePath)) {
        std::cout << "Game history file does not exist. Initializing...\n";

        // Create the file if it doesn't exist
        std::ofstream file(filePath, std::ios::out);
        if (!file.is_open()) {
            std::cerr << "Error creating file: " << gameHistoryFile << std::endl;
            // Handle error (throw exception, log, etc.)
        } else {
            std::cout << "Successfully created file: " << gameHistoryFile << std::endl;
            file.close(); // Close the file after creation
        }
    } else {
        std::cout << "Game history file already exists.\n";
    }
}

void GameHistory::saveGameHistory(const std::string& player1, const std::string& player2, const std::string& winner, const std::vector<std::string>& moves)
{
    std::ofstream file(gameHistoryFile, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << gameHistoryFile << std::endl;
        return;
    }

    // Format: player1:player2:winner:move1,move2,move3,...
    file << player1 << ":" << player2 << ":" << winner << ":";
    for (size_t i = 0; i < moves.size(); ++i) {
        file << moves[i];
        if (i != moves.size() - 1) {
            file << ",";
        }
    }
    file << std::endl;
    file.close();
}

std::vector<GameRecord> GameHistory::parseGameHistory() {
    std::vector<GameRecord> gameRecords;
    std::ifstream file(gameHistoryFile);
    if (!file.is_open()) {
        qDebug() << "Error opening file: " << QString::fromStdString(gameHistoryFile);
        return gameRecords;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string player1, player2, winner, moves_str;

        std::getline(ss, player1, ':');
        std::getline(ss, player2, ':');
        std::getline(ss, winner, ':');
        std::getline(ss, moves_str);

        std::stringstream moves_ss(moves_str);
        std::vector<std::string> moves;
        std::string move;
        while (std::getline(moves_ss, move, ',')) {
            moves.push_back(move);
        }

        gameRecords.push_back({player1, player2, winner, moves});
    }

    file.close();

  /*  // Debug: Print parsed data
    for (const auto& record : gameRecords) {
        qDebug() << "Parsed Record:" << QString::fromStdString(record.player1) << ","
                 << QString::fromStdString(record.player2) << ","
                 << QString::fromStdString(record.winner) << ", Moves:"
                 << movesToString(record.moves);
    }*/

    return gameRecords;
}
void GameHistory::viewGameHistory(const std::string& username)
{
    std::vector<GameRecord> gameHistory = parseGameHistory();

    if (gameHistory.empty()) {
        std::cout << "No game history found.\n";
        return;
    }

    std::cout << "Game History for " << username << ":\n";
    int gameCount = 0;
    for (const auto& record : gameHistory) {
        if (record.player1 == username || record.player2 == username) {
            ++gameCount;
            std::cout << gameCount << ". Player 1: " << record.player1
                      << ", Player 2: " << record.player2
                      << ", Winner: " << record.winner << std::endl;
        }
    }

    if (gameCount == 0) {
        std::cout << "No games found for " << username << ".\n";
        return;
    }

    std::cout << "Enter the number of the game you want to review (1-" << gameCount << "): ";
    int reviewChoice;
    std::cin >> reviewChoice;

    if (reviewChoice < 1 || reviewChoice > gameCount) {
        std::cout << "Invalid game number. Exiting.\n";
        return;
    }

    std::cout << "Reviewing Game " << reviewChoice << ":\n";
    displayBoard(gameHistory[reviewChoice - 1].moves);
}

void GameHistory::displayBoard(const std::vector<std::string>& moves)
{
    std::vector<char> board(9, ' ');
    for (size_t i = 0; i < moves.size(); ++i) {
        int move = std::stoi(moves[i]);
        char playerSymbol = (i % 2 == 0) ? 'X' : 'O';
        board[move] = playerSymbol;
    }

    std::cout << "-------------\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "|\n";
            std::cout << "-------------\n";
        }
    }
}
