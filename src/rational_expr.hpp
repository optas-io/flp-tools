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

  RationalExpr(LinearExpr enumerator = 1, LinearExpr denominator = 1)  // NOLINT : implicit conversion intentional
    : enumerator(enumerator), denominator(denominator)
  {}

  bool is_valid() const;
  bool is_linear() const;

  RationalExpr& operator+=(double rhs);
  RationalExpr& operator-=(double rhs);
  RationalExpr& operator*=(double rhs);
  RationalExpr& operator/=(double rhs);
  RationalExpr operator-() const;
};

RationalExpr operator+(RationalExpr lhs, double rhs);
RationalExpr operator+(double lhs, RationalExpr rhs);
RationalExpr operator-(RationalExpr lhs, double rhs);
RationalExpr operator-(double lhs, RationalExpr rhs);
RationalExpr operator*(RationalExpr lhs, double rhs);
RationalExpr operator*(double lhs, RationalExpr rhs);

}  //  namespace flp
}  //  namespace optasio

namespace operations_research {

optasio::flp::RationalExpr operator/(
    LinearExpr enumerator,
    LinearExpr denominator
);

}  //  namespace operations_research

#endif  //  SRC_RATIONAL_EXPR_HPP_
