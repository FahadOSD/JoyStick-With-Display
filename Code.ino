

//                             NeuralMesh Solution


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the analog pin connections for X and Y axes of the joystick
const int joyXPin = A0; // Connect joystick X-axis to analog pin A0
const int joyYPin = A1; // Connect joystick Y-axis to analog pin A1

// Define neutral values for the joystick
const int neutralX = 509; // Adjust based on your joystick's neutral X value
const int neutralY = 512; // Adjust based on your joystick's neutral Y value

// Threshold for detecting joystick movement
const int movementThreshold = 10; // Adjust based on your joystick's sensitivity

// Define I2C address for the LCD
const int lcdAddress = 0x27; // Change this based on your LCD's address

// Define LCD dimensions
const int lcdCols = 16;
const int lcdRows = 2;

// Create an instance of the LiquidCrystal_I2C library
LiquidCrystal_I2C lcd(lcdAddress, lcdCols, lcdRows);

void setup() {
  // Serial communication for debugging
  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(lcdCols, lcdRows);
  lcd.backlight();

  // Display initial message
  lcd.print("Joystick Control");
}

void loop() {
  // Read analog values from the joystick
  int joyXValue = analogRead(joyXPin);
  int joyYValue = analogRead(joyYPin);

  // Check if joystick is moved from neutral position
  if (abs(joyXValue - neutralX) > movementThreshold) {
    if (joyXValue > neutralX) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Right");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Left");
    }
  }

  if (abs(joyYValue - neutralY) > movementThreshold) {
    if (joyYValue > neutralY) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Down");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Up");
    }
  }

  delay(1000); // Adjust the delay based on your needs
}
