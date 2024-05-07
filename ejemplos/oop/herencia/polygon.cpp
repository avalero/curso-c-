#include "polygon.h"
#include <stdexcept>

using namespace std;

Polygon::Polygon()
{
  sides = 0;
  sidesLength = {};
  angles = {};
}

Polygon::Polygon(int sides, vector<double> const &sidesLength, vector<double> const &angles)
{
  setPolygon(sides, sidesLength, angles);
}

void Polygon::setPolygon(int sides, vector<double> const &sidesLength, vector<double> const &angles)
{
  if (sidesLength.size() != sides || angles.size() != sides)
  {
    throw invalid_argument("Invalid number of sides, sidesLength or angles");
  }

  const double sumAngles = (sides - 2) * 180.0;
  double anglesSum = 0;
  for (auto angle : angles)
  {
    anglesSum += angle;
  }

  if (sumAngles != anglesSum)
  {
    throw invalid_argument("Invalid angles");
  }

  this->sides = sides;
  this->sidesLength = sidesLength;
  this->angles = angles;
}

float Polygon::getPerimeter() const
{
  float perimeter = 0;
  for (auto side : sidesLength)
  {
    perimeter += side;
  }
  return perimeter;
}