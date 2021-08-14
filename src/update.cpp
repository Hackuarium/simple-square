#include "./common.h"
#include <math.h>

char counter = 0;

void update(char data[]) {

  counter++;

if (false) {
  for (int i=0; i<MAX_LED*3; i=i+3) {
	  data[i]=counter;
	  data[i+1]=0;
	  data[i+2]=0;
  }
} else {
  for (int i=0; i<MAX_LED; i++) {
	  data[i*3]= (abs(i-counter)<3) ? 255 : 0; // ternary operator
	  data[i*3+1]=0;
	  data[i*3+2]=0;
  }

}




};
