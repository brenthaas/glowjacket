#include <FadeBlinker.h>

unsigned long now;

const int num_pixels = 1;
FadeBlinker leds[num_pixels] = { FadeBlinker(13, 200, 500) };

void setup()
{
  SoftPWMBegin(SOFTPWM_NORMAL);
}

void loop()
{
  now = millis();
  // for(int i = 0; i < num_pixels; i++) {
    FadeBlinker& led = leds[0];
    if(led.is_finished(now)) {
      int up = random(100, 1500);
      int down =  random(100, 1500);
      led.set_up_duration(up);
      led.set_down_duration(down);
      led.reset(now);
    }
    led.update(now);
  // }
}

void turn_on(int pin) {
  // Turn on - set to 100%
  SoftPWMSetPercent(pin, 100);
}

void turn_off(int pin) {
  // Turn off - set to 0%
  SoftPWMSetPercent(pin, 0);
}
