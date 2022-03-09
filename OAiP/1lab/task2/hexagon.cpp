#include "hexagon.h"
#include <QPolygon>
#include <QPainterPath>

Hexagon::Hexagon(int x, int y, int radius)
{
    this->radius = radius;
    center = QPoint(x, y);
}

Hexagon::~Hexagon(){}

double Hexagon::area() const
{
    return  6 * pow(radius, 2) * sqrt(3) / 2;
}

double Hexagon::perimeter() const
{
    return 6 * radius;
}

void Hexagon::draw(QPainter* painter)
{
    QPolygon points;
    int angle = 0;
    int x, y;
    for (int i = 0; i < 7; i++){
        x = center.x() + radius * cos(angle * M_PI / 180);
        y = center.y() + radius * sin(angle * M_PI / 180);
        points << QPoint(x, y);
        angle = angle + 60;
    }
    QPainterPath path;
    painter->drawPolygon(points);
    path.addPolygon(points);
    painter->fillPath(path, Qt::green);
}

void Hexagon::setSize(int r){
    this->radius = r;
}
