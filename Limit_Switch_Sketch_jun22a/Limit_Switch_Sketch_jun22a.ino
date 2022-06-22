/*
  Stepper Motor Limit Switch Demo
  stepper-limit-demo.ino
  Uses Hall Effect sensors as limit switches
  Uses A4988 Stepper Motor Driver module
  
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Define connections
#define HALL_SENSOR_A      2
#define HALL_SENSOR_B      3
#define DIR      10
#define STEP      11

// Variables
int pd = 4000;       // Pulse Delay period
boolean setdir = LOW; // Set Direction

// Interrupt Handlers

void limit_a (){

  // Reverse motor
  setdir = !setdir;
  
}

void limit_b (){

  // Reverse motor
  setdir = !setdir;
  
}


void setup() {
  
  // Setup the stepper controller pins as Outputs
  pinMode(DIR,OUTPUT); 
  pinMode(STEP,OUTPUT);
  
  // Setup the Hall Effect switches as Inputs
  pinMode(HALL_SENSOR_A, INPUT);
  pinMode(HALL_SENSOR_B, INPUT);
  
  // Attach interrupt pins to handlers
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_A), limit_a, FALLING);
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_B), limit_b, FALLING);
   
}

void loop() {
  
    digitalWrite(DIR,setdir);
    digitalWrite(STEP,HIGH);
    delayMicroseconds(pd);
    digitalWrite(STEP,LOW);
    delayMicroseconds(pd);
 
}
