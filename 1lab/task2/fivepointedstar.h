#ifndef FIVEPOINTEDSTAR_H
#define FIVEPOINTEDSTAR_H

#include "star.h"

class FivePointedStar : public Star
{
public:
    FivePointedStar(int x = 0, int y = 0, int innerRadius = 40, int outerRadius = 100);
    ~FivePointedStar();
};

#endif // FIVEPOINTEDSTAR_H
