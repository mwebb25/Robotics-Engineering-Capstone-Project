#define BLYNK_TEMPLATE_ID "TMPLSS2DuLTW"
#define BLYNK_TEMPLATE_NAME "project"
#define BLYNK_AUTH_TOKEN "a55nPenSVwgQyXT0dCVGiNrOxt9rMoVe"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
const char* ssid="iPhone";
const char* password="Food is good for all people.";
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
WidgetLCD lcd(V4);
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
  //starts phone connection
  BlynkEdgent.begin();
}
void loop() {
  //loops the connection between phone and esp8266
  BlynkEdgent.run();
  directionControl();
  //allows for the distnace sensor to read distance
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //prints in cm on phone
  distance = duration * 0.034 / 2;
  lcd.print(0,0,distance);
  lcd.clear();
}
BLYNK_READ(V4){
    Blynk.virtualWrite(V4, distance);
}
//foward
BLYNK_WRITE(V1){
  if(param.asInt()==1){
    void directionControl(){
      if(distance>30){
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
  }
}
//right
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
//left
BLYNK_WRITE(V3){
    if(param.asInt()==1 ){
      //a/b speed controle
      digitalWrite(enA,255);
      digitalWrite(enB,125);
      //motor a singnal
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      //motor b signal
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
    else{
      //motor a stop
      digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
	    digitalWrite(in3, LOW);
	    digitalWrite(in4, LOW);
    }
  }
//back
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
//syncs all above to phone
BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  }

