#include <math.h>
#include "./common.h"

#include "./programs/snake.h"
#include "./programs/spot.h"

int program = 0;

void update(char data[]) {
  switch (program) {
    case 0:
      spot(data);
      break;
    case 1:
      snake(data);
      break;
  }
};
