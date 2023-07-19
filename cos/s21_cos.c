#include "../s21_math.h"

long double s21_cos(double x) {
  // Проверки на NaN и бесконечность
  if (s21_is_nan(x) || s21_fabs(x) == s21_INF) {
    return s21_NAN;
  }
  // Нормализация x в пределы от -2π до 2π
  x = s21_fmod(x, 2.0 * s21_PI);
  long double result = 1.0;
  long double step = 1.0;
  unsigned flag = 0;
  // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - x^10/10!
  // Прибавляем следующие члены ряда Тейлора до достижения предела точности
  while (s21_fabs(step / result) > s21_EPS) {
    flag += 2;
    step *= -(x * x) / ((flag - 1) * flag);
    result += step;
  }
  return result;
}
