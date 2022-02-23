#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon(int x = 0, int y = 0, int radius = 100);
    ~Hexagon();
    double area() const override;
    double perimeter() const override;
    void draw(QPainter*) override;
    void setSize(int r);
private:
    int radius;
};

#endif // HEXAGON_H
