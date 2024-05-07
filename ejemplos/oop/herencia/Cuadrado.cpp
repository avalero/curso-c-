#include "Cuadrado.h"

Cuadrado::Cuadrado(double lado) : RegularPolygon(4, lado)
{
}

double Cuadrado::getArea() const
{
  return sidesLength[0] * sidesLength[0];
}