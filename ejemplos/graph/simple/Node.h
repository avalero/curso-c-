#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Node;

struct Point
{
  double x;
  double y;
};

double operator-(Point const &a, Point const &b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

class Edge
{
public:
  Edge(
      shared_ptr<Node> n1,
      shared_ptr<Node> n2,
      function<double(shared_ptr<Node> const &, shared_ptr<Node> const &)> f = [](shared_ptr<Node> const &a, shared_ptr<Node> const &b)
      { return 0; })
  {
    node = n2;
    cost = f(n1, n2);
  }
  shared_ptr<Node> node;
  double cost;
};

class Node
{
public:
  Node(double x, double y);
  Edge getEdge(int i) const;
  vector<Edge> getEdges() const;
  Point getData() const;

  void addEdge(vector<Edge> const &eds);
  void addEdge(Edge const &e);
  void setData(Point const &d);

  bool removeEdge(shared_ptr<Node> const &node);

private:
  bool edgeExists(Edge const &edg) const;
  Point data;
  vector<Edge> edges;
};

ostream &operator<<(ostream &os, Point const &p);
ostream &operator<<(ostream &os, Edge const &e);
ostream &operator<<(ostream &os, Node const &n);

#endif