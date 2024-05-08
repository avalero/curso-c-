#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Vector.h"

class Vector2 : public Vector
{
public:
  Vector2();
  Vector2(double a, double b);

  double getX() const { return at(0); };
  double getY() const { return at(1); };

  void setX(double d) { setAt(0, d); };
  void setY(double d) { setAt(1, d); };

  double getModule() const;
};

#endif