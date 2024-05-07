#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "polygon.h"

class RegularPolygon : public Polygon
{
public:
  RegularPolygon();
  RegularPolygon(int sides, double sideLength);
};

#endif