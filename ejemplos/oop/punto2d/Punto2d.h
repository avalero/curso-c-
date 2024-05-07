#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <cmath>

class Punto2d
{
public:
  Punto2d();
  Punto2d(double a, double b, bool polar = false);

  double getX() const { return x; };
  double getY() const { return y; };
  double getR() const { return sqrt(x * x + y * y); };
  double getTheta() const { return atan2(y, x); };

  void setX(double a);
  void setY(double b);
  void setR(double r);
  void setTheta(double theta);

  double getModule() const { return sqrt(x * x + y * y); };

private:
  double x;
  double y;
};

#endif // PUNTO2D_H