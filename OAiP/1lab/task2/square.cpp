#include "square.h"

#include "rectangle.h"

Square::Square(int x, int y, int side)
{
    this->width = this->height = side;
}

Square::~Square(){}


void Square::setSize(int side)
{
    this->width = this->height = side;
}

