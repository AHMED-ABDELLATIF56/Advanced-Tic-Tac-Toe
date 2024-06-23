#include "GameBoard.h"

GameBoard::GameBoard()
{
    // Initialize the board with empty cells
    m_board = QVector<char>(9, EMPTY); // Assuming a 3x3 board for tic-tac-toe
}

int GameBoard::boardSize() const
{
    return m_board.size();
}

char GameBoard::cellAt(int index) const
{
    return m_board[index];
}

QVector<char> GameBoard::boardState() const
{
    return m_board;
}

void GameBoard::setCell(int index, char symbol)
{
    m_board[index] = symbol;
}
