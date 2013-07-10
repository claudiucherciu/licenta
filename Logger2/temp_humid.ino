// Data wire is plugged into port 7 on the Arduino
// Connect a 4.7K resistor between VCC and the data pin (strong pullup)
#define DHT22_PIN 2

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

void read_Temp_Humidity(String &s) {
  static unsigned long last_read = 0;
  if(millis() - last_read < 2000) {
    s += ",,";
    return;
  }
  last_read = millis();
  
  
  static DHT22_ERROR_t errorCode;

  //Serial.print(F("Requesting temp and humidity..."));
  errorCode = myDHT22.readData();
  if(errorCode == DHT_ERROR_NONE)
  {
    char temp[6],humid[6];
    s += "," + String(itoa(myDHT22.getTemperatureC(), temp, 10)) + "," + String(itoa(myDHT22.getHumidity(), humid, 10));
    //Serial.print(myDHT22.getTemperatureC());
    //Serial.print("C ");
    //Serial.print(myDHT22.getHumidity());
    //Serial.println("%");
  }
  
  
}
