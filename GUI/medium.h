#ifndef MEDIUM_H
#define MEDIUM_H

#include <vector>

class medium {
public:
    medium(char symbol); // Constructor to initialize with player symbol

    int makeMove(const std::vector<char> &board); // Function to make a move

private:
    char playerSymbol; // Player's symbol (either 'X' or 'O')
};

#endif // MEDIUMPLAYER_H

