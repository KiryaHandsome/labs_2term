#include "circle.h"
#include <QPainter>

Circle::Circle(QPoint center, int radius)
{
    this->center = center;
    this->wradius = this->hradius = radius;
}

Circle::~Circle(){}

void Circle::setSize(int r)
{
    wradius = hradius = r;
}
