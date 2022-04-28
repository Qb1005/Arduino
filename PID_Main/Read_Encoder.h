// Pins Motor1
#define ENCA_1 3
#define ENCB_1 8
#define PWM_1 5
#define IN1_1 6
#define IN2_1 7

// Pins Motor2
#define ENCA_2 2
#define ENCB_2 4
#define PWM_2 9
#define IN1_2 10
#define IN2_2 11

void readEncodertrai(){
  // Read encoder B when ENCA_1 rises
  int t = digitalRead(ENCB_1);
  int increment = 0;
  if(t>0){
    // If B is high, increment forward
    increment = 1;
  }
  else{
    // Otherwise, increment backward
    increment = -1;
  }
  pos_i = pos_i + increment;

  // Compute velocity with method 2
//  long currT = micros();
//  float deltaT = ((float) (currT - prevT_i))/1.0e6;
//  velocity_i = increment/deltaT;
//  prevT_i = currT;
}

void readEncoderphai(){
  // Read encoder B when ENCA_1 rises
  int p = digitalRead(ENCB_2);
  int increment = 0;
  if(p>0){
    // If B is high, increment forward
    increment = 1;
  }
  else{
    // Otherwise, increment backward
    increment = -1;
  }
  pos_ip = pos_ip + increment;

//  // Compute velocity with method 2
//  long currT = micros();
//  float deltaT = ((float) (currT - prevT_i))/1.0e6;
//  velocity_i = increment/deltaT;
//  prevT_i = currT;
}
