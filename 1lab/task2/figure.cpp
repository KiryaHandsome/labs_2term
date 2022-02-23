#include "figure.h"

Figure::Figure(){}

Figure::~Figure(){}

QPoint Figure::centerOfMass() { return center; }

void Figure::setZoom(float zoom)
{
    this->zoom = zoom;
}

float Figure::getZoom()
{
    return zoom;
}

void Figure::setAngle(int angle)
{
    this->angle = angle;
}

int Figure::getAngle()
{
    return angle;
}

void Figure::setCenter(QPoint point)
{
    center = point;
}

QPoint Figure::getCenter()
{
    return center;
}
