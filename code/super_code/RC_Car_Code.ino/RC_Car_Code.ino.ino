//varibles and connection
#define BLYNK_TEMPLATE_ID "TMPLSS2DuLTW"
#define BLYNK_TEMPLATE_NAME "project"
#define BLYNK_AUTH_TOKEN "a55nPenSVwgQyXT0dCVGiNrOxt9rMoVe"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
//wifi connection
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
//lcd conection
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
  //defins a command
  directionCotrol();
  //loops the connection between phone and esp8266
  BlynkEdgent.run();
}
//allows to use lcd on phone
BLYNK_READ(V4){
    Blynk.virtualWrite(V4, distance);
}
//foward
BLYNK_WRITE(V1){
  if(param.asInt()==1 && distance>50){
    //speed
    digitalWrite(enA, 255);
    digitalWrite(enB,255);
    //motor a
	  digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    //motor b
    digitalWrite(in3, HIGH);
	  digitalWrite(in4, LOW);
    }
  else{
    //motor a
	  digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    //motor b
    digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW); 
    } 
}
//right
BLYNK_WRITE(V2){
    if(param.asInt()==1){
      //speed
      digitalWrite(enA,125);
      digitalWrite(enB,255);
      //motor a
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //motor b
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else{
      //motor a
      digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
      //motor b
	    digitalWrite(in3, LOW);
	    digitalWrite(in4, LOW);
    } 
  }
//left
BLYNK_WRITE(V3){
    if(param.asInt()==1 ){
      //speed
      digitalWrite(enA,255);
      digitalWrite(enB,125);
      //motor a 
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      //motor b 
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
    else{
      //motor a 
      digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
      //motor b
	    digitalWrite(in3, LOW);
	    digitalWrite(in4, LOW);
    }
  }
//back
BLYNK_WRITE(V0){
  if(param.asInt()==1){
    //motor a
    digitalWrite(in1, LOW);
	  digitalWrite(in2, HIGH);
    //motor b
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, HIGH);
  }
  else{
    //motor a
    digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
    //motor b
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
  }
}
//syncs all above to phone
BLYNK_CONNECTED(){
  //back
  Blynk.syncVirtual(V0);
  //right
  Blynk.syncVirtual(V2);
  //left
  Blynk.syncVirtual(V3);
  }
void directionCotrol(){
  if(distance>50){
  //allows for the distnace sensor to read distance
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //print distance in cm
  distance = duration * 0.034 / 2;
  //prints on phone
  lcd.print(0,0,distance);
  lcd.clear();
  }
}

