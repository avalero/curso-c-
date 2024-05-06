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
  shared_ptr<Node<T>> pParent;
};

/**
 * @brief Insert a new node in the binary tree
 * @param data The data to insert
 * @param root The root of the binary tree
 * @param gt The function to compare the data
 * @param parent The parent of the new node
 * @return The new node
 * @tparam T The type of the data
 * @example auto root = insert(5, nullptr);
 * @example auto root = insert(5, nullptr, rootNode);
 * @example auto root = insert(5, rootNode, [](int const &a, int const &b) { return a > b; });
 *
 */
template <typename T>
shared_ptr<Node<T>> insert(T const &data, shared_ptr<Node<T>> &pRoot, function<bool(T const &, T const &)> gt = [](T const &a, T const &b)
                                                                      { return a > b; },
                           shared_ptr<Node<T>> pParent = nullptr)
{
  if (pRoot == nullptr)
  {
    pRoot = make_shared<Node<T>>(Node<T>(data));
    pRoot->pParent = pParent; // Set the parent of the newly created node
  }
  else
  {
    if (gt(data, *pRoot->pData))
    {
      // Recursive call to insert on the right subtree
      insert<T>(data, pRoot->pRight, gt, pRoot); // Pass current root as parent for the right child
    }
    else
    {
      // Recursive call to insert on the left subtree
      insert<T>(data, pRoot->pLeft, gt, pRoot); // Pass current root as parent for the left child
    }
  }
  return pRoot;
}

template <typename T>
void forEachPostOrder(shared_ptr<Node<T>> pHead, function<void(shared_ptr<Node<T>> const &)> f)
{
  if (pHead == nullptr)
    return;

  forEachPostOrder<T>(pHead->pLeft, f);
  f(pHead);
  forEachPostOrder<T>(pHead->pRight, f);

  return;
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
