# huskylens
# Face Recognition LED Trigger with HuskyLens and Arduino

This project uses the **HuskyLens AI camera** and an **Arduino UNO** to detect human faces. When a face is recognized, an LED connected to the Arduino is turned on.

## 📸 Features

- Face detection using HuskyLens
- LED activation on face recognition
- Real-time interaction via UART/I2C with Arduino
- Written in C++ (Arduino framework)

## 🧰 Hardware Required

- [HuskyLens AI Camera](https://www.dfrobot.com/product-1922.html)
- Arduino UNO (or compatible)
- LED (any color)
- 220Ω resistor
- Jumper wires
- Breadboard

## 🔌 Wiring

| Component     | Arduino UNO Pin |
|---------------|------------------|
| HuskyLens TX  | Pin 10 (SoftwareSerial RX) |
| HuskyLens RX  | Pin 11 (SoftwareSerial TX) |
| LED +         | Pin 7            |
| LED -         | GND (via 220Ω resistor) |

> Note: The camera should be trained to recognize a face using the onboard interface before running the code.

## 🧠 How It Works

1. The HuskyLens detects a pre-learned face.
2. It sends data to the Arduino via UART (SoftwareSerial).
3. Arduino checks if an ID is detected.
4. If a face is detected, the LED turns on; otherwise, it stays off.

## 🗂️ Files

- `main.ino` - Arduino sketch with the logic for HuskyLens face detection and LED control

## 📦 Libraries Used

- [HuskyLens Library](https://github.com/DFRobot/HUSKYLENSArduino)
- SoftwareSerial (built-in with Arduino)

## 🚀 Getting Started

1. Connect the components as shown above.
2. Upload the sketch to your Arduino board.
3. Observe the LED turning on when the face is detected.

## 🧑‍💻 Author

- **khaled mahmoud sulaimani** – [@yourgithub](https://github.com/yourgithub)

---

> Feel free to fork or contribute!

