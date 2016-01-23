/*
 * Author: Patrick Shinn
 * Version: 1.5
 * Date: 12/23/15
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


void setup() {
  // put your setup code here, to run once
  
  // Buzzer indicating M.A.T.T startup and servo test pass.
  buzzerOn(); 
  delay(1000);
  buzzerOff();
  delay(1000);

  // Motor Test
  //Forward test
  motor1.run(-100);
  motor2.run(100);
  delay(1000);
  motor1.stop();
  motor2.stop();
  delay(500);

  //Reverse Test
  motor1.run(100);
  motor2.run(-100);
  delay(1000);
  motor1.stop();
  motor2.stop();

   // Finish Testing
   buzzerOn();
   delay(500);
   buzzerOff();
   delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  // If the top sensor is within 15 cm of an object or the bottom sensor is within 30 cm of an object, stop and turn left
  if((ultraSensor.distanceCm() < 20 && ultraSensor.distanceCm() > 0) || (ultraSensor1.distanceCm() < 30 && ultraSensor1.distanceCm() > 0)){
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
