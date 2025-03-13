#include <Arduino.h>
#include "Button.h"

#define BUTTON_PIN 2  // Chân kết nối với nút nhấn

Button button(BUTTON_PIN);

void setup() {
    Serial.begin(115200);
}

void loop() {
    button.update();  // Cập nhật trạng thái nút nhấn

    if (button.isPressed()) {
        Serial.println("Nút đang được nhấn!");
    }

    if (button.isReleased()) {
        Serial.println("Nút đã nhả!");
    }

    if (button.isShortPress()) {
        Serial.println("Phát hiện nhấn ngắn!");
    }

    if (button.isLongPress()) {
        Serial.println("Phát hiện nhấn dài!");
    }

    delay(10); // Tránh kiểm tra quá nhanh
}
