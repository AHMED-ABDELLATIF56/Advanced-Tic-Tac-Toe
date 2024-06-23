#ifndef XOPLAYER_H
#define XOPLAYER_H

#include <vector>

class xoplayer {
public:
    xoplayer(char symbol);
    int makeMove(const std::vector<char>& board);

private:
    char playerSymbol;
};

#endif // XOPLAYER_H
