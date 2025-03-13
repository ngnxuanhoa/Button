#include "Button.h"

Button::Button(uint8_t pin) : _pin(pin), _lastState(LOW), _currentState(LOW), _lastDebounceTime(0), _pressStartTime(0), _shortPressDetected(false), _longPressDetected(false) {
    pinMode(_pin, INPUT); // Sử dụng điện trở kéo xuống (pull-down)
}

void Button::update() {
    bool reading = digitalRead(_pin);
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }
    
    if ((millis() - _lastDebounceTime) > debounceDelay) {
        if (reading != _currentState) {
            _currentState = reading;
            if (_currentState == HIGH) {
                _pressStartTime = millis();
                _shortPressDetected = false;
                _longPressDetected = false;
            } else {
                unsigned long pressDuration = millis() - _pressStartTime;
                if (pressDuration >= longPressTime) {
                    _longPressDetected = true;
                } else if (pressDuration >= shortPressTime) {
                    _shortPressDetected = true;
                }
            }
        }
    }
    
    _lastState = reading;
}

bool Button::isPressed() {
    return _currentState == HIGH;
}

bool Button::isReleased() {
    return _currentState == LOW;
}

bool Button::isShortPress() {
    bool result = _shortPressDetected;
    _shortPressDetected = false;
    return result;
}

bool Button::isLongPress() {
    bool result = _longPressDetected;
    _longPressDetected = false;
    return result;
}
