#include "SoftPWM.h"

void setup()
{
  // Initialize
  SoftPWMBegin();

  // Create and set pin 13 to 0 (off)
  SoftPWMSet(13, 0);

  // Set fade time for pin 13 to 100 ms fade-up time, and 500 ms fade-down time
  SoftPWMSetFadeTime(13, 200, 600);
}

struct pixel {
  int pin;
  int up_duration;
};

void loop()
{
  // Turn on - set to 100%
  SoftPWMSetPercent(13, 100);

  // Wait for LED to turn on - you could do other tasks here
  delay(300);

  // Turn off - set to 0%
  SoftPWMSetPercent(13, 0);

  // Wait for LED to turn off
  delay(1000);
}
