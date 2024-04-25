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
void swapNodes(shared_ptr<Node<T>> &a, shared_ptr<Node<T>> &b)
{
  auto temp = a->pData;
  a->pData = b->pData;
  b->pData = temp;
}

template <typename T>
void bubbleSort(shared_ptr<Node<T>> &head, function<bool(shared_ptr<T>, shared_ptr<T>)> gt)
{
  bool swapped;
  do
  {
    swapped = false;
    for (auto p = head; p != nullptr && p->pNext != nullptr; p = p->pNext)
    {
      if (gt(p->pData, p->pNext->pData))
      {
        swapNodes(p, p->pNext);
        swapped = true;
      }
    }
  } while (swapped);
}

template <typename T>
shared_ptr<Node<T>> binarySearch(shared_ptr<Node<T>> head, shared_ptr<Node<T>> tail, T const &key)
{
  auto start = head;
  auto end = tail;

  while (start != nullptr && end != nullptr && start != end && start->pNext != end)
  {
    auto mid = start;
    auto temp = start;

    while (temp != end && temp->pNext != end)
    {
      temp = temp->pNext->pNext;
      if (temp)
      {
        mid = mid->pNext;
      }
    }

    if (*mid->pData == key)
    {
      return mid;
    }
    else if (*mid->pData < key)
    {
      start = mid->pNext;
    }
    else
    {
      end = mid->pPrev;
    }
  }

  if (start && *start->pData == key)
  {
    return start;
  }

  if (end && *end->pData == key)
  {
    return end;
  }

  return nullptr; // Key not found
}

struct Person
{
  string name;
  int age;
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
