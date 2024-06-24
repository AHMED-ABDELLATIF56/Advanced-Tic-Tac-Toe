#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // for rand()
#include<sqlite3>
#include"CLASSES.hpp"
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
    executeSQLFromFile(db, "setup.sql");
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
    bool userFound = getUserByUsernameAndPassword(db, username, password, passwordHash);

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

void viewGameHistory(sqlite3* db, const std::string& username) {
    // Fetch game history from database for the current user
    sqlite3_stmt* stmt;
    std::string sql = "SELECT game_id, player1_id, player2_id, winner, moves, timestamp FROM GameHistory WHERE player1_id = (SELECT id FROM Users WHERE username = ?) OR player2_id = (SELECT id FROM Users WHERE username = ?)";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_STATIC);

    std::vector<int> gameIDs; // To store game IDs for selection
    std::vector<std::string> gameSummaries; // To store game summaries for display

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int game_id = sqlite3_column_int(stmt, 0);
        int player1_id = sqlite3_column_int(stmt, 1);
        int player2_id = sqlite3_column_int(stmt, 2);
        int winner = sqlite3_column_int(stmt, 3);
        const unsigned char* moves = sqlite3_column_text(stmt, 4);
        const unsigned char* timestamp = sqlite3_column_text(stmt, 5);

        std::string gameSummary = "Game ID: " + std::to_string(game_id) + "\n";
        gameSummary += "Timestamp: " + std::string(reinterpret_cast<const char*>(timestamp)) + "\n";
        gameSummary += "Moves: " + std::string(reinterpret_cast<const char*>(moves)) + "\n";

        // Determine opponent's username
        std::string opponentUsername;
        if (player1_id == sqlite3_column_int(stmt, 1)) {
            opponentUsername = "Computer";
        } else {
            sql = "SELECT username FROM Users WHERE id = ?";
            sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
            sqlite3_bind_int(stmt, 1, player2_id);
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                opponentUsername = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            }
            sqlite3_finalize(stmt);
        }

        gameSummary += "Opponent: " + opponentUsername + "\n";

        if (winner == player1_id) {
            gameSummary += "Winner: " + username + "\n";
        } else if (winner == player2_id) {
            gameSummary += "Winner: " + opponentUsername + "\n";
        } else {
            gameSummary += "Winner: Tie\n";
        }

        gameIDs.push_back(game_id);
        gameSummaries.push_back(gameSummary);
    }

    sqlite3_finalize(stmt);

    // Display game history
    if (gameIDs.empty()) {
        std::cout << "No games played yet.\n";
    } else {
        std::cout << "Game History:\n";
        for (size_t i = 0; i < gameIDs.size(); ++i) {
            std::cout << gameSummaries[i] << std::endl;
        }

        // Prompt user to review a game
        int selectedGameID;
        bool validSelection = false;
        while (!validSelection) {
            std::cout << "Enter the Game ID to review (0 to return to main menu): ";
            std::cin >> selectedGameID;

            if (selectedGameID == 0) {
                return; // Return to main menu
            }

            // Check if selectedGameID is valid
            auto it = std::find(gameIDs.begin(), gameIDs.end(), selectedGameID);
            if (it != gameIDs.end()) {
                validSelection = true;
            } else {
                std::cout << "Invalid Game ID. Please enter a valid Game ID.\n";
            }
        }

        // Fetch moves for selected game from database
        sql = "SELECT moves FROM GameHistory WHERE game_id = ?";
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_int(stmt, 1, selectedGameID);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* moves = sqlite3_column_text(stmt, 0);

            // Initialize a new TicTacToe game to replay moves
            Player* playerX = new HumanPlayer();
            Player* playerO = nullptr; // Placeholder for opponent player

            TicTacToe game(playerX, playerO);
            vector<char> board(9, EMPTY);
            game.setBoard(board); // Set the board for replaying moves

            std::string movesStr(reinterpret_cast<const char*>(moves));
            std::istringstream iss(movesStr);
            char symbol = PLAYER_X;
            int move;
            while (iss >> move) {
                board[move] = symbol;
                symbol = (symbol == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }

            // Display the board move by move
            displayBoard(board);
        }

        sqlite3_finalize(stmt);
    }
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
                            viewGameHistory(db, username);
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
