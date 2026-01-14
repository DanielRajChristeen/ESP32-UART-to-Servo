#include <ESP32Servo.h>

#define SERVO_PIN 5   // D5 on ESP32 Dev Kit V1 (GPIO5)

Servo myServo;

int angle = 90; // default startup angle

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Attach servo with safe pulse range
  myServo.setPeriodHertz(50);          // Standard 50Hz servo
  myServo.attach(SERVO_PIN, 500, 2400);

  myServo.write(angle);

  Serial.println("ESP32 Servo Control Ready");
  Serial.println("Send angle (0–180) via Serial");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    int receivedAngle = input.toInt();

    if (receivedAngle >= 0 && receivedAngle <= 180) {
      angle = receivedAngle;
      myServo.write(angle);

      Serial.print("Servo moved to: ");
      Serial.println(angle);
    } else {
      Serial.println("Invalid angle! Use 0–180");
    }
  }
}
