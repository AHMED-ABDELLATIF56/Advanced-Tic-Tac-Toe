//
// Created by Ahmed on 6/23/2024.
//

#include "../include/database.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Database::Database(const string& usersFile)
    : usersFile(usersFile) {
    // Constructor initializes with files
}

unordered_map<string, string> Database::loadUsers() {
    unordered_map<string, string> users;
    ifstream file(usersFile);
    string line;

    while (getline(file, line)) {
        size_t delimiterPos = line.find(":");
        string username = line.substr(0, delimiterPos);
        string password = line.substr(delimiterPos + 1);
        users[username] = password;
    }

    file.close();
    return users;
}

void Database::saveUser(const string& username, const string& password) {
    ofstream file(usersFile, ios::app);
    file << username << ":" << password << endl;
    file.close();
}

bool Database::signUp() {
    unordered_map<string, string> users = loadUsers();
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose another one.\n";
        return false;
    }

    cout << "Enter password: ";
    cin >> password;

    saveUser(username, password);
    cout << "Sign up successful!\n";
    return true;
}

bool Database::signIn(string& username) {
    unordered_map<string, string> users = loadUsers();
    string password;

    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) == users.end()) {
        cout << "Username not found.\n";
        return false;
    }

    cout << "Enter password: ";
    cin >> password;

    if (users[username] == password) {
        cout << "Sign in successful!\n";
        return true;
    } else {
        cout << "Incorrect password.\n";
        return false;
    }
}

//===========================================================================================

GameHistory::GameHistory(const string& gameHistoryFile)
    : gameHistoryFile(gameHistoryFile) {
    // Constructor initializes with files
}

void GameHistory::saveGameHistory(const string& player1, const string& player2, const string& winner, const string& moves) {
    ofstream file(gameHistoryFile, ios::app);
    file << player1 << ":" << player2 << ":" << winner << ":" << moves << endl;
    file.close();
}

vector<GameRecord> GameHistory::parseGameHistory() {
    vector<GameRecord> gameRecords;
    ifstream file(gameHistoryFile);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string player1, player2, winner, moves_str;

        getline(ss, player1, ':');
        getline(ss, player2, ':');
        getline(ss, winner, ':');
        getline(ss, moves_str);

        stringstream moves_ss(moves_str);
        vector<string> moves;
        string move;
        while (getline(moves_ss, move, ',')) {
            moves.push_back(move);
        }

        gameRecords.push_back({player1, player2, winner, moves});
    }

    file.close();
    return gameRecords;
}

void GameHistory::viewGameHistory(const string& username) {
    vector<GameRecord> gameHistory = parseGameHistory();

    if (gameHistory.empty()) {
        cout << "No game history found.\n";
        return;
    }

    cout << "Game History for " << username << ":\n";
    int gameCount = 0;
    for (int i = 0; i < gameHistory.size(); ++i) {
        if (gameHistory[i].player1 == username || gameHistory[i].player2 == username) {
            ++gameCount;
            cout << gameCount << ". Player 1: " << gameHistory[i].player1
                      << ", Player 2: " << gameHistory[i].player2
                      << ", Winner: " << gameHistory[i].winner << endl;
        }
    }

    if (gameCount == 0) {
        cout << "No games found for " << username << ".\n";
        return;
    }

    cout << "Enter the number of the game you want to review (1-" << gameCount << "): ";
    int reviewChoice;
    cin >> reviewChoice;

    if (reviewChoice < 1 || reviewChoice > gameCount) {
        cout << "Invalid game number. Exiting.\n";
        return;
    }

    cout << "Reviewing Game " << reviewChoice << ":\n";
    displayBoard(gameHistory[reviewChoice - 1].moves);
}

void GameHistory::displayBoard(const vector<string>& moves) {
    vector<char> board(9, ' ');
    string moves_string = moves[0];
    int Totalmove = stoi(moves_string);
    int move[9];

    cout << "moves review: " << moves_string << endl;

    // Extract moves into an array of integers
    for (int i = 0; i < moves_string.length(); i++) {
        int digit = Totalmove % 10; // Get the last digit
        move[moves_string.length()-i-1] = digit; // Store the digit in the array and increment counter
        Totalmove /= 10; // Remove the last digit from the number
    }

    for (int i = 0; i < moves_string.length(); i++) {
        char playerSymbol = (i % 2 == 0) ? 'X' : 'O';
        board[move[i]] = playerSymbol;
    }

    cout << "-------------\n";
    for (int i = 0; i < 9; ++i) {
        cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "|\n";
            cout << "-------------\n";
        }
    }
}