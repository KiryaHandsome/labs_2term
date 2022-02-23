#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public:
    Rhomb(int x = 0, int y = -50, int width = 200, int height = 100);
    ~Rhomb();
    double area() const override;
    double perimeter() const override;
    void draw(QPainter*) override;
    void setSize(int width, int height);
private:
    QPoint top;
    int side;
    int width;
    int height;
};

#endif // RHOMB_H
