
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
  Node(T const &data,
       shared_ptr<Node<T>> const &prev = nullptr,
       shared_ptr<Node<T>> const &next = nullptr) : pData(make_shared<T>(data)), pNext(next), pPrev(prev)
  {
  }
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
  if (pHead->pNext == nullptr)
  {
    pHead->pNext = make_shared<Node<T>>(data);
    pHead->pNext->pPrev = pHead;
  }
  else
  {
    push_back(pHead->pNext, data);
  }
}

template <typename T>
void push_back(shared_ptr<Node<T>> &pHead, shared_ptr<Node<T>> &pNew)
{
  if (pHead->pNext == nullptr)
  {
    pHead->pNext = pNew;
    pNew->pPrev = pHead;
  }
  else
  {
    push_back(pHead->pNext, pNew);
  }
}

template <typename T>
void push_front(shared_ptr<Node<T>> &p, T const &data)
{
  if (p->pPrev == nullptr)
  {
    p->pPrev = make_shared<Node<T>>(data);
    p->pPrev->pNext = p;
  }
  else
  {
    push_front(p->pPrev, data);
  }
}

template <typename T>
void push_front(shared_ptr<Node<T>> &p, shared_ptr<Node<T>> &pNew)
{
  if (p->pPrev == nullptr)
  {
    p->pPrev = pNew;
  }
  else
  {
    push_front(p->pPrev, pNew);
  }
}

template <typename T>
shared_ptr<Node<T>> pop_back(shared_ptr<Node<T>> &p)
{
  if (p->pNext == nullptr)
  {
    p->pPrev->pNext = nullptr;
    return p;
  }
  else
  {
    return pop_back(p->pNext);
  }
}

template <typename T>
shared_ptr<Node<T>> pop_front(shared_ptr<Node<T>> &p)
{
  if (p->pPrev == nullptr)
  {
    p->pNext->pPrev = nullptr;
    return p;
  }
  else
  {
    return pop_front(p->pPrev);
  }
}

template <typename T>
void insertAfter(shared_ptr<Node<T>> &p, T const &data)
{
  shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data, p, p->pNext);
  p->pNext->pPrev = newNode;
  p->pNext = newNode;
}

template <typename T>
void insertAfter(shared_ptr<Node<T>> &p, shared_ptr<Node<T>> &newNode)
{
  newNode->pPrev = p;
  newNode->pNext = p->pNext;
  p->pNext->pPrev = newNode;
  p->pNext = newNode;
}

template <typename T>
void insertBefore(shared_ptr<Node<T>> &p, T const &data)
{
  shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data, p->pPrev, p);
  p->pPrev->pNext = newNode;
  p->pPrev = newNode;
}

template <typename T>
void insertBefore(shared_ptr<Node<T>> &p, shared_ptr<Node<T>> &newNode)
{
  newNode->pPrev = p->pPrev;
  newNode->pNext = p;
  p->pPrev->pNext = newNode;
  p->pPrev = newNode;
}

template <typename T>
shared_ptr<Node<T>> filter(shared_ptr<Node<T>> const &pHead, function<bool(T const &)> f)
{
  shared_ptr<Node<T>> newHead = nullptr;
  for (auto it = pHead; it != nullptr; it = it->pNext)
  {
    if (f(*(it->pData)))
    {
      if (newHead == nullptr)
        newHead = it;
      else
        push(newHead, it);
    }
  }
  return newHead;
}

struct Person
{
  string name;
  int age;
};

int main()
{

  shared_ptr<Node<Person>> pHead = make_shared<Node<Person>>(Person{"John", 30});
  push_back<Person>(pHead, Person{"Maria", 30});
  push_back<Person>(pHead, Person{"Luis", 21});

  shared_ptr<Node<Person>> other = make_shared<Node<Person>>(Person{"Lucia", 30});

  push_back<Person>(pHead, other);
  insertAfter<Person>(pHead->pNext, Person{"Pedro", 30});

  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });
}