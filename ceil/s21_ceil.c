#include "../s21_math.h"

long double s21_ceil(double x) {
  long double result = (long double)((long long)x);
  if (s21_is_nan(x)) {
    result = s21_NAN;
  } else if (s21_is_inf(x)) {
    result = s21_INF;
  } else if (result < x) {
    result += 1.0;
  }
  return result;
}
