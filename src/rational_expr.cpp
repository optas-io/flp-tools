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

}  //  namespace flp
}  //  namespace optasio
