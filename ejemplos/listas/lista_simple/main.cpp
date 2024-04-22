
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
  Node(T const &data, shared_ptr<Node<T>> const &next = nullptr) : pData(make_shared<T>(data)), pNext(next)
  {
  }
  shared_ptr<T> pData;
  shared_ptr<Node<T>> pNext;
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
void push(shared_ptr<Node<T>> &pHead, T const &data)
{
  if (pHead->pNext == nullptr)
  {
    pHead->pNext = make_shared<Node<T>>(data);
  }
  else
  {
    push(pHead->pNext, data);
  }
}

template <typename T>
void push(shared_ptr<Node<T>> &pHead, shared_ptr<Node<T>> &newNode)
{
  if (pHead->pNext == nullptr)
  {
    pHead->pNext = newNode;
  }
  else
  {
    push(pHead->pNext, newNode);
  }
}

template <typename T>
shared_ptr<Node<T>> filter(shared_ptr<Node<T>> const &pHead, function<bool(T const &)> f)
{
  shared_ptr<Node<T>> newHead = nullptr;
  for (auto it = pHead; it != nullptr; it = it->pNext)
  {
    if (f(*(p->pData)))
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
  push<Person>(pHead, Person{"Maria", 30});
  push<Person>(pHead, Person{"Luis", 21});

  shared_ptr<Node<Person>> other = make_shared<Node<Person>>(Person{"Lucia", 30});

  push<Person>(pHead, other);

  forEach<Person>(pHead, [](Person const &p)
                  { cout << p.name << "-" << p.age << endl; });
}