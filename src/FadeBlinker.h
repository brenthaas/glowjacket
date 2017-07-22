#ifndef FadeBlinker_h
#define FadeBlinker_h

#include "Arduino.h"
#include "SoftPWM.h"

class FadeBlinker
{
  public:
    FadeBlinker(int pin, int up_duration, int down_duration);
    void reset(unsigned long at_time);
    void set_up_duration(int duration);
    void set_down_duration(int duration);
    bool update(unsigned long at_time);
    bool is_finished(unsigned long at_time);
  private:
    int _pin;
    int _current_state;

    unsigned long _start_at;
    unsigned long _up_start;
    unsigned long _up_end;
    int _up_duration;

    int _down_duration;
    unsigned long _down_start;
    unsigned long _down_end;
    unsigned long _end_at;

    void set_pin(int value);
};

#endif
