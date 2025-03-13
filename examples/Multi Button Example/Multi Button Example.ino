#include <Arduino.h>
#include "Button.h"

#define BUTTON1_PIN 2  // Chân kết nối với nút nhấn 1
#define BUTTON2_PIN 3  // Chân kết nối với nút nhấn 2
#define BUTTON3_PIN 4  // Chân kết nối với nút nhấn 3

Button button1(BUTTON1_PIN);
Button button2(BUTTON2_PIN);
Button button3(BUTTON3_PIN);

void setup() {
    Serial.begin(115200);
}

void loop() {
    button1.update();
    button2.update();
    button3.update();

    if (button1.isShortPress()) {
        Serial.println("Nút 1 - Nhấn ngắn!");
    }
    if (button1.isLongPress()) {
        Serial.println("Nút 1 - Nhấn dài!");
    }

    if (button2.isShortPress()) {
        Serial.println("Nút 2 - Nhấn ngắn!");
    }
    if (button2.isLongPress()) {
        Serial.println("Nút 2 - Nhấn dài!");
    }

    if (button3.isShortPress()) {
        Serial.println("Nút 3 - Nhấn ngắn!");
    }
    if (button3.isLongPress()) {
        Serial.println("Nút 3 - Nhấn dài!");
    }

    delay(10); // Tránh kiểm tra quá nhanh
}
