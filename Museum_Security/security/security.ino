// C++ code
// By- Shubhankar Sharma
#include <Adafruit_LiquidCrystal.h>

int ultrasonic_sensor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  ultrasonic_sensor = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(ultrasonic_sensor);

  lcd_1.setCursor(0, 0);
  lcd_1.print("Obj Distance =");
  lcd_1.setCursor(5, 1);
  lcd_1.print(ultrasonic_sensor);
  if (ultrasonic_sensor < 100) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
  if (ultrasonic_sensor < 20) {
    tone(10, 523, 100); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}