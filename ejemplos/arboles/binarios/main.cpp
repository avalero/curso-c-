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
shared_ptr<Node<T>> insert(T data, shared_ptr<Node<T>> &root, function<bool(T const &, T const &)> gt = [](T const &a, T const &b)
                                                              { return a > b; })
{
  if (root == nullptr)
  {
    root = Node(data);
    return root;
  }
  else
  {
    if (gt(data, *(root->data)))
    {
      if (root->pRight == nullptr)
      {
        root->pRight = Node(data);
        return root->pRight;
      }
      else
      {
        return insert(root->pRight);
      }
    }
    else
    {
      if (root->pLeft == nullptr)
      {
        root->pLeft == Node(data);
        return root->pLeft;
      }
      else
      {
        return insert(root->pLeft);
      }
    }
  }
}

int main()
{
  ;
}