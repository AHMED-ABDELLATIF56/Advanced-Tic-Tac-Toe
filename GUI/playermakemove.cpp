// Player.cpp

#include "Player.h"
#include <cstdlib>  // for std::rand()
#include <ctime>    // for std::time()

Player::Player(char symbol) : playerSymbol(symbol) {
    // Constructor implementation if needed
}

int Player::makeMove(const std::vector<char>& board) {
    int move = 0;  // Replace with actual move logic

    // Example: Randomly choose an empty position on the board
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    move = std::rand() % 9;  // Generate a random move between 0 and 8 (inclusive)

    // Check if the randomly chosen position is empty
    while (move < 9 && board[move] != ' ') {
        move = std::rand() % 9;  // Generate a new random move until an empty position is found
    }

    return move;
}
