#include "flp_solver.hpp"

#include <gtest/gtest.h>

using optasio::flp::FLPSolver;


TEST(FLPSolverInit, BasicTests) {
  FLPSolver solver = FLPSolver("Test");
  EXPECT_EQ(solver.message(), "Hello, World!");
}
