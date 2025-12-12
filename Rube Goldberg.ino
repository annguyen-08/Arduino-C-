const int motor1 = 6;
const int motor2 = 3;

const int trig = 10;
const int echo = 11;

long duration;

long distance;
void setup() {
  // put your setup code here, to run once:
  pinMode (motor1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 5)
  {
    digitalWrite (motor1, HIGH);
    digitalWrite (motor2, LOW);
  }
  else
  {
    digitalWrite (motor1, LOW);
    digitalWrite (motor2, LOW);
  }
}
