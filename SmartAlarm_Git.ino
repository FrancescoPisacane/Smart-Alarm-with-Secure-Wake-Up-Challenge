#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

Servo servo1;

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address and display dimensions
const int triggerPin = 10; // Trigger pin for the ultrasonic sensor
const int echoPin = 11;    // Echo pin for the ultrasonic sensor
const int pumpPin = 12;    // Pump pin

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6, 7, 8, 9}; // Row connections
byte colPins[COLS] = {2, 3, 4, 5}; // Column connections
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

bool displayRandomNumbers = false;
int randomNumbers[3];

unsigned long lastMeasurementTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.begin(16, 2);
  
  servo1.attach(13);
  servo1.write(180); // Start in a neutral position
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pumpPin, OUTPUT);

  randomSeed(analogRead(0)); // Initialize random to get truly random numbers
  
  Serial.begin(9600);
}

void loop() {
  if (millis() - lastMeasurementTime >= 2000) {
    measureDistance();
    lastMeasurementTime = millis();
  }

  if (displayRandomNumbers) {
    displayRandom();
  }
}

void measureDistance() {
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= 35) {
    displayRandomNumbers = true;
  } else {
    displayRandomNumbers = false;
    displayDistance(distance);
  }
}

void displayDistance(long distance) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void displayRandom() {

  servo1.write(180);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Person");
  lcd.setCursor(0, 1);
  lcd.print("detected");

  delay(2000);

  lcd.clear();
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.print("Fire!!!");
  delay(1000);
  lcd.clear();
  
  digitalWrite(pumpPin, HIGH); // Set MOSFET pin to HIGH to activate pump
  delay(800);
  digitalWrite(pumpPin, LOW);
  delay(100);

  lcd.print("5");
  delay(1000);
  lcd.clear();
  lcd.print("4");
  delay(1000);
  lcd.clear();
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.print("1");
  delay(1000);

  lcd.clear();
  lcd.print("Step 1");
  delay(1000);
  
  generateRandomNumbers();

  int sum = 0;
  for (int i = 0; i < 3; ++i) 
  {
    sum += randomNumbers[i];
  }

  while (true)
  {
    int userInput = 0;
    lcd.clear(); // Display random numbers
    lcd.setCursor(0, 0);
    lcd.print("Random numbers: ");
  
    for (int i = 0; i < 3; i++) // Print random numbers
    {
      lcd.setCursor(i * 5, 1);
      lcd.print(randomNumbers[i]);
      lcd.print(" ");
    }
    while (true) 
    {
      char key = keypad.getKey();
      if (key >= '0' && key <= '9') {
        userInput = userInput * 10 + (key - '0');
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Answer: ");
        lcd.print(userInput);
  
        Serial.print("User input: ");
        Serial.println(userInput);
    } else if (key == 'A') {
      break;
    }
  }

  if (userInput == sum) {
    lcd.clear();
    lcd.print("Correct!");
    delay(1000);
 
    break; // Move to step 2
    
  } else {
    lcd.clear();
    lcd.print("Incorrect result");
    lcd.setCursor(0, 1);
    lcd.print("Try again!");
    delay(2000); // Add a slight delay before clearing the display
  }
  }

  lcd.clear();
  lcd.print("Step 2");
  delay(1000);

  generateRandomNumbers();

  sum = 0;
  for (int i = 0; i < 3; ++i) 
  {
    sum += randomNumbers[i];
  }

  while (true)
  {
    int userInput = 0;
    lcd.clear(); // Display random numbers
    lcd.setCursor(0, 0);
    lcd.print("Random numbers: ");
  
    for (int i = 0; i < 3; i++) // Print random numbers
    {
      lcd.setCursor(i * 5, 1);
      lcd.print(randomNumbers[i]);
      lcd.print(" ");
    }
    while (true) 
    {
      char key = keypad.getKey();
      if (key >= '0' && key <= '9') {
        userInput = userInput * 10 + (key - '0');
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Answer: ");
        lcd.print(userInput);
  
        Serial.print("User input: ");
        Serial.println(userInput);
    } else if (key == 'A') {
      break;
    }
  }

  if (userInput == sum) {
    lcd.clear();
    lcd.print("Correct!");
    lcd.setCursor(0, 1);
    lcd.print("Are you awake? :)");
    delay(2000);

    for (int i=180; i>= 90; i--)
    {
      servo1.write(i);
      delay(4);
    }

    lcd.clear();
    lcd.print("Lock");
    lcd.setCursor(0, 1);
    lcd.print("unlocked");
    delay(3000);

    for (int i=90; i< 180; i++)
    {
      servo1.write(i);
      delay(4);
    }

    displayRandomNumbers = false; // Set to false to measure distance again
 
    break; // Process completed
    
  } else {
    lcd.clear();
    lcd.print("Incorrect result");
    lcd.setCursor(0, 1);
    lcd.print("Try again!");
    delay(2000); // Add a slight delay before clearing the display
  }
  }
  
}

void generateRandomNumbers() {
  for (int i = 0; i < 3; i++) {
    randomNumbers[i] = random(80);
  }
}

