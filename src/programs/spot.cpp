#include "../common.h"

char counterSpot = 0;

void spot(char data[]) {
  counterSpot++;

  for (int i = 0; i < MAX_LED * 3; i = i + 3) {
    data[i] = counterSpot;
    data[i + 1] = 150;
    data[i + 2] = 0;
  }
}
