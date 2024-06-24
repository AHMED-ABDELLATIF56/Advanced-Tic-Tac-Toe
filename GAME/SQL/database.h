#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

void executeSQL(sqlite3* db, const std::string& sql);
void executeSQLFromFile(sqlite3* db, const std::string& filename);
void insertUser(sqlite3* db, const std::string& username, const std::string& passwordHash, const std::string& email);
bool getUserByUsername(sqlite3* db, const std::string& username, std::string& passwordHash);
void insertGameHistory(sqlite3* db, int player1_id, int player2_id, int winner, const std::string& moves);

#endif
