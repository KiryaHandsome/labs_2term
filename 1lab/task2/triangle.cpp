#include "triangle.h"
#include <QPainterPath>

Triangle::Triangle(int R)
{
    this->R = R;
}
Triangle::~Triangle(){}

double Triangle::area() const
{
    return (3 * sqrt(3) / 4) * pow(R, 2);
}

double Triangle::perimeter() const
{
    return 3 * sqrt(3) * R;
}

void Triangle::setSize(int radius)
{
    this->R = radius;
}

void Triangle::draw(QPainter* painter)
{
    QPolygon points;
    int angle = 0;
    int x, y;
    for (int i = 0; i < 4; i++){
        x = center.x() + R * cos(angle * M_PI / 180);
        y = center.y() + R * sin(angle * M_PI / 180);
        points << QPoint(x, y);
        angle = angle + 120;
    }
    QPainterPath path;
    painter->drawPolygon(points);
    path.addPolygon(points);
    painter->fillPath(path, Qt::blue);
}
