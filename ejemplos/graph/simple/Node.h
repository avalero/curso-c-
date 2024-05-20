#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class Node;

struct Point
{
  double x;
  double y;
};

struct Edge
{
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

private:
  bool edgeExists(Edge const &edg) const;
  Point data;
  vector<Edge> edges;
};

ostream &operator<<(ostream &os, Point const &p);
ostream &operator<<(ostream &os, Edge const &e);
ostream &operator<<(ostream &os, Node const &n);

#endif