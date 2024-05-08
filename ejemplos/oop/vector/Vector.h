#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <ostream>

using namespace std;

class Vector
{
public:
  Vector(int size);
  Vector(vector<double> const &data);

  // getters
  int getSize() const { return data.size(); };
  vector<double> getSTDVector() const { return data; };

  // setter
  void setData(vector<double> const &d);

  double at(int i) const;
  void setAt(int i, double dato);

  double getModule() const;

private:
  vector<double> data;
  // const int size; // -> data.size();
};

Vector operator+(Vector const &a, Vector const &b);
Vector operator-(Vector const &a, Vector const &b);
double dotProduct(Vector const &a, Vector const &b);

ostream &operator<<(ostream &os, Vector const &a);

#endif // VECTOR_H