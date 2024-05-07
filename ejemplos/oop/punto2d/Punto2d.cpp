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
  x = a;
}

void Punto2d::setY(double b)
{
  y = b;
}

void Punto2d::setPolar(double r, double theta)
{
  x = r * cos(theta);
  y = r * sin(theta);
}

double Punto2d::getTheta() const
{
  if (y == 0)
    return 0;
  if (x == 0)
  {
    if (y > 0)
      return M_PI / 2;
    else
      return -M_PI / 2;
  }

  return atan2(y, x);
}
