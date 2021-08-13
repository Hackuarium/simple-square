#include <FastLED.h>

#include "./common.h"
#include "./update.h"

#define PIXELS_PIN 12

void blank(char data[]);
void copyDataToPixels(char data[], CRGB pixels[]);

void TaskPixels(void* pvParameters) {
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 40;
  // Initialise the xLastWakeTime variable with the current time.
  xLastWakeTime = xTaskGetTickCount();

  CRGB pixels[MAX_LED];
  char data[MAX_LED*3];

  LEDS.addLeds<WS2812B, PIXELS_PIN, GRB>(pixels, MAX_LED);


LEDS.setBrightness(50);

  blank(data);
  copyDataToPixels(data, pixels);
  LEDS.show();  // Initialize all pixels to 'off'


  while (true) {
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    update(data);
    copyDataToPixels(data, pixels); 
    LEDS.show();  // Send the updated pixel colors to the hardware.
  }
}

void copyDataToPixels(char data[], CRGB pixels[]) {
  for (uint16_t i = 0; i < MAX_LED; i++) {
    pixels[i] = CRGB(data[i*3], data[i*3+1], data[i*3+2]);
  }
}

void blank(char data[]) {
  for (uint16_t i = 0; i < MAX_LED*3; i++) {
	  data[i]=0;
  }
}

void taskPixels() {
  // Now set up two tasks to run independently.
  xTaskCreatePinnedToCore(TaskPixels, "TaskPixels",
                          20000,  // This stack size can be checked & adjusted
                                  // by reading the Stack Highwater
                          NULL,
                          1,  // Priority, with 3 (configMAX_PRIORITIES - 1)
                              // being the highest, and 0 being the lowest.
                          NULL, 1);
}
