/*
 * Author: Patrick Shinn
 * Version: 2.0
 * Date: 6/4/16
 * Vehicle: M.A.T.T
 * -------------------------------------------------------------
 * # Mechanical Autonomous Treaded Tank
 * This program is for a Makeblock Orion Board with two 
 * DC motors and an ME utlrasonic sensor.
 * 
 * This Program makes the vehicle drive without human intervention.
 * The vehicle will drive forward until it is within 30 centimeters.
 * of an obstacle. The vehicle will then turn left until it is clear
 * of obstacles, then continue to drive straight. 
 */

#include "MeOrion.h"

MeUltrasonicSensor ultraSensor(PORT_4); // Distance Sensor that rotates
MeUltrasonicSensor ultraSensor1(PORT_3); // Distance Sensor that is stationary
MeDCMotor motor1(M1); // DC motor 1
MeDCMotor motor2(M2); // DC motor 2
Servo servo; // creates a servo object.
MePort port(PORT_6); // creates an MePort object
int16_t servoPin = port.pin1(); // creates an attachment point for the servo.

void setup() {
  // put your setup code here, to run once
  // attaches servo
  servo.attach(servoPin);
  // Buzzer indicating M.A.T.T startup and servo test pass.
  
}

void loop() {
  // put your main code here, to run repeatedly:
   for (int i = 0; i < 180; i++){
      servo.write(i);
      delay(15);
      // If either sesnor picks up an object within 15 cm, stop and turn left. Then check for another obstacle.
        if((ultraSensor.distanceCm() < 15 && ultraSensor.distanceCm() > 0) || (ultraSensor1.distanceCm() < 15 && ultraSensor1.distanceCm() > 0))
        {
            motor1.stop();
            motor2.stop();
            delay(500);
            motor1.run(-255);
            motor2.run(-255);
            delay(500);
            motor1.stop();
            motor2.stop();
            delay(500);
      
        // Otherwise, full speed ahead
        }else{
         
          motor1.run(-255);
          motor2.run(255);
        }
      }
    for (int i = 180; i > 0; i --){
      servo.write(i);
      delay(15);
      // If either sesnor picks up an object within 15 cm, stop and turn left. Then check for another obstacle.
        if((ultraSensor.distanceCm() < 15 && ultraSensor.distanceCm() > 0) || (ultraSensor1.distanceCm() < 15 && ultraSensor1.distanceCm() > 0))
        {
            motor1.stop();
            motor2.stop();
            delay(500);
            motor1.run(-255);
            motor2.run(-255);
            delay(500);
            motor1.stop();
            motor2.stop();
            delay(500);
      
        // Otherwise, full speed ahead
        }else{
         
          motor1.run(-255);
          motor2.run(255);
        }
      }
    }

