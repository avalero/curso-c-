#include "Node.h"
#include <memory>
#include <vector>
#include <iostream>
#include <limits>
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

vector<shared_ptr<Node>> getPath(shared_ptr<Node> dest)
{
  vector<shared_ptr<Node>> path;
  path.push_back(dest);
  auto prev = dest->getPrevious();
  while (prev != nullptr)
  {
    path.push_back(prev);
    prev = prev->getPrevious();
  }

  // reverse
  vector<shared_ptr<Node>> reversedPath;
  for (auto it = path.rbegin(); it != path.rend(); ++it)
  {
    reversedPath.push_back(*it);
  }
  return reversedPath;
}

void computeDijkstra(vector<shared_ptr<Node>> &nodes, shared_ptr<Node> start)
{
  // set all pathcosts to max double
  for (auto &node : nodes)
  {
    node->setPathCost(std::numeric_limits<double>::max());
  }
  vector<shared_ptr<Node>> unvisited = nodes;
  vector<shared_ptr<Node>> visited;
  start->setPathCost(0);
  start->setPrevious(nullptr);

  while (!unvisited.empty())
  {

    shared_ptr<Node> current = unvisited[0];
    // go to the shortest path not visited node
    for (auto &node : unvisited)
    {
      if (node->getPathCost() < current->getPathCost())
      {
        current = node;
      }
    }

    // mark current as visited (definitely the most short path to it is found)
    visited.push_back(current);
    // remove current from unvisited as we do not need to visit it again
    for (auto it = unvisited.begin(); it != unvisited.end(); ++it)
    {
      if (*it == current)
      {
        unvisited.erase(it);
        break;
      }
    }

    // update the cost of the neighbors of current
    for (auto &edge : current->getEdges())
    {
      // check not visited
      if (find(visited.begin(), visited.end(), edge.node) != visited.end())
      {
        continue;
      }

      double newCost = current->getPathCost() + edge.cost;
      if (newCost < edge.node->getPathCost())
      {
        edge.node->setPathCost(newCost);
        edge.node->setPrevious(current);
      }
    }
  }
}

int main()
{
  shared_ptr<Node> n1 = make_shared<Node>(1, 2);
  shared_ptr<Node> n2 = make_shared<Node>(3, 4);
  shared_ptr<Node> n3 = make_shared<Node>(5, 6);
  shared_ptr<Node> n4 = make_shared<Node>(7, 8);

  vector<shared_ptr<Node>> nodes{n1, n2, n3, n4};

  auto cost_function = [](shared_ptr<Node> const &a, shared_ptr<Node> const &b)
  { return b->getData() - a->getData(); };

  Edge e0{n4, n1, cost_function};
  Edge e1{n1, n2, cost_function};
  Edge e2{n2, n3, cost_function};
  Edge e3{n3, n4, cost_function};

  n1->addEdge(e1);
  n2->addEdge(e2);
  n3->addEdge(e3);
  n4->addEdge(e0);

  for (auto &node : nodes)
  {
    cout << *node << endl;
  }
}