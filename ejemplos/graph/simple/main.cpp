#include "Node.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  shared_ptr<Node> n1 = make_shared<Node>(1, 2);
  shared_ptr<Node> n2 = make_shared<Node>(3, 4);
  shared_ptr<Node> n3 = make_shared<Node>(5, 6);
  shared_ptr<Node> n4 = make_shared<Node>(7, 8);

  vector<shared_ptr<Node>> nodes{n1, n2, n3, n4};

  Edge e0{n1, 1};
  Edge e1{n2, 2};
  Edge e2{n3, 3};
  Edge e3{n4, 4};

  n1->addEdge(e1);
  n2->addEdge(e2);
  n3->addEdge(e3);
  n4->addEdge(e0);

  for (auto &node : nodes)
  {
    cout << *node << endl;
  }
}