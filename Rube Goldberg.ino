//DC motor
const int motor1 = 6;
const int motor2 = 5;

//First sensor to detect the team before us
const int trig1 = 10;
const int echo1 = 11;

//Second sensor to detect our marbale
const int trig2 = 3;
const int echo2 = 2;

//Time that the first sensor detects something
long duration1;

//Distance from the first sensor
long distance1;

//Time that the second sensor detects something
long duration2;

//Distance from the second sensor
long distance2;

//Buzzer
const int buzzer = 9;
//************************************//

void setup() {
  pinMode (motor1, OUTPUT);
  pinMode (motor2, OUTPUT);

  pinMode (trig1, OUTPUT);
  pinMode (echo1, INPUT);

  pinMode (trig2, OUTPUT);
  pinMode (echo2, INPUT);

  pinMode (buzzer, OUTPUT);
  Serial.begin (9600);
}

//********************************************//

void loop() {
  //Code for the first sensor
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);

  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  Serial.print ("Distance from the first sensor: ");
  Serial.println (distance1);

  //Code for the DC motor
  int n = 1;

  if (distance1 <= 5 && n == 1)
  {
    analogWrite (motor1, 65);
    analogWrite (motor2, 0);
    n = 0;
  }
  else
  {
    analogWrite (motor1, 0);
    analogWrite (motor2, 0);
    n = 1;
  }
    
  //Code for the second sensor
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);

  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  Serial.print ("Distance from the second sensor: ");
  Serial.println (distance2);

  //Code for the buzzer
  if (distance2 <= 5)
  {
    tone (buzzer, 131, 100);
    delay (100);
    tone (buzzer, 147, 100);
    delay (100);
    tone (buzzer, 165, 100);
    delay (100);
  }
  else 
  {
    tone (buzzer, 0, 0);
  }
}
