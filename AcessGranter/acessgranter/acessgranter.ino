int count = 0;
char rfidData[12]; // Adjust the array size based on your RFID card format

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    count = 0;
    while (count < 12) // Change 12 to the length of your RFID data
    {
      char input = Serial.read();
      if (input != '\n') // Assuming newline as a delimiter, change it to your RFID card's delimiter
      {
        rfidData[count] = input;
        count++;
      }
      delay(5);
    }

    // Print the RFID data to the serial monitor
    Serial.print("RFID Data: ");
    Serial.println(rfidData);

    Serial.println("Access granted");
  }
}
