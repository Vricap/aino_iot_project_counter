#include <LiquidCrystal.h>

// Set up the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pins
const int buttonPin = 7;  // Button pin
const int buzzerPin = 8;  // Buzzer pin
const int bulbPin = 9;    // Bulb control pin

// Variables
int counter = 0;
int buttonState = 0; 
int lastButtonState = 0;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  
  // Set up pins
  pinMode(buttonPin, INPUT_PULLUP); // Button input with pull-up resistor
  pinMode(buzzerPin, OUTPUT);      // Buzzer output
  pinMode(bulbPin, OUTPUT);        // Bulb control pin
  
  // Initial LCD message
  lcd.setCursor(0, 0);
  lcd.print("Projects: ");
  lcd.setCursor(0, 1);
  lcd.print(counter);
}

void loop() {
  // Read button state
  buttonState = digitalRead(buttonPin);
  
  // Check if button is pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    counter++;  // Increment counter
    
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Projects: ");
    lcd.setCursor(0, 1);
    lcd.print(counter);

    // Play sound
    tone(buzzerPin, 1000, 200);  // Frequency: 1000Hz, Duration: 200ms

    // Turn on the light bulb
    digitalWrite(bulbPin, HIGH);

    // Delay to keep bulb on for a while
    delay(200); // Keep bulb and buzzer on for 200ms
    
    // Turn off the light bulb
    digitalWrite(bulbPin, LOW);

    delay(200); // Debounce delay
  }
  
  // Save button state for next loop
  lastButtonState = buttonState;
}
