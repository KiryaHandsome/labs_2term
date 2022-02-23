#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square(int x = -75, int y = -75, int side = 150);
    ~Square();
    void setSize(int side);
};

#endif // SQUARE_H
