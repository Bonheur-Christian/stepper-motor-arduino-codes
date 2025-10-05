# Stepper Motor Control via Serial Input  

This Arduino project allows you to control a **28BYJ-48 stepper motor** (or any stepper with 2048 steps per revolution) using serial commands. By entering an angle in the Arduino Serial Monitor, the motor rotates clockwise or counter-clockwise accordingly.  

## Features  
- Serial input control of motor rotation.  
- Enter any angle (positive = clockwise, negative = counter-clockwise).  
- Accurate step calculation using floating-point math and rounding.  
- Works with the **Stepper.h** library.  

## Hardware Requirements  
- Arduino board (Uno, Nano, etc.)  
- Stepper motor: **28BYJ-48 (2048 steps/rev)**  
- ULN2003 driver board (or equivalent motor driver)  
- Jumper wires  

## Wiring  
The stepper motor is connected to the Arduino as follows:  

| Stepper Pin | Arduino Pin |  
|-------------|-------------|  
| IN1         | 8           |  
| IN2         | 10          |  
| IN3         | 9           |  
| IN4         | 11          |  

⚠️ Ensure you power the stepper motor using a proper supply (typically **5V for 28BYJ-48**).  

## How It Works  
1. Upload the code to your Arduino.  
2. Open the **Serial Monitor** (set baud rate to **9600**).  
3. Enter an angle (e.g., `90` for clockwise or `-45` for counter-clockwise).  
4. The motor rotates by the specified angle.  

### Example Inputs  
- Input: `90` → rotates **90° clockwise**  
- Input: `-180` → rotates **180° counter-clockwise**  
- Input: `360` → completes **one full revolution**  

## Code Explanation  
- `STEPS_PER_REV = 2048` → total steps for one full revolution of the motor.  
- `stepper.setSpeed(10)` → sets motor speed to **10 RPM**.  
- Serial input is read using `Serial.readStringUntil('\n')`.  
- Steps are calculated with:  
  ```cpp
  steps = round((angle / 360.0) * STEPS_PER_REV);
