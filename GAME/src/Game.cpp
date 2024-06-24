#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib> // for rand()
#include "sqlite3.h"
#include "CLASSES.hpp"
#include "database.h"

using namespace std;


// Initialize SQLite database
sqlite3* db;

void initializeDatabase() {
    int rc = sqlite3_open("game_database.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        exit(1);
    }

    // Create tables and execute initial SQL setup
    std::ifstream scriptFile("database");
    if (scriptFile) {
        std::stringstream buffer;
        buffer << scriptFile.rdbuf();
        std::string script = buffer.str();
        char *errMsg = nullptr;
        rc = sqlite3_exec(db, script.c_str(), nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
        } else {
            printf("Database setup successfully.\n");
        }
    } else {
        fprintf(stderr, "Failed to open script file.\n");
    }
}


void signUp() {
    std::string username, password, email;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter email: ";
    std::cin >> email;

    insertUser(db, username, password, email);
}

bool signIn(std::string& username) {
    std::string password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::string passwordHash;
    bool userFound = getUserByUsername(db, username, passwordHash);

    if (userFound) {
        std::cout << "Sign in successful!\n";
        return true;
    } else {
        std::cout << "Invalid username or password.\n";
        return false;
    }
}


void displayBoard(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        cout << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

void viewGameHistory(const std::string& username) {
    int userID;
    sqlite3_stmt* stmt;

    std::string sql = "SELECT id FROM Users WHERE username = ?";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        userID = sqlite3_column_int(stmt, 0);
    } else {
        std::cerr << "User not found." << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);

    // Fetch game history for the user
    sql = "SELECT game_id, player1_id, player2_id, winner, moves, timestamp FROM GameHistory WHERE player1_id = ? OR player2_id = ?";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, userID);
    sqlite3_bind_int(stmt, 2, userID);

    std::vector<int> gameIDs;
    std::vector<std::string> gameDetails;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int gameID = sqlite3_column_int(stmt, 0);
        int player1_id = sqlite3_column_int(stmt, 1);
        int player2_id = sqlite3_column_int(stmt, 2);
        int winner = sqlite3_column_int(stmt, 3);
        const unsigned char* moves = sqlite3_column_text(stmt, 4);
        const unsigned char* timestamp = sqlite3_column_text(stmt, 5);

        gameIDs.push_back(gameID);

        std::stringstream detailStream;
        detailStream << "Game ID: " << gameID << ", Player 1 ID: " << player1_id
                     << ", Player 2 ID: " << player2_id << ", Winner ID: " << winner
                     << ", Moves: " << moves << ", Timestamp: " << timestamp;
        gameDetails.push_back(detailStream.str());
    }
    sqlite3_finalize(stmt);

    if (gameDetails.empty()) {
        std::cout << "No games played yet." << std::endl;
        return;
    }

    std::cout << "Game History:" << std::endl;
    for (size_t i = 0; i < gameDetails.size(); ++i) {
        std::cout << (i + 1) << ". " << gameDetails[i] << std::endl;
    }

    int selectedGameIndex;
    while (true) {
        std::cout << "Enter the number of the game you want to review: ";
        std::cin >> selectedGameIndex;

        if (selectedGameIndex > 0 && static_cast<size_t>(selectedGameIndex) <= gameIDs.size()) {
            break;
        }
        std::cout << "Invalid selection. Please try again." << std::endl;
    }

    int selectedGameID = gameIDs[selectedGameIndex - 1];

    sql = "SELECT moves FROM GameHistory WHERE game_id = ?";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, selectedGameID);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* moves = sqlite3_column_text(stmt, 0);
        std::vector<char> board(9, ' ');
        std::string movesStr(reinterpret_cast<const char*>(moves));

        size_t moveIndex = 0;
        char currentPlayer = 'X';
        while (moveIndex < movesStr.size()) {
            int pos = movesStr[moveIndex++] - '0';
            board[pos] = currentPlayer;
            displayBoard(board);

            std::string command;
            std::cout << "Enter 'n' for next move, 'p' for previous move, 'q' to quit review: ";
            std::cin >> command;

            if (command == "n") {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else if (command == "p") {
                if (moveIndex > 1) {
                    board[pos] = ' ';
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                    moveIndex -= 2;
                } else {
                    std::cout << "No previous moves." << std::endl;
                }
            } else if (command == "q") {
                break;
            } else {
                std::cout << "Invalid command." << std::endl;
            }
        }
    } else {
        std::cerr << "No moves found for selected game." << std::endl;
    }
    sqlite3_finalize(stmt);
}


