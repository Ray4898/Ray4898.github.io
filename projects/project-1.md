---
layout: project
type: project
image: images/proj1.PNG
title: Vericle Landing Rocket (Thrust Readings of a Rocket)

permalink: projects/roket
# All dates must be YYYY-MM-DD format!
date: 2015-07-01
labels:
  - propeller
  - Arduino
summary: We made an RPM sensor by using a Hall effect sensor and a magnet for the Vericle Landing Rocket.
---

<div class="ui small rounded images">
  <img class="ui image" src="../images/proj1.PNG">
  <img class="ui image" src="../images/proj1-2.PNG">
  
</div>

In order to ensure a descending rocket will land softly, a sensor system must be integrated to detect changes in height, velocity, rotations-per-minute (RPM) and thrust. The respective data is essential for proper communication between the microcontroller and the servo motor. The intended goal is to have our sensors output a single height value and to adjust the throttle of the propeller with respect to the velocity as the rocket descends.


For this project, We created an RPM sensor by using a Hall effect sensor and a magnet. The Hall effect sensor uses the Hall effect theory and acts like a switch. We 3D printed a mold, which could hold a magnet against the shaft and also 3D printed a base, which would hold the Hall effect sensor in a permanent position near the shaft. When the motor spins, the magnet passes in front of the Hall effect sensor, changes the magnetic field for that duration that the magnet is in front of the sensor, and sends a signal to the Arduino, thus detecting the rotation. 


Here is some code that illustrates how we read values from the RPM sensors:

```js
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define RPM_COUNT 20

int potpinval = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
volatile byte half_revolutions;
unsigned int rpm;
unsigned long timeold;
int sum[RPM_COUNT];
int average =0;
int REVS = 0;



void setup() {
  Serial.begin(115200);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  attachInterrupt(0, magnet_detect, RISING);//Initialize the intterrupt pin (Arduino digital pin 2)
  half_revolutions = 0;
  rpm = 0;
  timeold = 0;
}

void loop() {
  potpinval = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  //val = map(potpinval, 0, 1023, 1100, 1700);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print("Potpin:");
  Serial.println(val);
  if (potpinval <= 100) {
    val = 1100;
     //Set potpin to half position to get to max servo
  }
   else {
    val = 1144;
  }
  myservo.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  delay(500);                           // waits for the servo to get there

 

//  Serial.print("Throtte:");
//  Serial.println(val);
  if (half_revolutions >= 20) {
     rpm = 30*1000/(millis() - timeold)*half_revolutions;
     rpm = rpm * 2;
     for(int i = 0;i < RPM_COUNT - 1; i++){
      sum[i] = sum[i+1];
      }
     sum[RPM_COUNT-1] = rpm;
//     Serial.print("Test ");
//     Serial.println(sum[6]);
     long total = 0;
     for(int i = 0; i < RPM_COUNT; i++){
      total = total + sum[i];
      }
     average = total/RPM_COUNT;
     timeold = millis();
     half_revolutions = 0;
     REVS = REVS + 1;
     Serial.println(REVS);
     Serial.print("Final Reading ");
     
   }
   Serial.println(average);
   float predict_force = 0.0000211614*average*average-0.015424*average+5.23;
   Serial.print("predict-force: ");
   Serial.println(predict_force);
   
}

void magnet_detect()//This function is called whenever a magnet/interrupt is detected by the arduino
{
  half_revolutions++;
  Serial.println("detect");
}
```





