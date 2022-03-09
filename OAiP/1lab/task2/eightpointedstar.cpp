#include "eightpointedstar.h"

EightPointedStar::EightPointedStar(int x, int y, int innerRadius, int outerRadius)
{
    pointAmount = 8;
    center = QPoint(x, y);
    this->innerRadius = innerRadius;
    this->outerRadius = outerRadius;
}

EightPointedStar::~EightPointedStar(){}

