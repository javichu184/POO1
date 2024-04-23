#include "punto2d.h"

/*
punto2d punto2d::operator+(punto2d p)
{
    punto2d resultado;
    resultado.x = x + p.x;
    resultado.y = y + p.y;

    return resultado;
}
*/
punto2d operator+(const punto2d& p1, const punto2d& p2)
{
    punto2d resultado;
    resultado.x = p1.x + p2.x;
    resultado.y = p1.y + p2.y;

    return resultado;
}

ostream& operator<<(ostream& os, punto2d& c)
{
   
    os << "(" << c.x << "," << c.y << ")";
    return os;
   
}


