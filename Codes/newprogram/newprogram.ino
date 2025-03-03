#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  homingposition();
}

void loop() {
homingposition();
delay(500);
moveforward();
delay(500); 
}
void homingposition(){
  pwm.setPWM(0, 0, pulse(90));  //leg1
  pwm.setPWM(1, 0, pulse(160));
  pwm.setPWM(2, 0, pulse(40));

  pwm.setPWM(12, 0, pulse(65)); //leg2
  pwm.setPWM(13, 0, pulse(115));
  pwm.setPWM(14, 0, pulse(155));


  pwm.setPWM(4, 0, pulse(90));  //leg4
  pwm.setPWM(5, 0, pulse(135));
  pwm.setPWM(6, 0, pulse(45));

  pwm.setPWM(7, 0, pulse(0));  //leg3
  pwm.setPWM(9, 0, pulse(45));
  pwm.setPWM(10, 0, pulse(45));
  }
  void moveforward(){
  pwm.setPWM(0, 0, pulse(90+30));  
  pwm.setPWM(1, 0, pulse(160+20));
  pwm.setPWM(2, 0, pulse(40));
  delay(250);

  pwm.setPWM(12, 0, pulse(65+30));
  pwm.setPWM(13, 0, pulse(115-20));
  pwm.setPWM(14, 0, pulse(155));
  delay(250);


  pwm.setPWM(4, 0, pulse(90-30));
  pwm.setPWM(5, 0, pulse(135+20));
  pwm.setPWM(6, 0, pulse(45));
  delay(250);

  pwm.setPWM(7, 0, pulse(0-30));
  pwm.setPWM(9, 0, pulse(45-20));
  pwm.setPWM(10, 0, pulse(45));
  delay(250);
  }
int pulse(int ang) {
  int apulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(apulse);
  return apulse;
}
