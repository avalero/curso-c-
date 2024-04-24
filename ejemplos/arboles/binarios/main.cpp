#include <memory>
#include <functional>

using namespace std;

template <typename T>
struct Node
{
  Node(T data, shared_ptr<Node<T>> left = nullptr, shared_ptr<Node<T>> right = nullptr) : pData(make_shared<T>(data)), pLeft(left), pRight(right) {}
  Node(shared_ptr<T> data, shared_ptr<Node<T>> left = nullptr, shared_ptr<Node<T>> right = nullptr) : pData(data), pLeft(left), pRight(right) {}
  shared_ptr<T> pData;
  shared_ptr<Node<T>> pLeft;
  shared_ptr<Node<T>> pRight;
};

/**
 * @brief Insert a new node in the binary tree
 * @param data The data to insert
 * @param root The root of the binary tree
 * @param gt The function to compare the data
 * @return The new node
 * @tparam T The type of the data
 * @example auto root = insert(5, nullptr);
 * @example auto root = insert(5, nullptr, rootNode);
 * @example auto root = insert(5, rootNode, [](int const &a, int const &b) { return a > b; });
 *
 */
template <typename T>
shared_ptr<Node<T>> insert(T const &data, shared_ptr<Node<T>> &root, function<bool(T const &, T const &)> gt = [](T const &a, T const &b)
                                                                     { return a > b; })
{
  if (root == nullptr)
  {
    root = make_shared<Node<T>>(Node<T>(data));
    return root;
  }
  else
  {
    if (gt(data, *root->pData))
    {
      root->pRight = insert<T>(data, root->pRight, gt);
      return root->pRight;
    }
    else
    {
      root->pLeft = insert<T>(data, root->pLeft, gt);
      return root->pLeft;
    }
  }
}

struct Person
{
  string name;
  int age;
};

int main()
{

  // the lambda function to compare the persons
  auto gt = [](Person const &a, Person const &b)
  { return a.age > b.age; };

  // insert the persons

  shared_ptr<Node<Person>> root = nullptr;

  insert<Person>(Person{"Juan", 20}, root, gt);
  insert<Person>(Person{"Pedro", 30}, root, gt);
  insert<Person>(Person{"Maria", 25}, root, gt);
  insert<Person>(Person{"Ana", 35}, root, gt);
  return 0;
}