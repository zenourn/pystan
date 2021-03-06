#include "stan/math/functions/logical_negation.hpp"
#include <gtest/gtest.h>

TEST(MathFunctions,logical_negation) {
  using stan::math::logical_negation;
  EXPECT_TRUE(logical_negation(0));
  EXPECT_TRUE(logical_negation(0.0));
  EXPECT_TRUE(logical_negation(0.0f));

  EXPECT_FALSE(logical_negation(1));
  EXPECT_FALSE(logical_negation(2.0));
  EXPECT_FALSE(logical_negation(2.0f));
}
