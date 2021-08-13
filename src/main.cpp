#include "./common.h"


void taskBlink();
void taskPixels();

void setup() {
  Serial.begin(115200);  // only for debug purpose
  taskPixels();
  taskBlink();
}

void loop() {
  vTaskDelay(10000);
}