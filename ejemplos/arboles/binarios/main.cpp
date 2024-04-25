#include <memory>
#include <functional>
#include "binarytree.h"
using namespace std;

struct Person
{
  string name;
  int age;
};

int main()
{

  // the lambda function to compare the persons
  auto gt = [](Person const &a, Person const &b)
  { return a.age > b.age; };

  // insert the persons

  shared_ptr<Node<Person>> root = nullptr;

  insert<Person>(Person{"Juan", 20}, root, gt, nullptr);
  insert<Person>(Person{"Pedro", 30}, root, gt, nullptr);
  insert<Person>(Person{"Maria", 25}, root, gt);
  insert<Person>(Person{"Ana", 35}, root, gt);
  return 0;
}