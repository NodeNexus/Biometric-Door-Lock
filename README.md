# 🔐 Biometric Door Lock (Arduino)

## 📌 Overview
This project creates a **door lock system with fingerprint authentication** using Arduino.  
The lock opens only for registered fingerprints, controlled by a **servo motor**.

- Correct fingerprint → Unlocks for 3s  
- Wrong fingerprint → Access denied (red LED)  

---

## 🛠️ Hardware Required
- Arduino Uno/Nano  
- Fingerprint Sensor (R307, AS608, or GT-511C3)  
- Servo Motor (SG90/MG995)  
- LEDs (Red, Green)  
- Jumper wires, breadboard, 5V supply  

---

## 🔌 Wiring
- Fingerprint Sensor → Arduino:  
  - VCC → 5V  
  - GND → GND  
  - TX → D2  
  - RX → D3  

- Servo Motor:  
  - Signal → D9  
  - VCC → 5V  
  - GND → GND  

- LEDs:  
  - Green → D6  
  - Red → D7  

---

## ▶️ Usage
1. Install the **Adafruit Fingerprint Sensor Library** from Arduino IDE Library Manager.  
2. Use the `Enroll` example from the library to store fingerprints.  
3. Upload this sketch to Arduino.  
4. Place a registered finger → Servo rotates (unlock).  
5. Unregistered finger → Red LED blinks.  

---

## 📂 Repo Structure
```
Biometric-Door-Lock/
│── DoorLock.ino
└── README.md
```

---

## ✨ Future Improvements
- Add keypad + PIN for backup unlock.  
- Connect with IoT for remote monitoring.  
- Use solenoid lock instead of servo.
