# Button Library for Arduino

## Overview
This library provides an easy way to handle button states on Arduino, including:
- Detecting button press and release
- Detecting short press (≥100ms)
- Detecting long press (≥1000ms)
- Debouncing to prevent false triggers

## Wiring
- One leg of the button to **5V**
- The other leg to **a digital pin on Arduino**
- A **10kΩ pull-down resistor** from the digital pin to **GND**

## Installation
1. Copy `Button.h` and `Button.cpp` into your Arduino project folder.
2. Include the library in your sketch:
    ```cpp
    #include "Button.h"
    ```

## Example Usage
```cpp
#include <Arduino.h>
#include "Button.h"

#define BUTTON_PIN 2
Button button(BUTTON_PIN);

void setup() {
    Serial.begin(115200);
}

void loop() {
    button.update();
    if (button.isShortPress()) {
        Serial.println("Short press detected");
    }
    if (button.isLongPress()) {
        Serial.println("Long press detected");
    }
    delay(10);
}
```

## License
MIT License
