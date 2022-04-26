#include <ortools/base/logging.h>

#include "rational_expr.hpp"

namespace optasio {
namespace flp {

bool linear_expr_is_nonzero(const LinearExpr& expr) {
  bool zero_offset = expr.offset() == 0;
  auto all_coeffs_are_zero = expr.terms().size() == 0;
  return !zero_offset || !all_coeffs_are_zero;
}

bool RationalExpr::is_valid() const {
  return linear_expr_is_nonzero(denominator);
}

bool RationalExpr::is_linear() const {
  bool all_coeffs_are_zero = denominator.terms().size() == 0;
  return denominator.offset() != 0 && all_coeffs_are_zero;
}

RationalExpr& RationalExpr::operator+=(double rhs) {
  enumerator += rhs * denominator;
  return *this;
}

RationalExpr& RationalExpr::operator-=(double rhs) {
  enumerator -= rhs * denominator;
  return *this;
}

RationalExpr& RationalExpr::operator*=(double rhs) {
  enumerator *= rhs;
  return *this;
}

RationalExpr& RationalExpr::operator/=(double rhs) {
  DCHECK_NE(rhs, 0);
  denominator *= rhs;
  return *this;
}

RationalExpr RationalExpr::operator-() const {
  return -1 * (*this);
}

RationalExpr operator+(RationalExpr lhs, double rhs) {
  lhs += rhs;
  return lhs;
}

RationalExpr operator+(double lhs, RationalExpr rhs) {
  rhs += lhs;
  return rhs;
}

RationalExpr operator-(RationalExpr lhs, double rhs) {
  lhs -= rhs;
  return lhs;
}

RationalExpr operator-(double lhs, RationalExpr rhs) {
  rhs -= lhs;
  return rhs;
}

RationalExpr operator*(RationalExpr lhs, double rhs) {
  lhs *= rhs;
  return lhs;
}

RationalExpr operator*(double lhs, RationalExpr rhs) {
  rhs *= lhs;
  return rhs;
}

RationalExpr operator/(LinearExpr enumerator, LinearExpr denominator) {
  return RationalExpr(enumerator, denominator);
}

}  //  namespace flp
}  //  namespace optasio
