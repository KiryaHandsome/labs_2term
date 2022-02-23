#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"


class Ellipse : public Figure
{
public:
    Ellipse(QPoint center = QPoint(0, 0), int wradius = 100, int hradius = 50);
    ~Ellipse();
    double area() const override;
    double perimeter() const override;
    void draw(QPainter*) override;
    void setSize(int wr, int hr);
protected:
    int wradius;
    int hradius;
};

#endif // ELLIPSE_H
