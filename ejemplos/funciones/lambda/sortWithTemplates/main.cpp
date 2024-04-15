#include <vector>
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

// templated function

template <typename T>
shared_ptr<vector<T>> bubbleSort(vector<T> const &v, function<bool(T const &p1, T const &p2)> const &compare)
{
  auto sorted = make_shared<vector<T>>(v);
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
  auto sorted = bubbleSort<int>(v, [](int const &p1, int const &p2)
                                { return p1 > p2; });

  cout << "Sorted vector" << endl;
  for (auto const &i : *sorted)
  {
    cout << i << " ";
  }

  struct Person
  {
    string name;
    int age;
  };

  vector<Person> people = {{"John", 21}, {"Jane", 20}, {"Alice", 22}};

  auto sortedPeople = bubbleSort<Person>(people, [](Person const &p1, Person const &p2)
                                         { return p1.age > p2.age; });

  cout << "Peolple sorted by age" << endl;
  for (auto const &p : *sortedPeople)
  {
    cout << p.name << " " << p.age << endl;
  }

  // sort by name
  auto sortedPeopleByName = bubbleSort<Person>(people, [](Person const &p1, Person const &p2)
                                               { return p1.name > p2.name; });

  cout << "Peolple sorted by name" << endl;
  for (auto const &p : *sortedPeopleByName)
  {
    cout << p.name << " " << p.age << endl;
  }

  return 0;
}