#include <gtest/gtest.h>
#include "../binarytree.h"

TEST(BinaryTreeTest, PushTest)
{
  // Create a binary tree
  shared_ptr<Node<int>> root = nullptr;
  insert<int>(5, root);
  insert<int>(3, root);
  insert<int>(7, root);
  insert<int>(2, root);
  insert<int>(4, root);
  insert<int>(6, root);

  // Check the root
  EXPECT_EQ(*root->pData, 5);
  EXPECT_EQ(*root->pLeft->pData, 3);
  EXPECT_EQ(*root->pRight->pData, 7);
  EXPECT_EQ(*root->pLeft->pLeft->pData, 2);
  EXPECT_EQ(*root->pLeft->pRight->pData, 4);
  EXPECT_EQ(*root->pRight->pLeft->pData, 6);
}

TEST(BinaryTreeTest, PushWithLambda)
{
  struct Person
  {
    string name;
    int age;
  };

  // the lambda function to compare the persons
  auto gt = [](Person const &a, Person const &b)
  { return a.age > b.age; };

  // insert the persons

  shared_ptr<Node<Person>> root = nullptr;

  insert<Person>(Person{"Juan", 20}, root, gt);
  insert<Person>(Person{"Pedro", 30}, root, gt);
  insert<Person>(Person{"Maria", 25}, root, gt);
  insert<Person>(Person{"Ana", 35}, root, gt);

  // Check the root
  EXPECT_EQ(root->pData->age, 20);
  EXPECT_EQ(root->pRight->pData->age, 30);
  EXPECT_EQ(root->pRight->pLeft->pData->age, 25);
  EXPECT_EQ(root->pRight->pRight->pData->age, 35);

  EXPECT_EQ(root->pData->name, "Juan");
  EXPECT_EQ(root->pRight->pData->name, "Pedro");
  EXPECT_EQ(root->pRight->pLeft->pData->name, "Maria");
  EXPECT_EQ(root->pRight->pRight->pData->name, "Ana");
}
