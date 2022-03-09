#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(int x = -100, int y = -50, int width = 200, int height = 100);
    ~Rectangle();
    double area() const override;
    double perimeter() const override;
    void draw(QPainter*) override;
    void setSize(int width, int height);
protected:
    int width;
    int height;
};

#endif // RECTANGLE_H
