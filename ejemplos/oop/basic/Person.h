#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
public:
  // constructor
  Person();
  Person(string const &n, int a, string const &t);

  // setter functions
  void setName(string const &n);
  void setAge(int a);
  void setTelephone(string const &t);

  // getter functions
  string getName() const { return name; }
  int getAge() const { return age; };
  string getTelephone() const { return telephone; };

private:
  string name;
  int age;
  string telephone;
};

#endif