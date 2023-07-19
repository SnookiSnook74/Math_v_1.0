#include "../s21_math.h"

// Диапозон -π/2 до +π/2
long double s21_atan(double x) {
  if (s21_is_nan(x)) {
    return s21_NAN;
  }
  if (x == s21_INF) {
    return s21_PI_2;
  }
  if (x == -s21_INF) {
    return -s21_PI_2;
  }
  if (x == 1) {
    return s21_PI_4;
  }
  if (x == -1) {
    return -s21_PI_4;
  }
  int sign = 0;
  if (x < 0) {
    x = -x;
    sign = 1;
  }
  int flip = 0;
  if (x > 1) {
    x = 1 / x;
    flip = 1;
  }

  // x^3/3 + x^5/5 - x^7/7 + 
  long double term = x;
  long double res = 0.0;
  for (int i = 1; s21_fabs(term) > 1e-16; i += 2) {
    if (i % 4 == 1) {
      res += term;
    } else {
      res -= term;
    }
    term *= x * x * i / (i + 2);
  }
  if (flip) {
    res = s21_PI_2 - res;
  }
  return sign ? -res : res;
}
