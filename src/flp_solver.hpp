// Copyright 2022 Sebastian Winkler

#ifndef SRC_FLP_SOLVER_HPP_
#define SRC_FLP_SOLVER_HPP_

#include <ortools/linear_solver/linear_solver.h>

#include <string>

namespace optasio {
namespace flp {

class FLPSolver: public operations_research::MPSolver {
 public:
  FLPSolver(
    const std::string& name,
    OptimizationProblemType type = OptimizationProblemType::SCIP_MIXED_INTEGER_PROGRAMMING
  ) : MPSolver(name, type) {}

  std::string message() const;
};

}  // namespace flp
}  // namespace optasio
#endif  // SRC_FLP_SOLVER_HPP_
