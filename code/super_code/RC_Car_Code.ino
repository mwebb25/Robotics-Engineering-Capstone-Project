#define BLYNK_TEMPLATE_ID "TMPLSS2DuLTW"
#define BLYNK_TEMPLATE_NAME "project"
#define BLYNK_AUTH_TOKEN "a55nPenSVwgQyXT0dCVGiNrOxt9rMoVe"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
const char* ssid = "iPhone";
const char* password = "Food is good for all people.";
#define APP_DEBUG
#include "BlynkEdgent.h"
// Motor A connections
int enA = 16;
int in1 = 5;
int in2 = 4;
// Motor B connections
int enB = 0;
int in3 = 2;
int in4 = 14;
//Sensor connection
int trigPin = 12;
int echoPin = 13;
//variable conection
long duration;
int distance;
void setup()
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(trigPin,OUTPUT);
	pinMode(echoPin,INPUT);
	Serial.begin(9600);
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  BlynkEdgent.begin();
}
void loop() {
  BlynkEdgent.run();
  directionControl();
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(0.000000001);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
BLYNK_WRITE(V1){
  if(param.asInt()==1){
    digitalWrite(enA, 255);
    digitalWrite(enB,255);
	  digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
	  digitalWrite(in4, LOW);
    }
  else{
	  digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
    }
}  
BLYNK_WRITE(V2){
  if(param.asInt()==1){
    digitalWrite(enA,125);
    digitalWrite(enB,255);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    }
  else{
    digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
    }
  }
BLYNK_WRITE(V3){
  if(param.asInt()==1){
    digitalWrite(enA,255);
    digitalWrite(enB,125);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
    else{
    digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
    }
  }
BLYNK_WRITE(V0){
  if(param.asInt()==1){
    digitalWrite(in1, LOW);
	  digitalWrite(in2, HIGH);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, HIGH);
  }
  else{
    digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
  }
}
void directionControl(){
  if(distance<=400 && distance>30){
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
}
 else{
  Blynk.syncVirtual(V0); 
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
 }
 if(distance<30){
  Blynk.syncVirtual(V0);
 }
 else{
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
 }
}
