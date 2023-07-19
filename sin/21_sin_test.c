#include "../unit_test/s21_math_test.h"

START_TEST(test_sin_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_small_positive) {
  double x = 2.523;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_small_negative) {
  double x = -0.523;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_pi) {
  double x = M_PI;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_half_pi) {
  double x = M_PI / 2;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_two_pi) {
  double x = 2 * M_PI;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_big_positive) {
  double x = 1000.0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_big_negative) {
  double x = -1000.0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_nan) {
  double x = s21_NAN;
  ck_assert(s21_is_nan(s21_sin(x)));
}
END_TEST

START_TEST(test_sin_inf) {
  double x = s21_INF;
  ck_assert(s21_is_nan(s21_sin(x)));
}
END_TEST

START_TEST(test_sin_fractional_pi_values) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(sin(s21_PI / i), s21_sin(s21_PI / i), 1e-6);
  } else {
    ck_assert_ldouble_nan(s21_sin(s21_PI / i));
  }
}
END_TEST

Suite *suite_sin(void) {
  Suite *s = suite_create("suite_sin");
  TCase *tc = tcase_create("sin_tc");
  tcase_add_test(tc, test_sin_zero);
  tcase_add_test(tc, test_sin_small_positive);
  tcase_add_test(tc, test_sin_small_negative);
  tcase_add_test(tc, test_sin_pi);
  tcase_add_test(tc, test_sin_half_pi);
  tcase_add_test(tc, test_sin_two_pi);
  tcase_add_test(tc, test_sin_big_positive);
  tcase_add_test(tc, test_sin_big_negative);
  tcase_add_test(tc, test_sin_nan);
  tcase_add_test(tc, test_sin_inf);
  tcase_add_loop_test(tc, test_sin_fractional_pi_values, -10, 10);

  suite_add_tcase(s, tc);
  return s;
}