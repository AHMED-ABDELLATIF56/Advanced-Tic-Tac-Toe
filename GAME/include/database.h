//
// Created by Ahmed on 6/23/2024.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the GameRecord structure
struct GameRecord {
    string player1;
    string player2;
    string winner;
    vector<string> moves; // Store moves as strings
};

class Database {
private:
    std::unordered_map<std::string, std::string> loadUsers();
    void saveUser(const std::string& username, const std::string& password);

public:
    Database(const std::string& usersFile, const std::string& gameHistoryFile);

    void saveGameHistory(const std::string& player1, const std::string& player2, const std::string& winner, const std::string& moves);
    bool signUp();
    bool signIn(std::string& username);
    std::vector<GameRecord> parseGameHistory();
    void viewGameHistory(const std::string& username);
    void displayBoard(const std::vector<std::string>& moves);

private:
    std::string usersFile;
    std::string gameHistoryFile;
};

#endif //DATABASE_H
