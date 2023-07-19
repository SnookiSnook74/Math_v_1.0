#include "../s21_math.h"

long double s21_exp(double x) {
  long double result = 1;

  if (s21_is_inf(x)) {
    result = 0;
  } else {
    long double add_value = 1;
    long double i = 1;
    int status = 1;
    while (s21_fabs(add_value) > 1e-21 && status) {
      add_value *= x / i;
      i += 1;
      result += add_value;
      if (result > __DBL_MAX__) {
        if (x > 0)
          result = 1.0 / 0.0;
        else
          result = 0;
        status = 0;
      }
    }
  }
  return result;
}
