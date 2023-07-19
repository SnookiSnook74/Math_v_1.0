#include <stdio.h>

#include "../s21_math.h"

long double s21_log(double x) {
  double result = 0;
  int ex_pow = 0;
  if (s21_is_inf(x)) {
    if (x < 0) {
      result = s21_NAN;
    } else {
      result = s21_INF;
    }
  } else if (x <= 0) {
    if (x == 0) {
      result = s21_INF;
    } else {
      result = s21_NAN;
    }
  } else {
    double compare = 0;
    while (x > E) {
      x /= E;
      ex_pow++;
    }
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }

  return result + ex_pow;
}
