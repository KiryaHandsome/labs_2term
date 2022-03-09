#include "rhomb.h"
#include <QPainterPath>


Rhomb::Rhomb(int x, int y, int width, int height)
{
    top.setX(x);
    top.setY(y);
    this->width = width;
    this->height = height;
}

Rhomb::~Rhomb(){}

double Rhomb::area() const { return width * height; }

double Rhomb::perimeter() const { return 4 * side; };

void Rhomb::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
    center.setY(top.y() + height / 2);
}

void Rhomb::draw(QPainter* painter)
{
    QPainterPath path;

    QPoint p1(center.x(), center.y() - height / 2);
    QPoint p2(center.x() + width / 2, center.y());
    QPoint p3(center.x(), center.y() + height / 2);
    QPoint p4(center.x() - width / 2, center.y());

    path.moveTo(p1);

    path.lineTo(p2);
    path.lineTo(p3);    //draw rhomb
    path.lineTo(p4);
    path.lineTo(p1);

    painter->fillPath(path, QBrush(Qt::blue));
}
