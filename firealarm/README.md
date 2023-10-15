# <h1 align="center"> Alarming using Flame sensor module & Buzzer</h1>

This project can serve in offices & other indoor workplaces to detect and alarm about fire 

# Key Feature
- Buzzer starts to sound when it detects flame
- When no flame is detected green LED is ON.
- When flame detected red LED is turned ON.

 <p align="center">
<image src="circuit.png"
width="500px"
position="center">
</p>
<br> 

## Items which are required to make this project are listed below
- Arduino UNO
- Flame Sensor
- LED
- Buzzer
- BreadBoard
- Jumpers

## code
```
//Arduino Flame Sensor
//By-Shubhankar
const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
}


```
