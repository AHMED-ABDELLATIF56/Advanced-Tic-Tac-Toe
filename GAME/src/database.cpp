//
// Created by Ahmed on 6/23/2024.
//

#include "../include/database.h"
#include <sqlite3.h>
#include <fstream>
#include <sstream>
#include <iostream>

void executeSQL(sqlite3* db, const std::string& sql) {
    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void executeSQLFromFile(sqlite3* db, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sql = buffer.str();
    std::cout << "Executing SQL from file: " << sql << std::endl; // Debug output
    executeSQL(db, sql);
}

void insertUser(sqlite3* db, const std::string& username, const std::string& passwordHash, const std::string& email) {
    std::string sql = "INSERT INTO Users (username, password_hash, email) VALUES (?, ?, ?)";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, passwordHash.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_finalize(stmt);
}

bool getUserByUsername(sqlite3* db, const std::string& username, std::string& passwordHash) {
    std::string sql = "SELECT password_hash FROM Users WHERE username = ?";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    bool userFound = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        passwordHash = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        userFound = true;
    }
    sqlite3_finalize(stmt);
    return userFound;
}

void insertGameHistory(sqlite3* db, int player1_id, int player2_id, int winner, const std::string& moves) {
    std::string sql = "INSERT INTO GameHistory (player1_id, player2_id, winner, moves) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, player1_id);
    sqlite3_bind_int(stmt, 2, player2_id);
    sqlite3_bind_int(stmt, 3, winner);
    sqlite3_bind_text(stmt, 4, moves.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_finalize(stmt);
}
