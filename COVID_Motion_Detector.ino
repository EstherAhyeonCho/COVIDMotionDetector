/*
COVID Motion Sensor 
Created by Esther Cho, Eunbin Choe
Used : Arduino Uno
This project is intended to demonstrate the 2 metre social distancing for COVID-19
If a person is coming close to the sensor, the sensor detects the person which makes the project flashes the led red as well as having the alarm sound
Otherwise, only the led flashes green
*/

const int trigPin = 4; //ultransonic sensor output
const int echoPin = 5; //ultransonic sensor input
long duration;
int distance;
const int buzzer = 2;

const int red_light_pin = 10;
const int green_light_pin = 9;
const int led_on = 255; //highest RGB value for led (purest)
const int led_off = 0;

void setup() { 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT); 

pinMode(red_light_pin, OUTPUT);
pinMode(green_light_pin, OUTPUT);
}

void loop() { 

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.029/2; // calculate for using meters , 200=2m

if (distance <= 200){
  analogWrite(red_light_pin, led_on);
  analogWrite(green_light_pin, led_off);
  tone(buzzer, 1000);
}
else {
  analogWrite(red_light_pin, led_off);
  analogWrite(green_light_pin, led_on);
  noTone(buzzer); 
}
delay(300); //delay led when sensed
}
