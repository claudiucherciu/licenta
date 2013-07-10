#include <SD.h>
#include <DHT22.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

float temp, altit;
int32_t pres;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  Serial.println("Boot");

  setup_SDcard();
  setup_bmp();
  
  dump2SD("ADC0,ADC1,ADC2,Temp,Umid,Temp,Pres,Alt");
  
}

String dataString;

void loop()
{
  static unsigned int s1 = 0, s2 = 0, s3 = 0;
  read_RC(s1,s2,s3);
  
  static unsigned long last_fast_write = 0;
  
  if((millis() - last_fast_write > 99)) {
    
    dataString = String(s1) + ',' + String(s2) + ',' + String(s3) + ';'; 
    Serial.println(dataString);
    dumpRC2SD(dataString);
    s1 = s2 = s3 = 0;
    
    last_fast_write = millis();
  }
  
  
  
  static unsigned long last_read = 0;
  if(millis()-last_read < 2000) {
    //wait some more
    return;
  }
  last_read = millis();
  
  // refresh string
  dataString = "";


  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    
    //skip first comma
    if (analogPin!= 0)
      dataString += ",";
    dataString += String(sensor);
  }
  
  

  //DHT22
  //Serial.println(F("Reading temp."));
  read_Temp_Humidity(dataString);
  
  //BMP085
  //Serial.println(F("Reading pres."));
  read_Temp_Pressure(dataString);


  
  
  //Serial.println(dataString);
  dump2SD(dataString);
  
  Serial.print("free:");
  Serial.println(freeRam());
  
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
