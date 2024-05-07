#include "Punto2d.h"
#include <cmath>

Punto2d::Punto2d()
{
  x = 0;
  y = 0;
}

Punto2d::Punto2d(double a, double b, bool polar)
{
  if (polar)
  {
    x = a * cos(b);
    y = a * sin(b);
  }
  else
  {
    x = a;
    y = b;
  }
}

void Punto2d::setX(double a)
{
  x = 0;
}

void Punto2d::setY(double b)
{
  y = 0;
}

void Punto2d::setR(double r)
{
  x = 0;
  y = 0;
}

void Punto2d::setTheta(double theta)
{
  x = 0;
  y = 0;
}
