#include <check.h>
#include "../utils.c"

#define RANDOM_TRIES 1000
void expect_random_int_range(int min, int max) {
  int current;
  int seen_max, seen_min;

  for(int i = 0; i < RANDOM_TRIES; ++i) {
    current = random_int_range(min, max);
    if (i == 0) {
      seen_max = seen_min = current;
    }

    ck_assert_int_ge(current, min);
    ck_assert_int_le(current, max);

    if (current < seen_min) { seen_min = current; }
    if (current > seen_max) { seen_max = current; }
  }

  ck_assert_msg(seen_min == min, "Was expecting to see %d, but didn't see less than %d", min, seen_min);
  ck_assert_msg(seen_max == max, "Was expecting to see %d, but didn't see more than %d", max, seen_max);
}

START_TEST (test_random_int_range_positive) {
  expect_random_int_range(0, 10);
}
END_TEST

START_TEST (test_random_int_range_negative) {
  expect_random_int_range(-20, -5);
}
END_TEST

START_TEST (test_random_int_range_mixed) {
  expect_random_int_range(-5, 5);
}
END_TEST

Suite* utils_suite(void) {
  Suite* suite = suite_create("utils");

  TCase* tcase_random = tcase_create("Random");
  tcase_add_test(tcase_random, test_random_int_range_positive);
  tcase_add_test(tcase_random, test_random_int_range_negative);
  tcase_add_test(tcase_random, test_random_int_range_mixed);

  suite_add_tcase(suite, tcase_random);
  return suite;
}

int main(void) {
  int failed;
  Suite* suite = utils_suite();
  SRunner* runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failed;
}
