#include "ellipse.h"


Ellipse::Ellipse(QPoint center, int wradius, int hradius)
{
    this->center = center;
    this->wradius = wradius;
    this->hradius = hradius;
}

Ellipse::~Ellipse(){}

double Ellipse::area() const { return  M_PI * wradius * hradius; }

double Ellipse::perimeter() const { return 4 * (M_PI * wradius * hradius + (wradius - hradius)) / (wradius + hradius); };

void Ellipse::setSize(int wr, int hr)
{
    wradius = wr;
    hradius = hr;
}

void Ellipse::draw(QPainter* painter)
{
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->drawEllipse(center, wradius, hradius);

}
