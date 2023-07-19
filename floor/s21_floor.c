#include "../s21_math.h"

long double s21_floor(double x) {
  long double result = (long double)((long long)x);
  if (s21_is_inf(x)) {
    int sign = x < 0 ? -1 : 1;
    result = s21_INF * sign;
  } else if (s21_is_nan(x)) {
    result = s21_NAN;
  } else if (result > x) {
    result -= 1.0;
  }
  return result;
}
