#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (s21_is_inf(y)) {
    if (s21_is_inf(x)) {
      result = s21_NAN;
    } else {
      result = x;
    }
  } else if (s21_is_inf(x)) {
    result = s21_NAN;
  } else if (y == 0) {
    result = 0 / 0.0;
  } else {
    long long n = x / y;
    result = x - (long double)(n * y);
  }

  return result;
}
