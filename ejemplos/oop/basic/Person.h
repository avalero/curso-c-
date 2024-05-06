#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
  friend bool operator<(Person const &p1, Person const &p2);
  friend ostream &operator<<(ostream &os, Person const &p);

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

bool operator<(Person const &p1, Person const &p2);
ostream &operator<<(ostream &os, Person const &p);

#endif