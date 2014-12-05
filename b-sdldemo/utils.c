#import <stdlib.h>
#include "utils.h"

int random_int(int max) {
  return random_int_range(0, max);
}

int random_int_range(int min, int max) {
  // We need to work in a range of positive integers for the math to work
  // properly here.
  int length = abs(max - min);
  return rand() % (length + 1) + min;
}

