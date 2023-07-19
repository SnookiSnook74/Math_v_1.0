#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>
#include <stdio.h>

#define DBL_TOLERANCE 1e-7
#define E 2.71828182845904523536028747
// Проверка на бесконечность
#define s21_is_inf __builtin_isinf
// Проверка на NaN
#define s21_is_nan __builtin_isnan
#define s21_NAN (0.0 / 0.0)
#define s21_INF (1.0 / 0.0)
// Эпсилон
#define s21_EPS 1e-17
#define s21_PI 3.14159265358979323846
// Для вычесления atan asin acos
#define s21_PI_2 (s21_PI / 2.)
#define s21_PI_4 (s21_PI / 4.)

int s21_abs(int x);

long double s21_log(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);

#endif  //  SRC_S21_MATH_H_