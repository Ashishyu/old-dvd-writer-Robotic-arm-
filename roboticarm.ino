//Robotic Arm & Gripper using Old Dvd Writer Gear Motor mechanism and servo motor

#include <Servo.h>
#include <AFMotor.h>

Servo sr1;
Servo sr2;

#define IR2 8
#define IR1 9
#define relayF 11
#define relayB 12
#define relayM 10

AF_DCMotor motor1(1);
void setup() 
{
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8,INPUT);
 
  sr1.attach(5);
  sr2.attach(6);
 
  digitalWrite(relayF,LOW);//gear motor upwards
  delay(5000);
  digitalWrite(relayF,HIGH);
  
  motor1.setSpeed(150);  
  motor1.run(RELEASE);
Serial.println("It begins");

  motor1.run(FORWARD);
  delay(1000);
  motor1.run(RELEASE);
  delay(2000);


sr2.write(180);
sr1.write(0);

Serial.println("initial");
delay(2000);
}

void loop() {

  if(!digitalRead(IR2) && digitalRead(IR1)) {
    digitalWrite(relayM,HIGH);
  Serial.println("Ir sensed");
  sr2.write(125);//grip open
  delay(2000);
  Serial.println("sr2 set to 125");
  
  digitalWrite(relayB,LOW);
  delay(5000);
  digitalWrite(relayB,HIGH);
  
  sr2.write(180); //grip closed
  delay(2000);
  Serial.println("grip closed");
  
  digitalWrite(relayF,LOW);//gear motor upwards
  delay(5000);
  digitalWrite(relayF,HIGH);
  

  sr1.write(90);
  digitalWrite(relayB,LOW);//gear motor downwards
  delay(5000);
  digitalWrite(relayB,HIGH);
  

  sr2.write(125);
  delay(10000);
  sr2.write(180);
  digitalWrite(relayF,LOW);//gear motor upwards
  delay(5000);
  digitalWrite(relayF,HIGH);
  
  Serial.println("up");
  sr1.write(180);
  digitalWrite(relayB,LOW);//gear down
  delay(5000);
  digitalWrite(relayB,HIGH);
  
  sr2.write(125);
  delay(5000);
  digitalWrite(relayF,LOW);//gear up
  delay(5000);
  digitalWrite(relayF,HIGH);
  
  sr2.write(180);
  }
  if(!digitalRead(IR1) && digitalRead(IR2))
  {
    delay(1000);
    digitalWrite(relayM,LOW);
  }
}
