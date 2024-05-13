#include "person.h"

Person::Person()
{
}

Person::Person(string const &name)
    : name(name)
{
}

string Person::getName() const
{
  return name;
}

void Person::setName(string const &name)
{
  this->name = name;
}

ostream &operator<<(ostream &os, Person const &p)
{
  os << p.getName();
  return os;
}