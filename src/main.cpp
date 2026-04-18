#include <Arduino.h>
#include <ESP32Servo.h>

constexpr uint8_t SG90_PIN = 13;
constexpr int STEP_DELAY_MS = 15;
constexpr int SERVO_MIN_US = 500;
constexpr int SERVO_MAX_US = 2400;
constexpr int SERVO_FREQ_HZ = 50;

Servo sg90;

void setup() {
  ESP32PWM::allocateTimer(0);
  sg90.setPeriodHertz(SERVO_FREQ_HZ);
  sg90.attach(SG90_PIN, SERVO_MIN_US, SERVO_MAX_US);
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
