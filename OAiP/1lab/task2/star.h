#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure      //abstract class
{
public:
    Star();
    ~Star();
    void draw(QPainter*) override;
    double perimeter() const override;
    double area() const override;
    void setSize(int innerRadius, int outerRadius);
protected:
    int pointAmount;
    int innerRadius;
    int outerRadius;
};

#endif // STAR_H
