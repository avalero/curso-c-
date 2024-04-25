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
void forEachReverse(shared_ptr<Node<T>> pTail, function<void(T const &)> f)
{
  for (shared_ptr<Node<T>> p = pTail; p != nullptr; p = p->pPrev)
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
void push_front(shared_ptr<Node<T>> &pHead, T const &data)
{
  auto newNode = make_shared<Node<T>>(data, nullptr, pHead);
  if (pHead)
  {
    pHead->pPrev = newNode;
  }
  pHead = newNode;
}

template <typename T>
shared_ptr<Node<T>> pop_back(shared_ptr<Node<T>> &pHead)
{
  if (!pHead)
    return nullptr;

  if (!pHead->pNext)
  {
    auto retNode = pHead;
    if (pHead->pPrev)
    {
      pHead->pPrev->pNext = nullptr;
    }
    pHead = pHead->pPrev;
    return retNode;
  }
  else
  {
    return pop_back(pHead->pNext);
  }
}

template <typename T>
shared_ptr<Node<T>> pop_front(shared_ptr<Node<T>> &pHead)
{
  if (!pHead)
    return nullptr;

  auto retNode = pHead;
  pHead = pHead->pNext;
  if (pHead)
  {
    pHead->pPrev = nullptr;
  }
  return retNode;
}

template <typename T>
void insertAfter(shared_ptr<Node<T>> &p, T const &data)
{
  auto newNode = make_shared<Node<T>>(data, p, p->pNext);
  if (p->pNext)
    p->pNext->pPrev = newNode;
  p->pNext = newNode;
}

template <typename T>
void insertBefore(shared_ptr<Node<T>> &p, T const &data)
{
  auto newNode = make_shared<Node<T>>(data, p->pPrev, p);
  if (p->pPrev)
    p->pPrev->pNext = newNode;
  p->pPrev = newNode;
}

template <typename T>
void swapNodes(shared_ptr<Node<T>> &a, shared_ptr<Node<T>> &b)
{
  // Swap the data held by the nodes
  auto temp = a->pData;
  a->pData = b->pData;
  b->pData = temp;
}

template <typename T>
void bubbleSort(shared_ptr<Node<T>> &head, function<bool(shared_ptr<Node<T>>, shared_ptr<Node<T>>)> gt = [](shared_ptr<Node<T>> a, shared_ptr<Node<T>> b)
                                           { return *(a->pData) > *(b->pData); })
{
  bool swapped;
  shared_ptr<Node<T>> p;
  shared_ptr<Node<T>> lptr = nullptr;

  if (head == nullptr)
    return;

  do
  {
    swapped = false;
    p = head;

    while (p->pNext != lptr)
    {
      if (gt(p, p->pNext))
      {
        swapNodes(p, p->pNext);
        swapped = true;
      }
      p = p->pNext;
    }
    lptr = p;
  } while (swapped);
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

  bubbleSort<Person>(pHead, [](shared_ptr<Node<Person>> a, shared_ptr<Node<Person>> b)
                     { return a->pData->age > b->pData->age; });

  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });
}
