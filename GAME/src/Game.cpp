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
    cout << "1. Play against another player\n";
    cout << "2. Play against the computer (easy)\n";
    cout << "3. Play against the computer (medium)\n";
    cout << "4. Play against the computer (hard)\n";
    cout << "Enter your choice (1-4): ";
    
    cin >> choice;

    // Validate user input and handle invalid choices
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4: ";
        cin.clear();  // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cin >> choice;
    }

    Player* playerX = new HumanPlayer();
    Player* playerO;

    if (choice==1){
        playerO = new HumanPlayer();
    }
    else if (choice==2){
        playerO = new randomPlayer();

    }
    else if (choice==3){
        playerO = new mediumplayer(PLAYER_O);
    }
    else if (choice==4){
        playerO = new AIPlayer(PLAYER_O);
    }


    TicTacToe game(playerX, playerO);
    game.playGame();

    delete playerX;
    delete playerO;
    }
