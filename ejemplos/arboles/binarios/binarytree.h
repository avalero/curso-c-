#include <memory>
#include <functional>

using namespace std;

/**
 * @brief The node of the binary tree
 * @tparam T The type of the data
 * @example auto node = make_shared<Node<int>>(Node<int>(5));
 * @example auto node = make_shared<Node<int>>(Node<int>(5, leftNode, rightNode));
 * @example auto node = make_shared<Node<int>>(Node<int>(5, make_shared<Node<int>>(Node<int>(4)), make_shared<Node<int>>(Node<int>(6))));

*/
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
  }
  else
  {
    if (gt(data, *root->pData))
    {
      insert<T>(data, root->pRight, gt);
    }
    else
    {
      insert<T>(data, root->pLeft, gt);
    }
  }
  return root;
}

template <typename T>
shared_ptr<Node<T>> find(T const &data, shared_ptr<Node<T>> const &root, function<bool(T const &, T const &)> f = [](T const &a, T const &b)
                                                                         { return a == b; },
                         function<bool(T const &, T const &)> gt = [](T const &a, T const &b)
                         { return a > b; })
{
  if (root == nullptr)
  {
    return nullptr;
  }
  else
  {
    if (f(data, *root->pData))
    {
      return root;
    }
    else if (gt(data, *root->pData))
    {
      return find<T>(data, root->pRight, gt);
    }
    else
    {
      return find<T>(data, root->pLeft, gt);
    }
  }
}
