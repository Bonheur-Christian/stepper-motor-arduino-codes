#include <Stepper.h>

#define STEPS_PER_REV 2048  // 4096 steps = 360° for 28BYJ-48

// IN1–IN4 connected to Arduino pins 8,10,9,11
Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);       // Start Serial communication
  stepper.setSpeed(10);     // 10 RPM
  Serial.println("Stepper ready!");
  Serial.println("Enter angle in degrees (positive = clockwise, negative = counter-clockwise):");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input until Enter is pressed
    float angle = input.toFloat();                // Convert input to float for precision

    // Calculate steps using floating-point, then round to nearest integer
    int steps = round((angle / 360.0) * STEPS_PER_REV);

    // Rotate motor
    stepper.step(steps);

    // Feedback
    Serial.print("Rotated ");
    Serial.print(angle);
    Serial.println(" degrees.");
  }
}


// #include <Stepper.h>

// #define STEPS_PER_REV 2048  // 4096 steps = 360° for 28BYJ-48

// // IN1–IN4 connected to Arduino pins 8,10,9,11
// Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11);

// void setup() {
//   stepper.setSpeed(10); // 10 RPM

//   // Rotate 180° clockwise once
//   stepper.step(1024);
// }

// void loop() {
//   // Do nothing, motor has already rotated 180°
// }


//Controlled movement


// #include <Stepper.h>

// #define STEPS_PER_REV 2048  // 2048 steps = 360° for 28BYJ-48

// // IN1–IN4 connected to Arduino pins 8,10,9,11
// Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11);

// void setup() {
//   Serial.begin(9600);       // Start serial communication
//   stepper.setSpeed(10);     // 10 RPM
//   Serial.println("Stepper ready!");
//   Serial.println("Press 'w' to rotate 180° clockwise");
//   Serial.println("Press 's' to rotate 180° counter-clockwise");
// }

// void loop() {
//   if (Serial.available() > 0) {
//     char key = Serial.read();  // Read the key pressed

//     if (key == 'w') {
//       stepper.step(1024);      // Rotate 180° clockwise
//       Serial.println("Rotated 180° clockwise");
//     } 
//     else if (key == 's') {
//       stepper.step(-1024);     // Rotate 180° counter-clockwise
//       Serial.println("Rotated 180° counter-clockwise");
//     } 
//     else {
//       Serial.print("Unknown key: ");
//       Serial.println(key);
//     }
//   }
// }

