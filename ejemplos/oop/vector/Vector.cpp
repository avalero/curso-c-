#include "Vector.h"
#include <exception>
#include <stdexcept>
#include <cmath>

// // setter
// void setData(vector<double> &const d);

// double at(int i) const;
// void setAt(int i, double dato);

using namespace std;

Vector::Vector(int size) : data{vector<double>(size, 0)}
{
}

Vector::Vector(vector<double> const &d)
{
  this->data = d;
}

void Vector::setData(vector<double> const &d)
{
  if (!(d.size() == data.size()))
  {
    throw new runtime_error("Vector size is invalid");
  }

  data = d;
}

double Vector::at(int i) const
{
  if (i >= data.size())
  {
    throw new out_of_range("index out of range");
  }

  return data.at(i);
}

void Vector::setAt(int i, double dato)
{
  if (i >= data.size())
  {
    throw new out_of_range("index out of range");
  }
  data.at(i) = dato;
}

double Vector::getModule() const
{
  double mod = 0;
  for (auto elem : data)
  {
    mod += elem * elem;
  }
  return std::sqrt(mod);
}

Vector operator+(Vector const &a, Vector const &b)
{
  if (a.getSize() != b.getSize())
  {
    throw new runtime_error("operator+: Sizes must match");
  }

  Vector result{a.getSize()};
  for (int i = 0; i < a.getSize(); i++)
  {
    result.setAt(i, a.at(i) + b.at(i));
  }

  return result;
}
Vector operator-(Vector const &a, Vector const &b)
{
  if (a.getSize() != b.getSize())
  {
    throw new runtime_error("operator+: Sizes must match");
  }

  Vector result{a.getSize()};
  for (int i = 0; i < a.getSize(); i++)
  {
    result.setAt(i, a.at(i) - b.at(i));
  }

  return result;
}
double dotProduct(Vector const &a, Vector const &b)
{
  if (a.getSize() != b.getSize())
  {
    throw new runtime_error("operator+: Sizes must match");
  }

  Vector result{a.getSize()};
  for (int i{0}; i < a.getSize(); i++)
  {
    result.setAt(i, a.at(i) * b.at(i));
  }

  return result.getModule();
}

ostream &operator<<(ostream &os, Vector const &a)
{
  auto data = a.getSTDVector();
  os << "[ ";
  for (auto elem : data)
  {
    os << elem << " ";
  }
  os << "]";
  return os;
}