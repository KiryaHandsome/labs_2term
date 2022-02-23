#ifndef SIXPOINTEDSTAR_H
#define SIXPOINTEDSTAR_H

#include "star.h"

class SixPointedStar : public Star
{
public:
    SixPointedStar(int x = 0, int y = 0, int innerRadius = 40, int outerRadius = 100);
    ~SixPointedStar();
};

#endif // SIXPOINTEDSTAR_H
