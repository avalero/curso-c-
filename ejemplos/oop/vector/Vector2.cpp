#include "Vector2.h"
#include <cmath>

Vector2::Vector2() : Vector{2}
{
}

Vector2::Vector2(double a, double b) : Vector{{a, b}}
{
}

double Vector2::getModule() const
{
  return std::sqrt(at(1) * at(1) + at(0) * at(0));
}