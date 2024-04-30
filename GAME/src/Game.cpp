#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // for rand()
#include"CLASSES.hpp"
using namespace std;

int main() {
      int choice;
    

     cout << "Welcome to X-O Game. :)\n";
    cout << "Select the game mode:\n";
    cout << "1. Play against the computer (easy)\n";
    cout << "2. Play against the computer (hard)\n";
    cout << "3. Play against another player\n";
    cout << "Enter your choice (1-3): ";
    
    cin >> choice;

    // Validate user input and handle invalid choices
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter a number between 1 and 3: ";
        cin.clear();  // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cin >> choice;
    }

    Player* playerX = new HumanPlayer();
    Player* playerO;

    if (choice==1){
        playerO = new randomPlayer();
    }
    else if (choice==2){
       playerO = new AIPlayer(PLAYER_O);
    }
    else if (choice==3){
        playerO = new HumanPlayer();
    }


    TicTacToe game(playerX, playerO);
    game.playGame();

    delete playerX;
    delete playerO;
    }
