#include "../s21_math.h"

long double s21_asin(double x) {
  if (s21_is_nan(x) || x < -1.0 || x > 1.0) {
    return s21_NAN;
  }
  if (x == 1.0) {
    return s21_PI_2;
  }
  if (x == -1.0) {
    return -s21_PI_2;
  }
  return s21_atan(x / s21_sqrt(1.0 - x * x));
}