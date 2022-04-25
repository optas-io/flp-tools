#include <gtest/gtest.h>

#include "rational_expr.hpp"


using optasio::flp::RationalExpr;

TEST(RationalExprTest, DefaultConstructor) {
  RationalExpr expr = RationalExpr();
  EXPECT_EQ(expr.enumerator.offset(), 1);
  EXPECT_EQ(expr.enumerator.terms().size(), 0);
  EXPECT_EQ(expr.denominator.offset(), 1);
  EXPECT_EQ(expr.denominator.terms().size(), 0);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_TRUE(expr.is_linear());
}
