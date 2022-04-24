#include "flp_solver.hpp"

#include <gtest/gtest.h>

using optasio::flp::FLPSolver;
using operations_research::MPSolver;


TEST(FLPSolverInit, BasicTests) {
  FLPSolver solver = FLPSolver(
      "Test",
      MPSolver::OptimizationProblemType::SCIP_MIXED_INTEGER_PROGRAMMING);
  EXPECT_EQ(solver.message(), "Hello, World!");
}
