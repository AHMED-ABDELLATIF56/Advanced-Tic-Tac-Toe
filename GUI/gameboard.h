// gameboard.h

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QVector>  // Include necessary Qt headers

// Constants representing board states
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

class GameBoard {
public:
    GameBoard();  // Constructor
    ~GameBoard(); // Destructor

    QVector<char> boardState() const;
    void setCell(int index, char value);
    char cellAt(int index) const;
    int boardSize() const;

private:
    QVector<char> m_board;
    int m_size;
};

#endif // GAMEBOARD_H
