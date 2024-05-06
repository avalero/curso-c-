#include "Person.h"
#include <exception>

Person::Person()
{
  std::cout << "Soy el constructor por defecto" << endl;
  name = "";
  age = 0;
  telephone = "";
}

Person::Person(string const &n, int a, string const &t)
{
  std::cout << "Soy el constructor parametrizado" << endl;
  setName(n);
  setAge(a);
  setTelephone(t);
}

void Person::setName(string const &n)
{
  name = n;
}

void Person::setAge(int a)
{
  if (a < 0)
    throw std::runtime_error("Age must be greater than 0");
  age = a;
}

void Person::setTelephone(string const &t)
{
  if (t.length() < 9 || t.length() > 13)
    throw std::runtime_error("Telephone must have between 9 and 13 characters");
  telephone = t;
}
