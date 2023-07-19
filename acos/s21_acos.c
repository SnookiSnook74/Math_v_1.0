#include "../s21_math.h"

long double s21_acos(double x) {
  if (x < -1.0 || x > 1.0) {
    return s21_NAN;
  }
  return s21_PI_2 - s21_asin(x);
}