#include "Node.h"
#include <exception>

using namespace std;

Node::Node(double x, double y) : data{Point{x, y}} {}

Edge Node::getEdge(int i) const
{
  if (i < 0 || i >= edges.size())
  {
    throw out_of_range("Index out of range");
  }
  return edges[i];
}

vector<Edge> Node::getEdges() const
{
  return edges;
}

Point Node::getData() const
{
  return data;
}

bool Node::edgeExists(Edge const &edg) const
{
  for (auto &existingEdg : edges)
  {
    if (edg.node == existingEdg.node)
    {
      return true;
    }
  }
  return false;
}

void Node::addEdge(vector<Edge> const &eds)
{
  vector<Edge> neweds;
  for (auto &edge : eds)
  {
    if (!edgeExists(edge))
      edges.push_back(edge);
  }
}

void Node::addEdge(Edge const &edge)
{
  if (!edgeExists(edge))
    edges.push_back(edge);
}

void Node::setData(Point const &d)
{
  data = d;
}

ostream &operator<<(ostream &os, Point const &p)
{
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}
ostream &operator<<(ostream &os, Edge const &e)
{
  os << "Node: " << e.node->getData() << " Cost: " << e.cost;
  return os;
}
ostream &operator<<(ostream &os, Node const &n)
{
  os << "Node: " << n.getData() << " Edges: ";
  for (auto &edge : n.getEdges())
  {
    os << edge << " ";
  }
  return os;
}