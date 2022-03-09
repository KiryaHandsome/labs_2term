#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>

class Figure
{
public:
    Figure();
    virtual ~Figure();
    virtual double area() const  = 0;
    virtual double perimeter() const = 0;
    virtual void draw(QPainter*) = 0;

    QPoint centerOfMass();

    void setZoom(float);
    float getZoom();
    void setAngle(int angle);
    int getAngle();
    void setCenter(QPoint);
    QPoint getCenter();

protected:
    int angle = 0;
    QPoint center = QPoint(0, 0);
    float zoom = 1;

};

#endif // FIGURE_H
