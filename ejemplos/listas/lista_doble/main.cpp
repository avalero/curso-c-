#include <memory>
#include <functional>
#include <iostream>
#include "tictoc.h"

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
void push_front(shared_ptr<Node<T>> &pHead, T const &data)
{
  // Create the new node with the current head as its next node.
  auto newHead = make_shared<Node<T>>(data, nullptr, pHead);

  // If the list isn't empty, set the previous pointer of the existing head.
  if (pHead)
  {
    pHead->pPrev = newHead;
  }

  // The new node becomes the new head of the list.
  pHead = newHead;
}

template <typename T>
void swapNodes(shared_ptr<Node<T>> &a, shared_ptr<Node<T>> &b)
{
  auto temp = a->pData;
  a->pData = b->pData;
  b->pData = temp;
}

template <typename T>
void bubbleSort(shared_ptr<Node<T>> &head, function<bool(T const &, T const &)> gt)
{
  bool swapped;
  do
  {
    swapped = false;
    for (auto p = head; p != nullptr && p->pNext != nullptr; p = p->pNext)
    {
      if (gt(*(p->pData), *(p->pNext->pData)))
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
  if (!head)
    return nullptr; // If the head is null, return immediately.

  auto start = head;
  auto end = tail ? tail : head; // If tail is nullptr, start from head to find the last node.

  // Find the last node if tail is not provided.
  while (end->pNext)
  {
    end = end->pNext;
  }

  while (start != nullptr && end != nullptr && start != end && start->pNext != end)
  {
    auto mid = start;
    auto temp = start;

    // Advance `mid` to the middle between `start` and `end`.
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
    else if (*mid->pData > key)
    { // Adjust comparison for descending order
      start = mid->pNext;
    }
    else
    {
      end = mid->pPrev;
    }
  }

  // Check at the boundaries if the loop exits without finding the key.
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

// pass size as argument
int main(int argc, char const *argv[])
{
  srand(time(0));
  auto size = argc > 1 ? atoi(argv[1]) : 100;
  auto elem = argc > 2 ? atoi(argv[2]) : rand() % size;
  shared_ptr<Node<int>> head = nullptr;
  cout << "Creando lista de " << size << " elementos ..." << endl;
  cout << "Elemento a buscar: " << elem << endl;

  TicToc clock;
  clock.tic();
  for (int i = 0; i <= size; i++)
  {
    push_front<int>(head, i);
    // cout << "Added: " << i << endl; // Debug output to see progress
  }
  cout << "Tiempo transcurrido: " << clock.toc() << " ms" << endl;

  cout << "Lista creada" << endl;

  cout << "Searching for element: " << elem << endl; // Debug output
  clock.tic();
  auto p = binarySearch<int>(head, nullptr, elem);
  cout << "Element " << (p ? "found" : "not found") << endl;
  cout << "Tiempo transcurrido: " << clock.toc() << " ms" << endl;

  return 0;
}
