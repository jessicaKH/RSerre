#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 5
#define CLOCK_PIN 13
CRGB leds[NUM_LEDS];

void setup() {
	
   	delay(2000);
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::White;
      FastLED.show();
      delay(100);
   }
}
