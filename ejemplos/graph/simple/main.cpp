#include "Node.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

bool removeNode(vector<shared_ptr<Node>> &nodes, shared_ptr<Node> node)
{
  for (auto it = nodes.begin(); it != nodes.end(); ++it)
  {
    if (*it == node)
    {
      nodes.erase(it);
      for (auto &n : nodes)
      {
        n->removeEdge(node);
      }
      return true;
    }
  }
  return false;
}

int main()
{
  shared_ptr<Node> n1 = make_shared<Node>(1, 2);
  shared_ptr<Node> n2 = make_shared<Node>(3, 4);
  shared_ptr<Node> n3 = make_shared<Node>(5, 6);
  shared_ptr<Node> n4 = make_shared<Node>(7, 8);

  vector<shared_ptr<Node>> nodes{n1, n2, n3, n4};

  auto const_function = [](shared_ptr<Node> const &a, shared_ptr<Node> const &b)
  { return b->getData() - a->getData(); };

  Edge e0{n4, n1, const_function};
  Edge e1{n1, n2, const_function};
  Edge e2{n2, n3, const_function};
  Edge e3{n3, n4, const_function};

  n1->addEdge(e1);
  n2->addEdge(e2);
  n3->addEdge(e3);
  n4->addEdge(e0);

  for (auto &node : nodes)
  {
    cout << *node << endl;
  }
}