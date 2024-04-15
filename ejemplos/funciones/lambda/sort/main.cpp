#include <vector>
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

shared_ptr<vector<int>> bubbleSort(vector<int> const &v)
{
  auto sorted = make_shared<vector<int>>(v);
  for (int i = 0; i < sorted->size(); i++)
  {
    for (int j = 0; j < sorted->size() - i - 1; j++)
    {
      if (sorted->at(j) > sorted->at(j + 1))
      {
        swap(sorted->at(j), sorted->at(j + 1));
      }
    }
  }
  return sorted;
}

struct Person
{
  string name;
  int age;
};

shared_ptr<vector<Person>> bubbleSort(vector<Person> const &v, function<bool(Person const &p1, Person const &p2)> const &compare)
{
  auto sorted = make_shared<vector<Person>>(v);
  for (int i = 0; i < sorted->size(); i++)
  {
    for (int j = 0; j < sorted->size() - i - 1; j++)
    {
      if (compare(sorted->at(j), sorted->at(j + 1)))
      {
        swap(sorted->at(j), sorted->at(j + 1));
      }
    }
  }
  return sorted;
}

int main()
{
  vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  auto sorted = bubbleSort(v);
  for (auto const &i : *sorted)
  {
    cout << i << " ";
  }
  cout << endl;

  vector<Person> people = {{"Alice", 25}, {"Bob", 20}, {"Charlie", 30}};
  auto sortedPeopleByAge = bubbleSort(people, [](Person const &p1, Person const &p2)
                                      { return p1.age > p2.age; });
  for (auto const &p : *sortedPeopleByAge)
  {
    cout << p.name << " " << p.age << endl;
  }

  auto sortedPeopleByName = bubbleSort(people, [](Person const &p1, Person const &p2)
                                       { return p1.name > p2.name; });
  for (auto const &p : *sortedPeopleByName)
  {
    cout << p.name << " " << p.age << endl;
  }
  return 0;
}