#include "star.h"
#include <QPainterPath>

Star::Star()
{

}
Star::~Star(){}

void Star::draw(QPainter* painter)
{
    QPainterPath path(center);
    path.moveTo(center.x(), center.y() - outerRadius);
    for (int i = 1; i <= pointAmount; i++){
          path.lineTo(center.x() + sin((i * 2 - 1) * M_PI / pointAmount) * innerRadius, center.y() - cos((i * 2 - 1) * M_PI / pointAmount) * innerRadius);
          path.lineTo(center.x() + sin(i * 2 * M_PI / pointAmount) * outerRadius + 1, center.y() - cos(i * 2 * M_PI / pointAmount) * outerRadius - 1);
    }
    painter->fillPath(path, QBrush(Qt::darkRed));
}

double Star::area() const
{
    return pointAmount * innerRadius * outerRadius * sin(2 * M_PI / (pointAmount * 2));
}

double Star::perimeter() const
{
    return pointAmount * 2 * sqrt(pow(innerRadius, 2) + pow(outerRadius, 2)  - 2 * innerRadius * outerRadius * cos(360 / (pointAmount * 2)));
}

void Star::setSize(int innerRadius, int outerRadius)
{
    this->innerRadius = innerRadius;
    this->outerRadius = outerRadius;
}
