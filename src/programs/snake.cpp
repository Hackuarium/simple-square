#include <math.h>
#include "../common.h"

char counterSnake = 0;

void snake(char data[]) {
  counterSnake++;

  for (int i = 0; i < MAX_LED; i++) {
    data[i * 3] = (abs(i - counterSnake) < 3) ? 255 : 0;  // ternary operator
    data[i * 3 + 1] = 0;
    data[i * 3 + 2] = 0;
  }
};
