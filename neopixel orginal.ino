#include <Adafruit_NeoPixel.h>

// ----------------------------
// USER SETTINGS
// ----------------------------
#define PIXEL_PIN   6      // Pin connected to NeoPixel strip
#define NUMPIXELS   30     // Change to your strip length
#define BRIGHTNESS  50     // 0–255 (keep lower to prevent power issues)

// ----------------------------
// CREATE STRIP OBJECT
// ----------------------------
Adafruit_NeoPixel strip(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// ----------------------------
// TIMER VARIABLES
// ----------------------------
long totalSeconds = 0;
bool timerRunning = false;

// ----------------------------
// FUNCTION: Update NeoPixels based on seconds remaining in current minute
// ----------------------------
void updateNeoPixels(int secondsRemainingInMinute)
{
  // Map seconds to number of pixels ON
  int pixelsOn = map(secondsRemainingInMinute, 60, 0, NUMPIXELS, 0);

  for (int i = 0; i < NUMPIXELS; i++)
  {
    if (i < pixelsOn)
    {
      strip.setPixelColor(i, strip.Color(0, 150, 0)); // GREEN ON
    }
    else
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0));   // OFF
    }
  }

  strip.show();
}

// ----------------------------
// FUNCTION: Turn all pixels OFF
// ----------------------------
void turnOffStrip()
{
  strip.clear();
  strip.show();
}

// ----------------------------
// SETUP
// ----------------------------
void setup()
{
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();

  Serial.println("=== NeoPixel Countdown Timer ===");
  Serial.println("Enter time in minutes:");

  // Wait for user input
  while (Serial.available() == 0)
  {
    // wait
  }

  int minutes = Serial.parseInt();

  totalSeconds = (long)minutes * 60;

  if (totalSeconds <= 0)
  {
    Serial.println("Invalid input.");
    turnOffStrip();
    return;
  }

  timerRunning = true;

  Serial.print("Timer started for ");
  Serial.print(totalSeconds);
  Serial.println(" seconds");
}

// ----------------------------
// LOOP
// ----------------------------
void loop()
{
  if (timerRunning && totalSeconds > 0)
  {
    // Determine position within current 60-second cycle
    int secondsInMinute = totalSeconds % 60;

    // Reset strip at each new minute
    if (secondsInMinute == 0)
    {
      secondsInMinute = 60;
    }

    // Update NeoPixels
    updateNeoPixels(secondsInMinute);

    // Print remaining time
    Serial.print("Seconds remaining: ");
    Serial.println(totalSeconds);

    delay(1000);

    totalSeconds--;
  }
  else if (timerRunning && totalSeconds <= 0)
  {
    Serial.println("Time's Up!");

    turnOffStrip();

    timerRunning = false;
  }
}
