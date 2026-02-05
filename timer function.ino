int countdown_seconds = 0;
int input_minutes = 0;

void setup() {
  Serial.begin(9600);
  
  // Wait for Serial Monitor to open (important on some boards)
  while (!Serial) {}

  Serial.println("Enter countdown time in minutes:");
  
  // Wait until user enters something
  while (Serial.available() == 0) {
    // wait for input
  }

  // Read the minutes entered
  input_minutes = Serial.parseInt();

  // Convert minutes to seconds
  countdown_seconds = input_minutes * 60;

  Serial.print("Starting countdown from ");
  Serial.print(countdown_seconds);
  Serial.println(" seconds...");
  
  // Countdown loop
  while (countdown_seconds >= 0) {

    Serial.print("Time remaining: ");
    
    // Add leading zero if less than 10
    if (countdown_seconds < 10) {
      Serial.print("0");
    }
    
    Serial.println(countdown_seconds);

    delay(1000); // wait 1 second
    
    countdown_seconds--;
  }

  Serial.println("Time's Up!");
}

void loop() {
  // Empty so countdown runs only once
}
