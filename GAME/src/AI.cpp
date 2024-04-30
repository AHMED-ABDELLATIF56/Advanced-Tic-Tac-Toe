#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // for rand()
#include"CLASSES.hpp"



    AIPlayer::AIPlayer(char symbol) : playerSymbol(symbol) {
        opponentSymbol = (symbol == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    int AIPlayer::makeMove(const vector<char>& board)  {
        int bestMove = -1;
        int bestScore = numeric_limits<int>::min();

        for (int i = 0; i < board.size(); i++) {
            if (board[i] == EMPTY) {
                vector<char> testBoard = board;
                testBoard[i] = playerSymbol;
                int score = minimax(testBoard, false, 0);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            }
        }
        return bestMove;
    }

    int AIPlayer::minimax(vector<char>& board, bool isMaximizing, int depth) {
        if (checkWinner(playerSymbol, board)) {
            return 10 - depth;
        }
        if (checkWinner(opponentSymbol, board)) {
            return depth - 10;
        }
        if (isBoardFull(board)) {
            return 0;
        }

        if (isMaximizing) {
            int bestScore = numeric_limits<int>::min();
            for (int i = 0; i < board.size(); i++) {
                if (board[i] == EMPTY) {
                    board[i] = playerSymbol;
                    int score = minimax(board, false, depth + 1);
                    board[i] = EMPTY;
                    bestScore = max(bestScore, score);
                }
            }
            return bestScore;
        } else {
            int bestScore = numeric_limits<int>::max();
            for (int i = 0; i < board.size(); i++) {
                if (board[i] == EMPTY) {
                    board[i] = opponentSymbol;
                    int score = minimax(board, true, depth + 1);
                    board[i] = EMPTY;
                    bestScore = min(bestScore, score);
                }
            }
            return bestScore;
        }
    }

    bool AIPlayer::checkWinner(char player, const vector<char>& board) {
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

    bool AIPlayer::isBoardFull(const vector<char>& board) {
        for (const auto& cell : board) {
            if (cell == EMPTY) {
                return false;
            }
        }
        return true;
    }
