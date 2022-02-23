#include "fivepointedstar.h"

FivePointedStar::FivePointedStar(int x, int y, int innerRadius, int outerRadius)
{
    pointAmount = 5;
    center = QPoint(x, y);
    this->innerRadius = innerRadius;
    this->outerRadius = outerRadius;
}

FivePointedStar::~FivePointedStar(){}
