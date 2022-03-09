#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(int R = 100);
    ~Triangle();
    double area() const override;
    double perimeter() const override;
    void setSize(int radius);
    void draw(QPainter*) override;
private:
    int R;  //The circumcircle(circle around triangle)
};

#endif // TRIANGLE_H
