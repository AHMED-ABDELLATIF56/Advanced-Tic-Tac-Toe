#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // for rand()
#include"CLASSES.hpp"

     int Player::makeMove (const vector<char>& board){
    return 0;
} ;

    int  HumanPlayer :: makeMove(const vector<char>& board)  {
        int move;
        cout << "Enter your move (0-8): ";
        cin >> move;
        return move;
    }

    int randomPlayer:: makeMove(const vector<char> &board)  {
        int move;
        move = (rand() / (RAND_MAX + 1.0) * 8);
        return move;
    }
mediumplayer::mediumplayer(char symbol) : playerSymbol(symbol) {
    opponentSymbol = (symbol == PLAYER_X) ? PLAYER_O : PLAYER_X;
}
int mediumplayer:: makeMove(const vector<char> &board)  {
    int move , chance;
    chance = (rand() / (RAND_MAX + 1.0) * 99);
    if(chance <= 49){
        move = (rand() / (RAND_MAX + 1.0) * 8);


    }
    else {
        AIPlayer obj1(PLAYER_O);
        move = obj1.makeMove(board);
    }
    return move;
}

