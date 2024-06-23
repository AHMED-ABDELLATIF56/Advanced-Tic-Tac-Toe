// AIPlayer.h

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

enum Player { PLAYER_X, PLAYER_O };

class Player {
private:
    Player playerType;

public:
    Player(Player type);
    int makeMove(const std::vector<char> &board);
};

#endif // AIPLAYER_H
