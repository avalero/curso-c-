#include "splitstring.h"
#include <gtest/gtest.h>

TEST(SplitString, splitString)
{
  string s = "this is a test";
  auto tokens = splitString(s, ' ');
  EXPECT_EQ(tokens.size(), 4);
  EXPECT_EQ(tokens[0], "this");
  EXPECT_EQ(tokens[1], "is");
  EXPECT_EQ(tokens[2], "a");
  EXPECT_EQ(tokens[3], "test");
}