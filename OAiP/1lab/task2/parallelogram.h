#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "figure.h"

class Parallelogram : public Figure
{
public:
    Parallelogram(int a = 100, int b = 200, int angle = 45);
    ~Parallelogram();
    double area() const override;
    double perimeter() const override;
    void draw(QPainter*) override;
    void setSize(int a, int b, int angle);
private:
    QPoint top;
    int innerAngle; //between a and b
    int a;
    int b;

};

#endif // PARALLELOGRAM_H
