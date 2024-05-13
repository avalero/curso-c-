#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
  Person();
  Person(string const &name);
  string getName() const;
  void setName(string const &name);

protected:
  string name;
};

ostream &operator<<(ostream &os, Person const &p);

#endif // PERSON_H