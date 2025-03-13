#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(uint8_t pin);
    void update();
    bool isPressed();
    bool isReleased();
    bool isShortPress();
    bool isLongPress();

private:
    uint8_t _pin;
    bool _lastState;
    bool _currentState;
    unsigned long _lastDebounceTime;
    unsigned long _pressStartTime;
    const unsigned long debounceDelay = 50;
    const unsigned long shortPressTime = 100;
    const unsigned long longPressTime = 1000;
    bool _shortPressDetected;
    bool _longPressDetected;
};

#endif
