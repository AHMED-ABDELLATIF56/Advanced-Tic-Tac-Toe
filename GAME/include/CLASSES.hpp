#ifndef _CLASSES_HPP
#define _CLASSES_HPP
#include "database.h"

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

class Player {
public:
    virtual int makeMove(const vector<char>& board);
};

class HumanPlayer : public Player {
public:
    int makeMove(const vector<char>& board);
};

class randomPlayer : public Player {
public:
    int makeMove(const vector<char>& board);
};

class mediumplayer : public Player {
private:
    char playerSymbol;
    char opponentSymbol;
public:
    mediumplayer(char symbol);
    int makeMove(const vector<char>& board);
};

class AIPlayer : public Player {
private:
    char playerSymbol;
    char opponentSymbol;

public:
    AIPlayer(char symbol);

    int makeMove(const vector<char>& board);

    int minimax(vector<char>& board, bool isMaximizing, int depth);

    bool checkWinner(char player, const vector<char>& board);

    bool isBoardFull(const vector<char>& board);
};

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;
    char opponent;
    Player* playerX;
    Player* playerO;
    Database* database; // Database instance

public:
    TicTacToe(Player* playerX, Player* playerO, Database* database); // Constructor

    void printBoard();
    bool checkWinner(char player);
    bool isBoardFull();
    void playGame(const string& username, const string& opponentName);
};

#endif
