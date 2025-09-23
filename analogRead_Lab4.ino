// analogRead lab #4: Turn on the LED at a specific value of the potentiometer

int led = 10;
const int pot = A0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(115200);
}

void loop() {

  int value = analogRead(pot);
  Serial.print("Value of Potentiometer: ");
  Serial.println(value);

  int brightness = map(value, 0, 1023, 0, 255);
  Serial.print("brightness: ");
  Serial.println(brightness);

  if (value == 500){
    analogWrite(led, brightness);
  }
  else if (value == 700){
    analogWrite(led, brightness);
  }
  else if (value == 1023){
    analogWrite(led, brightness);
  }
  else {
    analogWrite(led, 0);
  }

  delay(10);
}
