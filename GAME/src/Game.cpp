#include <iostream>
#include <sstream>
#include <fstream>
#include "CLASSES.hpp"
#include "database.h"

using namespace std;

int main() {

    Database database("users.txt"); // Create instance of Database
    GameHistory gamehistory("game_history.txt");

    int choice;
    string username;
    bool loggedIn = false;

    while (true) {
        if (!loggedIn) {
            cout << "Welcome to X-O Game. :)\n";
            cout << "Select an option:\n";
            cout << "1. Sign Up\n";
            cout << "2. Sign In\n";
            cout << "3. Exit\n";
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    database.signUp(); // Use signUp method of Database
                    break;
                case 2:
                    loggedIn = database.signIn(username); // Use signIn method of Database
                    break;
                case 3:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                    break;
            }
        } else {
            cout << "Welcome, " << username << "!\n";
            cout << "Select an option:\n";
            cout << "1. View Game History\n";
            cout << "2. Play Game\n";
            cout << "3. Log Out\n";
            cout << "Enter your choice (1-3): ";
            int subChoice;
            cin >> subChoice;

            switch (subChoice) {
                case 1:
                    gamehistory.viewGameHistory(username); // Use viewGameHistory method of Database
                    break;
                case 2: {
                    Player* playerX = new HumanPlayer();
                    Player* playerO = nullptr;
                    string opponentName;

                    while (true) {
                        cout << "Select opponent:\n";
                        cout << "1. Play against another player\n";
                        cout << "2. Play against the computer (easy)\n";
                        cout << "3. Play against the computer (medium)\n";
                        cout << "4. Play against the computer (hard)\n";
                        cout << "Enter your choice (1-4): ";

                        int opponentChoice;
                        cin >> opponentChoice;

                        if (opponentChoice >= 1 && opponentChoice <= 4) {
                            switch (opponentChoice) {
                                case 1:
                                    playerO = new HumanPlayer();
                                    cout << "Enter opponent's name: ";
                                    cin >> opponentName;
                                    break;
                                case 2:
                                    playerO = new randomPlayer();
                                    opponentName = "Computer";
                                    break;
                                case 3:
                                    playerO = new mediumplayer(PLAYER_O);
                                    opponentName = "Computer (Medium)";
                                    break;
                                case 4:
                                    playerO = new AIPlayer(PLAYER_O);
                                    opponentName = "Computer (Hard)";
                                    break;
                            }
                            break; // Exit the opponent selection loop
                        } else {
                            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                        }
                    }

                    TicTacToe game(playerX, playerO, &gamehistory); // Pass database instance to TicTacToe
                    game.playGame(username, opponentName);

                    delete playerX;
                    delete playerO;
                    break;
                }
                case 3:
                    loggedIn = false;
                    username.clear();
                    cout << "Logged out successfully.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
        }
    }
}