// These constants won't change:
const int sensorPin1 = A0;
const int sensorPin2 = A2;
const int sensorPin3 = A3;
const int sensorPin4 = A4;
const int sensorPin5 = A5;

const uint8_t Sensorcount = 5;
uint16_t sensorValues[Sensorcount];

int a,b,c,d,e;

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 15;        // minimum sensor value
int sensorMax = 1055;           // maximum sensor value
int den = 40;
int trang = 1010;

void mapsensor(){
  // read the sensor:
  a=analogRead(A0);
  b=analogRead(A2);
  c=analogRead(A3);
  d=analogRead(A4);
  e=analogRead(A5);

//  if (a < den)
//  {
//    a = 1;
//  }
//  if (a > trang)
//  {
//    a=0;
//  }
//  if (b < den)
//  {
//    b = 1;
//  }
//  if (b > trang)
//  {
//    b=0;
//  }
//  if (c < den)
//  {
//    c = 1;
//  }
//  if (c > trang)
//  {
//    c=0;
//  }
//  if (d < den)
//  {
//    d = 1;
//  }
//  if (d > trang)
//  {
//    d=0;
//  }
//  if (e < den)
//  {
//    e = 1;
//  }
//  if (e > trang)
//  {
//    e=0;
//  }

//  // in case the sensor value is outside the range seen during calibration
//  a = constrain(a, sensorMin, sensorMax);
//  b = constrain(b, sensorMin, sensorMax);
//  c = constrain(c, sensorMin, sensorMax);
//  d = constrain(d, sensorMin, sensorMax);
//  e = constrain(e, sensorMin, sensorMax);
//  
//  // apply the calibration to the sensor reading
//  a = map(a, sensorMin, sensorMax, 0, 255);
//  b = map(b, sensorMin, sensorMax, 0, 255);
//  c = map(c, sensorMin, sensorMax, 0, 255);
//  d = map(d, sensorMin, sensorMax, 0, 255);
//  e = map(e, sensorMin, sensorMax, 0, 255);
}
