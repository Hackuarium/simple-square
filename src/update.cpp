#include "./common.h"

char counter = 0;

void update(char data[]) {
  counter++;
  for (int i=0; i<MAX_LED*3; i=i+3) {
	  data[i]=counter;
	  data[i+1]=0;
	  data[i+2]=0;
  }
};
