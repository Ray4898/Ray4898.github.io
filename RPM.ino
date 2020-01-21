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