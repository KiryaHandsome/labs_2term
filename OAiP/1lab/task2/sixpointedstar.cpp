#include "sixpointedstar.h"

SixPointedStar::SixPointedStar(int x, int y, int innerRadius, int outerRadius)
{
    pointAmount = 6;
    center = QPoint(x, y);
    this->innerRadius = innerRadius;
    this->outerRadius = outerRadius;
}

SixPointedStar::~SixPointedStar(){}