void playGame(Player* playerX, Player* playerO, const std::string& username) {
    TicTacToe game(playerX, playerO);
    game.playGame();

    // Insert game history after game is finished
    std::string moves = "Replace with actual moves"; // Example, replace with actual moves played
    int player1_id, player2_id, winner;

    // Fetch user IDs from database based on usernames
    sqlite3_stmt* stmt;
    std::string sql = "SELECT id FROM Users WHERE username = ?";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        player1_id = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);

    // Determine player2_id and winner based on game outcome
    if (dynamic_cast<HumanPlayer*>(playerO)) {
        // Player 2 is a human player
        std::string opponentUsername;
        std::cout << "Enter opponent's username: ";
        std::cin >> opponentUsername;

        // Fetch opponent's ID from database
        sql = "SELECT id FROM Users WHERE username = ?";
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_text(stmt, 1, opponentUsername.c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            player2_id = sqlite3_column_int(stmt, 0);
        } else {
            std::cerr << "Error: Opponent not found in database.\n";
            return;
        }
        sqlite3_finalize(stmt);
    } else {
        // Player 2 is a computer opponent
        player2_id = -1; // Special ID reserved for computer opponent
    }

    // Determine winner
    winner = (game.checkWinner(PLAYER_X)) ? player1_id : player2_id;

    // Insert game history into database
    insertGameHistory(db, player1_id, player2_id, winner, moves);
}


int main() {
    initializeDatabase(); // Initialize database connection

    int choice;
    std::string username;

    while (true) {
        std::cout << "Welcome to X-O Game. :)\n";
        std::cout << "Select an option:\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Sign In\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                if (signIn(username)) {
                    // Option to view game history
                    std::cout << "1. View Game History\n";
                    std::cout << "2. Play Game\n";
                    std::cout << "Enter your choice (1-2): ";
                    int subChoice;
                    std::cin >> subChoice;

                    switch (subChoice) {
                        case 1: {
                            // View game history logic (not implemented here)
                            //viewGameHistory(db, username);
                            cout<<"not implemented";
                            break;
                        }
                        case 2: {
                            Player* playerX = new HumanPlayer();
                            Player* playerO = nullptr;

                            while (true) {
                                std::cout << "Select opponent:\n";
                                std::cout << "1. Play against another player\n";
                                std::cout << "2. Play against the computer (easy)\n";
                                std::cout << "3. Play against the computer (medium)\n";
                                std::cout << "4. Play against the computer (hard)\n";
                                std::cout << "Enter your choice (1-4): ";

                                int opponentChoice;
                                std::cin >> opponentChoice;

                                if (opponentChoice >= 1 && opponentChoice <= 4) {
                                    switch (opponentChoice) {
                                        case 1:
                                            playerO = new HumanPlayer();
                                            break;
                                        case 2:
                                            playerO = new randomPlayer();
                                            break;
                                        case 3:
                                            playerO = new mediumplayer(PLAYER_O);
                                            break;
                                        case 4:
                                            playerO = new AIPlayer(PLAYER_O);
                                            break;
                                    }
                                    break; // Exit the opponent selection loop
                                } else {
                                    std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                                }
                            }

                            playGame(playerX, playerO, username);

                            delete playerX;
                            delete playerO;
                            break;
                        }
                        default:
                            std::cout << "Invalid choice.\n";
                            break;
                    }
                }
                break;
            case 3:
                std::cout << "Exiting...\n";
                sqlite3_close(db); // Close database connection
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                break;
        }
    }

    sqlite3_close(db); // Close database connection
    return 0;
}
