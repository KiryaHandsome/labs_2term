#include "parallelogram.h"
#include <QPainterPath>

Parallelogram::Parallelogram(int a, int b, int angle)
{
    this->a = a;
    this->b = b;
    this->innerAngle = angle;
}

Parallelogram::~Parallelogram(){}

double Parallelogram::area() const { return a * b * sin(angle) ; }

double Parallelogram::perimeter() const { return 2 * (a + b); };

void Parallelogram::setSize(int a, int b, int angle)
{
    this->a = a;
    this->b = b;
    this->innerAngle = angle;
}

void Parallelogram::draw(QPainter* painter)
{
    QPainterPath path;

    QPoint p1(center.x() - (a * cos(innerAngle * M_PI / 180) + b) / 2, center.y() + a * sin(innerAngle * M_PI / 180) / 2);
    QPoint p2(center.x() - (b - a * cos(innerAngle * M_PI / 180)) / 2 , center.y() - a * sin(innerAngle * M_PI / 180) / 2);
    QPoint p3(center.x() - (b - a * cos(innerAngle * M_PI / 180)) / 2 + b , center.y() - a * sin(innerAngle * M_PI / 180) / 2);
    QPoint p4(center.x() - (a * cos(innerAngle * M_PI / 180) + b) / 2 + b, center.y() + a * sin(innerAngle * M_PI / 180) / 2);

    path.moveTo(p1);

    path.lineTo(p2);
    path.lineTo(p3);
    path.lineTo(p4);
    path.lineTo(p1);

    painter->fillPath(path, QBrush(Qt::darkCyan));
}
