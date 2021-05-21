#include <mrm-servo.h>

// Angle is being increased from 0 counterclockwise to MAXIMUM_DEGREES degrees
#define MAXIMUM_DEGREES 300                     // Maximum servo angle, model specific
#define PIN 18                                  // Servo connected to pin 18
#define SET_DEGREES 290                         // Fixed angle
#define SWEEP 0                                 // 0 - sweep, 1 position servo at SET_DEGREES

Mrm_servo mrm_servo;                            // Object representing servo
uint16_t degrees = 0;

void setup() {
                                                // Connect servo to GPIO 18
                                                // PWM between 0.5 and 2.5 ms, may be model specific
  mrm_servo.add(PIN, "Servo1", 0, MAXIMUM_DEGREES, 0.5, 2.5); 
#if !SWEEP
  mrm_servo.write(SET_DEGREES);
  while(1);
#endif
}

void loop() {
  mrm_servo.write(degrees);                       // Postion servo
  delay(10);
  if (++degrees == MAXIMUM_DEGREES)               // First increase by and and then compare to maximum
    degrees = 0;                                  // Reset
}