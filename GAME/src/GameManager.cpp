#include <iostream>
#include <vector>
#include "CLASSES.hpp"
#include "database.h"

using namespace std;

vector<char> board;
char currentPlayer;
char opponent;
Player* playerX;
Player* playerO;

TicTacToe::TicTacToe(Player* playerX, Player* playerO, Database* database)
    : playerX(playerX), playerO(playerO), database(database) {
    board = vector<char>(9, EMPTY);
    currentPlayer = PLAYER_X;
    opponent = PLAYER_O;
}

void TicTacToe::printBoard() {
    for (int i = 0; i < 9; i++) {
        cout << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

bool TicTacToe::checkWinner(char player) {
    const vector<vector<int>> WINNING_COMBOS = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}  // Diagonals
    };

    for (const auto& combo : WINNING_COMBOS) {
        if (board[combo[0]] == player && board[combo[1]] == player && board[combo[2]] == player) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::isBoardFull() {
    for (const auto& cell : board) {
        if (cell == EMPTY) {
            return false;
        }
    }
    return true;
}

void TicTacToe::playGame(const string& username, const string& opponentName) {
    string moves; // Initialize string to store moves
    while (true) {
        printBoard();
        int move;
        if (currentPlayer == PLAYER_X) {
            move = playerX->makeMove(board);
        } else {
            move = playerO->makeMove(board);
            cout << opponentName << " chose position " << move << endl;
        }

        if (board[move] == EMPTY) {
            board[move] = currentPlayer;
            moves += to_string(move); // Record the move
            if (checkWinner(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (isBoardFull()) {
                printBoard();
                cout << "It's a tie!" << endl;
                break;
            }
            swap(currentPlayer, opponent); // Swap players
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Determine winner for game history
    string winner = (checkWinner(PLAYER_X)) ? username : (checkWinner(PLAYER_O)) ? opponentName : "Tie";

    // Save game history using Database class method
    database->saveGameHistory(username, opponentName, winner, moves);
}
