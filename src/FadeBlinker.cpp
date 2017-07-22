#include "Arduino.h"
#include "SoftPWM.h"
#include "FadeBlinker.h"

#ifndef PAUSE_TIME
#define PAUSE_TIME 200
#endif

FadeBlinker::FadeBlinker(int pin, int up_duration, int down_duration) {
  // setup times
  reset(millis(), up_duration, down_duration);

  // setup pin
  _pin = pin;
  pinMode(_pin, OUTPUT);
  set_pin(LOW);
}

void FadeBlinker::reset(unsigned long at_time, int up_duration, int down_duration) {
  _start_at = at_time;

  // setup timers
  _up_start = PAUSE_TIME + _start_at;
  _up_end = _up_start + up_duration;
  _down_start = _up_end + PAUSE_TIME;
  _down_end = _down_start + down_duration;
  _end_at = _down_end + PAUSE_TIME;
}

bool FadeBlinker::update(unsigned long at_time = 0) {
  // use given time or current time
  unsigned long now = at_time;
  if(now == 0) {
    now = millis();
  }

  if(now > _end_at) {
    return false;
  }

  if(_up_start < now && now < _up_end && _current_state == LOW) { // time for up and is off?
    set_pin(HIGH);
    return true;
  } else if (_down_start < now && now < _down_end && _current_state == HIGH) { // time for off and is on?
    set_pin(LOW);
    return true;
  }
  return false;
}

void FadeBlinker::set_pin(uint8_t value) {
  if(value != _current_state) {
    digitalWrite(_pin, value);
    _current_state = value;
  }
}

bool FadeBlinker::is_finished(unsigned long at_time = 0) {
  // use given time or current time
  unsigned long now = at_time;
  if(now == 0) {
    now = millis();
  }

  return (now >= _end_at);
}
