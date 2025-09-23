// analogRead lab #5: Blink the LED at the specific brightness corresponding to the potentiometer value with the blinking speed also corresponding to the potentiometer value

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

  if (value <= 500){
    analogWrite(led, brightness);
    delay(10);
    analogWrite(led, 0);
    delay(10);
  }
  else if (value <= 700 || value > 500){
    analogWrite(led, brightness);
    delay(100);
    analogWrite(led, 0);
    delay(100);
  }
  else if (value > 700){
    analogWrite(led, brightness);
    delay(700);
    analogWrite(led, 0);
    delay(700);
  }

  delay(10);
}
