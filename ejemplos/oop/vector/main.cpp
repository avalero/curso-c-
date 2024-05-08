#include "Vector.h"
#include "Vector2.h"

#include <iostream>

using namespace std;

int main()
{
  Vector v1{{1, 2, 3}};
  Vector v2{{1, 2, 3}};
  cout << "size: " << v1.getSize() << endl;
  cout << "elem 1: " << v1.at(1) << endl;
  cout << "module: " << v1.getModule() << endl;

  cout << v1 + v2 << endl;
  cout << v1 - v2 << endl;
  cout << dotProduct(v1, v2);
}