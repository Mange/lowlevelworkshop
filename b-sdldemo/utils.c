#import <stdlib.h>
#include "utils.h"

int random_int(int max) {
  return random_int_range(0, max);
}

int random_int_range(int min, int max) {
  return rand() % (max - min) + min;
}

