#ifndef SRC_RATIONAL_EXPR_HPP_
#define SRC_RATIONAL_EXPR_HPP_

#include <ortools/linear_solver/linear_expr.h>

namespace optasio {
namespace flp {

using operations_research::LinearExpr;

bool linear_expr_is_nonzero(const LinearExpr& expr);

class RationalExpr {
 public:
  LinearExpr enumerator { 1 };
  LinearExpr denominator { 1 };

  explicit RationalExpr(LinearExpr enumerator = 1, LinearExpr denominator = 1)
    : enumerator(enumerator), denominator(denominator)
  {}

  bool is_valid() const;
  bool is_linear() const;
};


}  //  namespace flp
}  //  namespace optasio

#endif  //  SRC_RATIONAL_EXPR_HPP_
