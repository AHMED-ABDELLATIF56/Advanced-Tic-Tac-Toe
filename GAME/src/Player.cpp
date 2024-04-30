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
