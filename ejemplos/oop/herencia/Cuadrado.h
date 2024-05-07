#ifndef CUADRADO_H
#define CUADRADO_H

#include "regularpolygon.h"

class Cuadrado : public RegularPolygon
{
public:
  Cuadrado(double lado);
  double getArea() const;
};

#endif