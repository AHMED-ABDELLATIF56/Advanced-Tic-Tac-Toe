#include "medium.h"
#include <cstdlib> // For std::rand()
#include <ctime>   // For std::time()
#include <vector>

medium::medium(char symbol) : playerSymbol(symbol) {
    // Constructor to initialize with player symbol
    std::srand(std::time(nullptr)); // Seed random number generator
}

int medium::makeMove(const std::vector<char> &board) {
    int move;
    std::vector<int> availableMoves;

    // Collect all available moves (empty cells) from the board
    for (int i = 0; i < board.size(); ++i) {
        if (board[i] == ' ')
            availableMoves.push_back(i);
    }

    // If no available moves (shouldn't happen in a well-designed game loop)
    if (availableMoves.empty())
        return -1;

    // Randomly choose a move from available moves
    int randomIndex = std::rand() % availableMoves.size();
    move = availableMoves[randomIndex];

    return move;
}
