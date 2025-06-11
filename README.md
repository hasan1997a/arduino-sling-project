# Arduino Sling Project

## Overview

This repository contains the full documentation and implementation of a mechanical slingshot system developed as part of a laboratory course in digital manufacturing and prototyping.

The goal of the project is to build a programmable launching mechanism based on Arduino, with dual-axis control (horizontal and vertical) using servo motors, and a triggering system for launching a wooden projectile using a rubber band.

---

## Project Objectives

- Design a compact, functional slingshot using accessible mechanical and electronic components
- Implement dual-axis aiming using servo motors controlled via potentiometers
- Integrate a triggering system using a mini servo and a push button
- Document the mechanical assembly, code, and troubleshooting steps
- Analyze system performance and propose improvements

---

## System Architecture

- **Control Board:** Arduino Uno (ATmega328P)
- **Axes Control:**  
  - Horizontal rotation (Z axis): Servo MG995  
  - Vertical rotation (X axis): Servo MG995
- **Trigger Mechanism:** SG90 servo to release stretched rubber band
- **Manual Input:** Two potentiometers (for X and Z angles), one button for firing
- **Materials Used:**  
  - MDF sheets for laser-cut structural parts  
  - PLA plastic for 3D-printed motor mounts  
  - Wooden sticks for projectiles

---

## Directory Structure

```
arduino-sling-project/
├── ОТЧЕТ.docx                   # Full report (in Russian)
├── code/
│   └── sling.ino                # Arduino code (servo + input logic)
├── report_images/
│   ├── base_mount.png
│   ├── servo_holder.png
│   ├── shooting_frame.png
│   ├── test_result.jpg
│   └── ...                      # SolidWorks + real photos
└── README.md
```

---

## Arduino Code Summary

The program uses the standard `Servo.h` library and reads two analog inputs (potentiometers) to control the two MG995 servos.  
A push button triggers the SG90 servo, which acts as a release mechanism. Initial servo positions are set at boot to prevent jitter.

```cpp
// Setup
myservo1.write(90);
myservo2.write(90);
myservo3.write(90);
delay(500);
```

---

## Observed Issues and Solutions

**Problem:** Servo motors jitter or move unexpectedly at power-on  
**Cause:** Undefined PWM output and power instability  
**Fixes:**
- Initialized all servo angles in `setup()`
- Added 1000μF capacitor between VCC and GND
- Powered MG995 motors with external 6V source (not USB)

---

## Testing Results

| Test Parameter         | Result                  |
|------------------------|-------------------------|
| Max aiming deviation   | ±1.5°                   |
| Launch accuracy        | ±10 cm at 3m distance   |
| Response time          | ~18 ms                  |
| Success rate           | 7/10 launches           |

---

## Future Improvements

- Replace potentiometers with joystick module
- Add display to show current angle and state
- Use Hall effect sensor or encoder for feedback
- Implement Bluetooth control from mobile device

---

## Author

**Hasan Alhasan**  
National University of Science and Technology MISiS  
Moscow, 2025
