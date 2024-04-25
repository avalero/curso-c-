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
  srand(time(0));
  auto size = argc > 1 ? atoi(argv[1]) : 100;
  shared_ptr<Node<int>> head = nullptr;
  cout << "Creando arbol de " << size << " elementos ..." << endl;

  TicToc clock;
  clock.tic();
  for (int i = 0; i <= size / 2; i++)
  {
    insert<int>(size / 2 - i, head);
    insert<int>(size / 2 + i, head);
  }
  cout << "Tiempo transcurrido: " << clock.toc() << " ms" << endl;

  cout << "Arbol creado" << endl;

  auto elem = rand() % size;

  cout << "Searching for element: " << elem << endl; // Debug output
  clock.tic();
  auto p = find<int>(elem, head);
  cout << "Element " << (p ? "found" : "not found") << endl;
  cout << "Tiempo transcurrido: " << clock.toc() << " ms" << endl;

  return 0;
}
