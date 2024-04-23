#include <gtest/gtest.h>
#include "../lista.h"

TEST(ListaSimple, push)
{
  shared_ptr<Node<int>> pHead = make_shared<Node<int>>(1);
  push<int>(pHead, 2);
  push<int>(pHead, 3);
  push<int>(pHead, 4);
  push<int>(pHead, 5);
  push<int>(pHead, 6);
  push<int>(pHead, 7);
  push<int>(pHead, 8);
  push<int>(pHead, 9);
  push<int>(pHead, 10);

  int i = 1;
  forEach<int>(pHead, [&i](int const &data)
               { EXPECT_EQ(data, i++); });
}

TEST(ListaSimple, filter)
{
  shared_ptr<Node<int>> pHead = make_shared<Node<int>>(1);
  push<int>(pHead, 2);
  push<int>(pHead, 3);
  push<int>(pHead, 4);
  push<int>(pHead, 5);
  push<int>(pHead, 6);
  push<int>(pHead, 7);
  push<int>(pHead, 8);
  push<int>(pHead, 9);
  push<int>(pHead, 10);

  // print all
  forEach<int>(pHead, [](int const &data)
               { cout << data << endl; });

  // shared_ptr<Node<int>> pFiltered = filter<int>(pHead, [](int const &data)
  // {
  //   return data % 2 == 0;
  // });

  int i = 2;
  // forEach<int>(pFiltered, [&i](int const &data)
  //              {
  //               cout << i << " - " << data << endl;
  //               EXPECT_EQ(data, i);
  //               i += 2; });
}
