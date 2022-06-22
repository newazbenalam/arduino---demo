#define ENC_IN 3
volatile long encoderValue = 0;
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
// One-second interval for measurements
int interval = 250;
int ppr = 24;
int pwmPin = 6;
int pwmValue = 40;
bool dir = LOW;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(ENC_IN, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
  previousMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Write PWM to controller
  analogWrite(pwmPin,pwmValue); // speed
  digitalWrite(7,dir); // direction

  if (encoderValue > ((ppr/2)*0.8)){
    pwmValue = 0;
    if (dir==1){
      dir = LOW;
      pwmValue = 40;
      encoderValue = 0;
    }
    else{
        dir = HIGH;
//        pwmValue = 40;
//        encoderValue = 0;
        }
//    encoderValue = 0;
    }
  // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    // Only update display when there is a reading
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print("\n  \n ");
      Serial.print(dir);
    
//    encoderValue = 0;
  }
}

void updateEncoder(){
  // Increment value for each pulse from encoder
  encoderValue++;
}
