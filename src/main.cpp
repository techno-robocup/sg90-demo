#include <Arduino.h>
#include <Servo.h>

constexpr uint8_t SG90_PIN = 9;
constexpr int STEP_DELAY_MS = 15;

Servo sg90;

void setup() {
  sg90.attach(SG90_PIN);
}

void loop() {
  for (int pos = 0; pos <= 180; ++pos) {
    sg90.write(pos);
    delay(STEP_DELAY_MS);
  }

  for (int pos = 180; pos >= 0; --pos) {
    sg90.write(pos);
    delay(STEP_DELAY_MS);
  }
}
