#ifndef EIGHTPOINTEDSTAR_H
#define EIGHTPOINTEDSTAR_H

#include "star.h"

class EightPointedStar : public Star
{
public:
    EightPointedStar(int x = 0, int y = 0, int innerRadius = 40, int outerRadius = 100);
    ~EightPointedStar();
};

#endif // EIGHTPOINTEDSTAR_H
