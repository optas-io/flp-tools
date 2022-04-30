#include <gtest/gtest.h>

#include "rational_expr.hpp"
#include "flp_solver.hpp"


using operations_research::LinearExpr;
using optasio::flp::RationalExpr;
using optasio::flp::FLPSolver;


TEST(RationalExprTest, DefaultConstructor) {
  // Act
  RationalExpr expr = RationalExpr();
  // Assert
  EXPECT_EQ(expr.enumerator.offset(), 1);
  EXPECT_EQ(expr.enumerator.terms().size(), 0);
  EXPECT_EQ(expr.denominator.offset(), 1);
  EXPECT_EQ(expr.denominator.terms().size(), 0);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_TRUE(expr.is_linear());
}

TEST(RationalExprTest, LinearConstructor) {
  // Arrange
  FLPSolver solver = FLPSolver("TestSolver");
  LinearExpr x = solver.MakeVar(0.0, 1.0, false, "x");
  LinearExpr y = solver.MakeVar(0.0, 1.0, false, "y");
  LinearExpr enumerator = 2 * x + 42 * y;
  // Act
  RationalExpr expr = RationalExpr(enumerator);
  // Assert
  EXPECT_EQ(expr.enumerator.offset(), 0);
  EXPECT_EQ(expr.enumerator.terms().size(), 2);
  EXPECT_EQ(expr.denominator.offset(), 1);
  EXPECT_EQ(expr.denominator.terms().size(), 0);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_TRUE(expr.is_linear());
}

TEST(RationalExprTest, FullConstructor) {
  // Arrange
  FLPSolver solver = FLPSolver("TestSolver");
  LinearExpr x = solver.MakeVar(0.0, 1.0, false, "x");
  LinearExpr y = solver.MakeVar(0.0, 1.0, false, "y");
  LinearExpr enumerator = 2 * x + 42 * y;
  LinearExpr denominator = 42 * x + 2 * y;
  // Act
  RationalExpr expr = RationalExpr(enumerator, denominator);
  // Assert
  EXPECT_EQ(expr.enumerator.offset(), 0);
  EXPECT_EQ(expr.enumerator.terms().size(), 2);
  EXPECT_EQ(expr.denominator.offset(), 0);
  EXPECT_EQ(expr.denominator.terms().size(), 2);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_FALSE(expr.is_linear());
}

TEST(RationalExprTest, DivisionOfLinearExpr) {
  // Arrange
  FLPSolver solver = FLPSolver("TestSolver");
  LinearExpr x = solver.MakeVar(0.0, 1.0, false, "x");
  LinearExpr y = solver.MakeVar(0.0, 1.0, false, "y");
  // Act
  RationalExpr expr = (2 * x + 42 * y) / (42 * x + 2 * y);
  // Assert
  EXPECT_EQ(expr.enumerator.offset(), 0);
  EXPECT_EQ(expr.enumerator.terms().size(), 2);
  EXPECT_EQ(expr.denominator.offset(), 0);
  EXPECT_EQ(expr.denominator.terms().size(), 2);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_FALSE(expr.is_linear());
}

TEST(RationalExprTest, DivisionOfLinearExpr2) {
  // Arrange
  FLPSolver solver = FLPSolver("TestSolver");
  LinearExpr x = solver.MakeVar(0.0, 1.0, false, "x");
  LinearExpr y = solver.MakeVar(0.0, 1.0, false, "y");
  // Act
  RationalExpr expr = 1 / (42 * x + 2 * y);
  // Assert
  EXPECT_EQ(expr.enumerator.offset(), 1);
  EXPECT_EQ(expr.enumerator.terms().size(), 0);
  EXPECT_EQ(expr.denominator.offset(), 0);
  EXPECT_EQ(expr.denominator.terms().size(), 2);
  EXPECT_TRUE(expr.is_valid());
  EXPECT_FALSE(expr.is_linear());
}

