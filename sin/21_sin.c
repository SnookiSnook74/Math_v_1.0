#include "../s21_math.h"

long double s21_sin(double x) {
  // Проверки на NaN и бесконечность
  if (s21_is_nan(x) || s21_fabs(x) == s21_INF) {
    return s21_NAN;
  }
  // Нормализация x в пределы от -2π до 2π
  x = s21_fmod(x, 2.0 * s21_PI);
  long double result = x;
  long double step = x;
  unsigned flag = 1;
  // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + ...
  // Прибавляем следующие члены ряда Тейлора до достижения предела точности
  while (s21_fabs(step / result) > s21_EPS) {
    flag += 2;
    step *= -(x * x) / ((flag - 1) * flag);
    result += step;
  }
  return result;
}
