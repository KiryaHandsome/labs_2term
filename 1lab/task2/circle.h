#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"
#include <QPoint>

class Circle : public Ellipse
{
public:
    Circle(QPoint center = QPoint(0, 0), int radius = 100);
    ~Circle();
    void setSize(int r);
};

#endif // CIRCLE_H
