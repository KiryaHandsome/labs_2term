#ifndef A_H
#define A_H

#include <QString>
#include "Stack.h"

struct Position {
    Position(int r = 0, int c = 0) : row(r), column(c){}
    int row;
    int column;
};

Position checkBrackets(const std::string& input);

#endif // A_H
