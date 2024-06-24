
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

