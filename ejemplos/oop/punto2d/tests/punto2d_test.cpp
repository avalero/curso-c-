#include <gtest/gtest.h>
#include "../Punto2d.h"
#include <cmath>

TEST(DefaultConstructor, DefaultConstructor_def_Test)
{
  Punto2d p;
  // expect similar values
  EXPECT_NEAR(0, p.getX(), 0.0001);
  EXPECT_NEAR(0, p.getY(), 0.0001);
  EXPECT_NEAR(0, p.getR(), 0.0001);
  EXPECT_NEAR(0, p.getTheta(), 0.0001);
  EXPECT_NEAR(0, p.getModule(), 0.0001);
}

TEST(ParametrizedConstructor, ParametrizedConstructor_def_Test)
{
  Punto2d p(3, 4);
  EXPECT_NEAR(3, p.getX(), 0.0001);
  EXPECT_NEAR(4, p.getY(), 0.0001);
  EXPECT_NEAR(sqrt(3 * 3 + 4 * 4), p.getR(), 0.0001);
  EXPECT_NEAR(3 / sqrt(3 * 3 + 4 * 4), cos(p.getTheta()), 0.0001);
  EXPECT_NEAR(sqrt(3 * 3 + 4 * 4), p.getModule(), 0.0001);
}

TEST(ParametrizedConstructor, ParametrizedConstructor_polar_false_Test)
{
  Punto2d p(3, 4, false);
  EXPECT_NEAR(3, p.getX(), 0.0001);
  EXPECT_NEAR(4, p.getY(), 0.0001);
  EXPECT_NEAR(sqrt(3 * 3 + 4 * 4), p.getR(), 0.0001);
  EXPECT_NEAR(p.getX() / p.getR(), cos(p.getTheta()), 0.0001);
  EXPECT_NEAR(sqrt(3 * 3 + 4 * 4), p.getModule(), 0.0001);
}

TEST(ParametrizedConstructor, ParametrizedConstructor_polar_true_Test)
{
  Punto2d p(3, 4, true);
  EXPECT_NEAR(3, p.getR(), 0.0001);
  // EXPECT_NEAR(4, p.getTheta(), 0.0001);
  EXPECT_NEAR(3 * cos(4), p.getX(), 0.0001);
  EXPECT_NEAR(3 * sin(4), p.getY(), 0.0001);
  EXPECT_NEAR(3, p.getModule(), 0.0001);
}