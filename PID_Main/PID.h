
//use in set motor
int dirt,pwrt,dirp,pwrp;

// globals
long prevT = 0;
int posPrev = 0;

long prevP = 0;
int posPrevP = 0;

// Use the "volatile" directive for variables
// used in an interrupt
volatile int pos_i = 0;
volatile float velocity_i = 0;
volatile long prevT_i = 0;

volatile int pos_ip = 0;
volatile float velocity_ip = 0;
volatile long prevT_ip = 0;

float v1Filt = 0;
float v1Prev = 0;
float v2Filt = 0;
float v2Prev = 0;

float eintegral1 = 0,eintegral2 = 0;
float ederivative1 = 0,ederivative2 = 0;
float vtp = 0 ,vtt = 0;
//PID
void PIDt( float vtt)
{
// Compute the control signal u
int pos = 0;

  noInterrupts(); // disable interrupts temporarily while reading
  pos = pos_i;
  interrupts(); // turn interrupts back on
  long currT = micros();
  float deltaT = ((float) (currT-prevT))/1.0e6;
  float velocity1 = (pos - posPrev)/deltaT;
  posPrev = pos;
  prevT = currT;

  // Convert count/s to RPM
  float v1 = velocity1/330.0*60.0;
  

  // Low-pass filter (25 Hz cutoff)
  //v1Filt = 0.969*v1Filt + 0.0155*v1 + 0.0155*v1Prev;
  v1Filt = 0.854*v1Filt + 0.0728*v1 + 0.0728*v1Prev;

  v1Prev = v1;
  
  float kp = 8;
  float ki = 40;
  float kd = 0;
  float e1 = vtt-v1Filt;
  
//  float e = vt-v2;
//  float kd = 0.05;
  float eintegral1 = eintegral1 + e1*deltaT;
  
  float ederivative1 = ederivative1 - e1*deltaT;
  
//  float u = kp*e + ki*eintegral + kd*ederivative;
  float u1 = kp*e1 + ki*eintegral1 + kd*ederivative1;
 
  // Set the motor speed and direction
   dirt = 1;
  
  if (u1<0)
  {
    dirt = -1;
  }
  
   pwrt = (int) fabs(u1);

  if(pwrt > 255)
  {
    pwrt = 255;
  } 
  
  
}
void PIDp( float vtp)
{
// Compute the control signal u
  int posp = 0;
  noInterrupts();
  posp = pos_ip;
  interrupts();
  long currT = micros();
  float deltaT = ((float) (currT-prevP))/1.0e6;
  float velocity2 = (posp - posPrevP)/deltaT;
  posPrevP = posp;
  prevP = currT;
  float v2 = velocity2/330.0*60.0;
  //v2Filt = 0.969*v2Filt + 0.0155*v2 + 0.0155*v2Prev;
  v2Filt = 0.854*v2Filt + 0.0728*v2 + 0.0728*v2Prev;
  v2Prev = v2;
  
  float kp = 8;
  float ki = 40;
  float kd = 0;
  float e2 = vtp-v2Filt;
  
  float eintegral2 = eintegral2 + e2*deltaT;
  
  float ederivative2 = ederivative2 - e2*deltaT;
  
  float u2 = kp*e2 + ki*eintegral2 + kd*ederivative2;
 
  // Set the motor speed and direction
   dirp = 1;
  
  if (u2<0)
  {
    dirp = -1;
  }
  
   pwrp = (int) fabs(u2);

  if(pwrp > 255)
  {
    pwrp = 255;
  } 
  
  
}
