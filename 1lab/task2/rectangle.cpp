#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
{
    this->width = width;
    this->height = height;
}

Rectangle::~Rectangle(){}

double Rectangle::area() const { return width * height; }

double Rectangle::perimeter() const { return 2 * (width + height); };

void Rectangle::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Rectangle::draw(QPainter* painter)
{
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::black);
    painter->drawRect(center.x() - width / 2, center.y() - height / 2, width, height);
}
