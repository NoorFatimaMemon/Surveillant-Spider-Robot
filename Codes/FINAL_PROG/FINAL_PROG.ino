#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#include <dht.h>
#define MQ2pin (0)

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
dht DHT;
float sensorValue;  //variable for MQ2 to store sensor value

#define DHT11_PIN 7

void setup(){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("Gas sensor warming up!");
  delay(20000); // allow the MQ-2 to warm up
}

void loop(){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(3000);

  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  if(sensorValue > 230)
  {Serial.print(" | Smoke detected!");}
  Serial.println("");
  delay(2000); // wait 2s for next reading

  float mq8sensorvoltage, MQ8RS_gas, MQ8_R0 = 0.44, MQ_8_ratio;              // Get value of RS in a GAS and ratio RS_GAS/RS_air
  int mq8sensorValue = analogRead(A1);
  mq8sensorvoltage = (float)mq8sensorValue/1024*5.0;
  MQ8RS_gas = (5.0 - mq8sensorvoltage) / mq8sensorvoltage;          // omit *RL
  MQ_8_ratio = MQ8RS_gas/MQ8_R0;                                            // ratio = RS/R0
  Serial.print("MQ8 SENSOR VOLTAGE = ");
  Serial.println(mq8sensorvoltage);
  Serial.print("RS ratio = ");
  Serial.println(MQ8RS_gas);
  Serial.print("Rs/R0 = ");
  Serial.println(MQ_8_ratio);
  Serial.print("\n");
  delay(1000);
  
  float mq9sensorvoltage, RS_gas, R0 = 0.6, ratio;              // Get value of RS in a GAS and ratio RS_GAS/RS_air
  int mq9sensorValue = analogRead(A2);
  mq9sensorvoltage = (float)mq9sensorValue/1024*5.0;
  RS_gas = (5.0 - mq9sensorvoltage) / mq9sensorvoltage;          // omit *RL
  ratio = RS_gas/R0;                                            // ratio = RS/R0
  Serial.print("MQ9 SENSOR VOLTAGE = ");
  Serial.println(mq9sensorvoltage); 
  Serial.print("RS ratio = ");
  Serial.println(RS_gas); 
  Serial.print("Rs/R0 = ");
  Serial.println(ratio);
  Serial.print("\n");
  delay(1000);
}
