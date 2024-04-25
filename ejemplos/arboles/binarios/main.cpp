#include <memory>
#include <functional>
#include "binarytree.h"
#include <iostream>
#include "tictoc.h"

using namespace std;

struct Person
{
  string name;
  int age;
};

// pass size as argument
int main(int argc, char const *argv[])
{

  auto head = make_shared<Node<int>>(Node<int>(5));
  insert<int>(3, head);
  insert<int>(8, head);
  insert<int>(1, head);
  insert<int>(4, head);
  insert<int>(7, head);

  forEachPostOrder<int>(head, [](shared_ptr<Node<int>> node)
                        { cout << *(node->pData) << endl; });

  forEachPostOrder<int>(head, [](shared_ptr<Node<int>> node)
                        { node->pData = make_shared<int>(*(node->pData) * 2); });

  forEachPostOrder<int>(head, [](shared_ptr<Node<int>> node)
                        { cout << *(node->pData) << endl; });

  // auto elem = rand() % size;

  // cout << "Searching for element: " << elem << endl; // Debug output
  // clock.tic();
  // auto p = find<int>(elem, head);
  // cout << "Element " << (p ? "found" : "not found") << endl;
  // cout << "Tiempo transcurrido: " << clock.toc() << " ms" << endl;

  return 0;
}
