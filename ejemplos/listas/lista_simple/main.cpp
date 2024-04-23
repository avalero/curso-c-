#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include "lista.h"

using namespace std;

struct Person
{
  string name;
  int age;
};

int main()
{

  shared_ptr<Node<Person>> pHead = make_shared<Node<Person>>(Person{"John", 30});
  push<Person>(pHead, Person{"Maria", 30});
  push<Person>(pHead, Person{"Luis", 21});

  shared_ptr<Node<Person>> other = make_shared<Node<Person>>(Person{"Lucia", 30});

  push<Person>(pHead, other);

  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });
}