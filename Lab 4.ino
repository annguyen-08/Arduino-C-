const int yellow = 11;
const int green = 6;
const int orange = 2;

int delay_time = 1000; // set the delay time

void blink (); // function to blink an LED; function prototype
void d_t (); // function to print the delay time

void setup() {
  pinMode (yellow, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (orange, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  blink (yellow, delay_time);
  blink (green, delay_time);
  blink (orange, delay_time);
  d_t (delay_time);
}


// Define the function that blinks the LED
void blink (int LED, int delay_time) {
  digitalWrite (LED, HIGH);
  delay (delay_time);
  digitalWrite (LED, LOW);
  delay (delay_time);
  digitalWrite (LED, HIGH);
  delay (delay_time);
  digitalWrite (LED, LOW);
  delay (delay_time);
}

// Define the function to print out the delay tine
void d_t (int delay_time) {
  int time = delay_time;
  Serial.print("Delay time: ");
  Serial.println(time);
}
