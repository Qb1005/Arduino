#include "PID.h"
#include "Read_Encoder.h"
#include "Set_Motor.h"
#include "Sensor.h"
#include "Calib_Line_Sensor.h"

void setup() {
  Serial.begin(115200);
//-------------------------------------------------

  pinMode(sensorPin1,INPUT_PULLUP);
  pinMode(sensorPin2,INPUT_PULLUP);
  pinMode(sensorPin3,INPUT_PULLUP);
  pinMode(sensorPin4,INPUT_PULLUP);
  pinMode(sensorPin5,INPUT_PULLUP);
  
  // calibrate during the first five seconds
//  while (millis() < 3000) 
//    {
//    a=analogRead(A0);
//    b=analogRead(A2);
//    c=analogRead(A3);
//    d=analogRead(A4);
//    e=analogRead(A5);
//    
//    // record the maximum sensor value
//    if (a > sensorMax) {
//      sensorMax = a;
//    }
//    if (b > sensorMax) {
//      sensorMax = b;
//    }
//    if (c > sensorMax) {
//      sensorMax = c;
//    }
//    if (d > sensorMax) {
//      sensorMax = d;
//    }
//    if (e > sensorMax) {
//      sensorMax = e;
//    }
//
//    // record the minimum sensor value
//      if (a < sensorMin) {
//      sensorMin = a;
//      }
//      if (b < sensorMin) {
//      sensorMin = b;
//      }
//      if (c < sensorMin) {
//      sensorMin = c;
//      }
//      if (d < sensorMin) {
//      sensorMin = d;
//      }
//      if (e < sensorMin) {
//      sensorMin = e;
//      }
//    }

//-------------------------------------------------
  pinMode(ENCA_1,INPUT_PULLUP);
  pinMode(ENCB_1,INPUT_PULLUP);
  pinMode(PWM_1,OUTPUT);
  pinMode(IN1_1,OUTPUT);
  pinMode(IN2_1,OUTPUT);
  pinMode(ENCA_2,INPUT_PULLUP);
  pinMode(ENCB_2,INPUT_PULLUP);
  pinMode(PWM_2,OUTPUT);
  pinMode(IN1_2,OUTPUT);
  pinMode(IN2_2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA_1),
                  readEncodertrai,FALLING);
  attachInterrupt(digitalPinToInterrupt(ENCA_2),
                  readEncoderphai,FALLING);                 
}

void loop() {
  //mapsensor();
  //caliblinesensor(); 
  
//------------------------------------------------------  
  vtt = 100;
  vtp = 100;
  PIDt(vtt);
  PIDp(vtp);

  setMotorA(dirt,pwrt,PWM_1,IN1_1,IN2_1);
  setMotorB(dirp,pwrp,PWM_2,IN1_2,IN2_2);

//------------------------------------------------------  
   
  
  Serial.print(vtt);
  Serial.print(" - ");
  Serial.print(v1Filt);
  Serial.print(" || ");
  Serial.print(vtp);
  Serial.print(" - ");
  Serial.print(v2Filt);
  Serial.println();
//  Serial.print(a);
//  Serial.print(" || ");
//  Serial.print(b);
//  Serial.print(" || ");
//  Serial.print(c);
//  Serial.print(" || ");
//  Serial.print(e);
//  Serial.print(" || ");
//  Serial.print(d);
//  Serial.println( );

  delay(1);
}
