#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (s21_fabs(base) < 1 && s21_fabs(base) > 0) {
    if (s21_is_inf(exp)) {
      result = exp > 0 ? s21_exp(exp * s21_log(base)) : s21_INF;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  } else if (s21_is_inf(base)) {
    if (exp == 0) {
      result = 1;
    } else if (s21_is_inf(exp)) {
      result = exp < 0 ? 0 : s21_INF;
    } else if (s21_is_nan(exp)) {
      result = s21_NAN;
    }
  } else if (s21_is_nan(base)) {
    result = exp == 0 ? 1 : s21_NAN;
  } else if (base == 1 || (base == -1 && s21_is_inf(exp))) {
    result = 1;
  } else if (base == 0) {
    result = (exp < 0 || s21_is_inf(exp)) ? s21_INF : (exp == 0 ? 1 : 0);
  } else if (base < 0) {
    if (s21_is_inf(exp) && exp > 0) {
      result = s21_INF;
    } else if (s21_is_inf(exp) && exp < 0) {
      result = 0;
    } else {
      base = -base;
      result = s21_exp(exp * s21_log(base));
      if (s21_fmod(exp, 2) != 0 && exp != 0) {
        result = -result;
      }
    }
  } else {
    if (s21_is_inf(exp) && exp < 0) {
      result = 0;
    } else if (s21_is_inf(exp) && exp > 0) {
      result = s21_INF;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}
