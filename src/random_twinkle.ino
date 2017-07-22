#include <FadeBlinker.h>

FadeBlinker led(13, 200, 500);
unsigned long now;

void setup()
{
}

void loop()
{
  now = millis();
  if(led.is_finished(now)){
    led.reset(now, 200, 700);
  }
  led.update(now);
}

void turn_on(int pin) {
  // Turn on - set to 100%
  SoftPWMSetPercent(pin, 100);
}

void turn_off(int pin) {
  // Turn off - set to 0%
  SoftPWMSetPercent(pin, 0);
}
