// Motor A connections
int enA = 8;
int in1 = 7;
int in2 = 6;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
//Sensor connection
int trigPin = 9;
int echoPin = 2;
//variable conection
long duration;
int distance;
void setup() {
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
}

void loop() {
directionControl();
delay(1000);
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

}

// This function lets you control spinning direction of motors
void directionControl() {
// Set motors to maximum speed
// For PWM maximum possible values are 0 to 255
analogWrite(enA, 255);
analogWrite(enB, 255);

if (distance<=400 && distance>15){
// Turn on motor A & B
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
delay(2000);
}
if(distance<=15){
// Turn off motors
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}
}
