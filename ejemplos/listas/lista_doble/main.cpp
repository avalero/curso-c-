#include <memory>
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
  Node(T const &data, shared_ptr<Node<T>> const &prev = nullptr, shared_ptr<Node<T>> const &next = nullptr)
      : pData(make_shared<T>(data)), pNext(next), pPrev(prev) {}
  shared_ptr<T> pData;
  shared_ptr<Node<T>> pNext;
  shared_ptr<Node<T>> pPrev;
};

template <typename T>
void forEach(shared_ptr<Node<T>> pHead, function<void(T const &)> f)
{
  for (shared_ptr<Node<T>> p = pHead; p != nullptr; p = p->pNext)
  {
    f(*(p->pData));
  }
}

template <typename T>
void push_back(shared_ptr<Node<T>> &pHead, T const &data)
{
  if (!pHead)
  {
    pHead = make_shared<Node<T>>(data);
  }
  else if (!pHead->pNext)
  {
    pHead->pNext = make_shared<Node<T>>(data, pHead);
  }
  else
  {
    push_back(pHead->pNext, data);
  }
}

template <typename T>
void bubbleSort(shared_ptr<Node<T>> &head, function<bool(shared_ptr<T>, shared_ptr<T>)> gt)
{
  bool swapped;
  shared_ptr<Node<T>> p;
  shared_ptr<Node<T>> lptr = nullptr;

  if (!head)
    return;

  do
  {
    swapped = false;
    p = head;

    while (p->pNext != lptr)
    {
      if (gt(p->pData, p->pNext->pData))
      {
        swapNodes(p, p->pNext);
        swapped = true;
      }
      p = p->pNext;
    }
    lptr = p;
  } while (swapped);
}

template <typename T>
void swapNodes(shared_ptr<Node<T>> &a, shared_ptr<Node<T>> &b)
{
  // Swap the data held by the nodes
  auto temp = a->pData;
  a->pData = b->pData;
  b->pData = temp;
}

struct Person
{
  string name;
  int age;

  friend ostream &operator<<(ostream &os, const Person &p)
  {
    os << p.name << "-" << p.age;
    return os;
  }
};

int main()
{
  shared_ptr<Node<Person>> pHead = make_shared<Node<Person>>(Person{"John", 30});
  push_back(pHead, Person{"Maria", 35});
  push_back(pHead, Person{"Luis", 21});

  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });

  bubbleSort<Person>(pHead, [](shared_ptr<Person> a, shared_ptr<Person> b)
                     { return a->age > b->age; });

  cout << "After sorting:" << endl;
  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });
}
