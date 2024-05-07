#include "regularpolygon.h"

RegularPolygon::RegularPolygon() : Polygon()
{
}

RegularPolygon::RegularPolygon(int sides, double sideLength) : Polygon{sides, vector<double>(sides, sideLength), vector<double>(sides, (sides - 2) * 180.0 / sides)}
{
}
