#include <FadeBlinker.h>
#include <stdlib.h>

unsigned long now;

const int num_pixels = 13;
FadeBlinker leds[num_pixels] = {
  {2, 200, 700},
  {3, 200, 700},
  {4, 200, 700},
  {5, 200, 700},
  {6, 200, 700},
  {7, 200, 700},
  {8, 200, 700},
  {9, 200, 700},
  {10, 200, 700},
  {11, 200, 700},
  {12, 200, 700},
  {13, 200, 700},
  {14, 200, 700},
};

void setup()
{
  SoftPWMBegin(SOFTPWM_NORMAL);
}

void loop()
{
  now = millis();
  for(int i = 0; i < num_pixels; i++) {
    FadeBlinker& led = leds[i];
    if(led.is_finished(now)) {
      int up = random(100, 1500);
      int down =  random(100, 1500);
      led.set_up_duration(up);
      led.set_down_duration(down);
      led.reset(now);
    }
    led.update(now);
  }
}

void turn_on(int pin) {
  // Turn on - set to 100%
  SoftPWMSetPercent(pin, 100);
}

void turn_off(int pin) {
  // Turn off - set to 0%
  SoftPWMSetPercent(pin, 0);
}
