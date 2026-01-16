# ESP32 UART to Servo Control

Simple and reliable servo motor control using UART (Serial) communication on ESP32.

This project demonstrates how to control a servo motor connected to an ESP32 by sending angle values (0–180) via Serial (UART). It is designed as a minimal, clean, and extensible example for embedded systems, robotics, and IoT actuator control.

---

## Features

- UART (Serial) based servo control  
- Angle input validation (0–180 degrees)  
- Standard 50Hz servo signal  
- Safe PWM pulse range  
- Clean and minimal code structure  

---

## Why This Project

In real embedded systems, actuators are controlled through commands from external systems such as PCs, Raspberry Pi, or other microcontrollers. This project acts as a foundational UART-to-actuator interface that can be extended into larger robotic or IoT systems.

---

## Hardware Requirements

- ESP32 Dev Kit V1  
- Servo motor (SG90, MG90, or compatible)  
- External 5V power supply for servo (recommended)  
- Jumper wires  

---

## Pin Configuration

| Component      | ESP32 Pin |
|----------------|-----------|
| Servo Signal   | GPIO 5    |
| Servo VCC      | 5V (External recommended) |
| Servo GND      | GND       |

> Note: Always connect the grounds of ESP32 and the servo power supply together.

---

## Software Requirements

- Arduino IDE  
- ESP32 Board Package  
- ESP32Servo Library  

### Install ESP32Servo Library

```text
Arduino IDE → Library Manager → Search **ESP32Servo** → Install
```
---

## Code Structure

```text
ESP32-UART-to-Servo/
├── UART_to_Servo.ino
├── MIT License 
└── README.md
```

---

## How It Works

1. ESP32 initializes UART at 115200 baud  
2. Servo is attached with a safe PWM range  
3. User sends an angle value via Serial Monitor  
4. ESP32 validates the input  
5. Servo moves to the specified position  

---

## Usage Instructions

1. Connect the servo signal pin to GPIO 5  
2. Upload `UART_to_Servo.ino` to ESP32  
3. Open Serial Monitor  
4. Set baud rate to **115200**  
5. Send angle values followed by newline  

### Example Inputs

```text
0 45 90 180
```

---

## Example Serial Output

ESP32 Servo Control Ready Send angle (0–180) via Serial Servo moved to: 90 Servo moved to: 45 Invalid angle! Use 0–180

---

## Applications

- Robotic arm control  
- ESP32 to Raspberry Pi UART communication  
- Embedded systems learning  
- Actuator testing and debugging  
- IoT and automation prototypes  

---

## Future Enhancements

- Multiple servo support  
- Structured command protocol  
- Non-blocking serial handling  
- WiFi / BLE based control  
- Integration with dashboards or IoT platforms  

---

## License

This project is licensed under the **MIT License**.

---

## Author

**Daniel Raj Christeen**

GitHub: https://github.com/DanielRajChristeen


---