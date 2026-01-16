# ESP32 UART to Servo Control

🔧 Simple, reliable servo motor control using UART (Serial) communication on ESP32

This project demonstrates how to control a servo motor connected to an ESP32 by sending angle values (0–180) over UART / Serial Monitor.
It’s designed as a foundational building block for robotics, automation, and distributed embedded systems where commands are sent digitally instead of hard-coded logic.


---

🚀 Why This Project Exists

In real-world embedded systems, actuators (like servos) rarely work in isolation.
They receive commands from:

* PCs

* Raspberry Pi

* Other microcontrollers

* Edge/IoT gateways


This repo provides a clean UART-to-Actuator pipeline, making it ideal for:

* Robotics arms

* Remote control systems

* ESP32 ↔ Raspberry Pi communication

* Debugging and testing servo behavior quickly


No fluff. No UI dependency. Just solid signal flow.


---

🧠 How It Works (High-Level)

1. ESP32 initializes UART at 115200 baud


2. Servo is attached using ESP32Servo library


3. User sends an angle (0–180) via Serial Monitor


4. ESP32 validates the input


5. Servo moves to the requested position



This keeps control logic decoupled from the actuator — a best practice in scalable system design.


---

🛠 Hardware Requirements

ESP32 Dev Kit V1

Servo Motor (SG90 / MG90 / compatible)

External 5V supply for servo (recommended)

Jumper wires



---

🔌 Pin Configuration

Component	ESP32 Pin

Servo Signal	GPIO 5 (D5)
Servo VCC	5V (External preferred)
Servo GND	GND


⚠️ Important:
Do not power the servo directly from ESP32 5V pin if it draws high current. Use a common ground.


---

📦 Software Requirements

Arduino IDE

ESP32 Board Package

Library: ESP32Servo


Install ESP32Servo Library

Arduino IDE → Library Manager → Search "ESP32Servo" → Install


---

📄 Code Overview

File: UART_to_Servo.ino

Key Features

UART-based angle input

Input validation (0–180 degrees)

Safe servo pulse range

Clean serial feedback


Core Logic

myServo.setPeriodHertz(50);   // Standard servo frequency
myServo.attach(SERVO_PIN, 500, 2400);

int receivedAngle = input.toInt();
if (receivedAngle >= 0 && receivedAngle <= 180) {
    myServo.write(receivedAngle);
}


---

▶️ How to Run

1. Connect servo to ESP32 (GPIO5)


2. Upload UART_to_Servo.ino


3. Open Serial Monitor


4. Set baud rate to 115200


5. Send angle values:

0
45
90
180




---

🧪 Example Output

ESP32 Servo Control Ready
Send angle (0–180) via Serial
Servo moved to: 90
Servo moved to: 45
Invalid angle! Use 0–180


---

📈 Use Cases

Robotic arm joint control

ESP32 ↔ Raspberry Pi actuator bridge

UART protocol testing

Embedded systems learning

IoT actuator prototyping


This can be easily extended to:

Multiple servos

Binary protocols

WiFi → UART bridges

WebSocket / MQTT control



---

🧩 Future Enhancements (Optional Roadmap)

Multiple servo support

Non-blocking UART parsing

Command format (S1:90)

WiFi / BLE control layer

Watchdog integration



---

📜 License

This project is licensed under the MIT License.
You’re free to use, modify, and distribute it — just keep the license intact.


---

👤 Author

Daniel Raj C

🔗 GitHub: https://github.com/DanielRajChristeen