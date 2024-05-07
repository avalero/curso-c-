#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

using namespace std;

class Polygon
{
public:
  Polygon();
  Polygon(int sides, vector<double> const &sidesLength, vector<double> const &angles);

  void setPolygon(int sides, vector<double> const &sidesLength, vector<double> const &angles);

  int getSides() const { return sides; }
  vector<double> getSidesLength() const { return sidesLength; }
  vector<double> getAngles() const { return angles; }

  float getPerimeter() const;

protected:
  int sides;
  vector<double> sidesLength;
  vector<double> angles;
};

#endif