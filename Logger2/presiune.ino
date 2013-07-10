// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here


Adafruit_BMP085 bmp;

#define SEA_LEVEL_PRESSURE 101755


void setup_bmp(){
  
    if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    }
    
}




void read_Temp_Pressure(String &s) {
  
    //char temp[7], pres[10], altit[12];
    
    
    /*
    Serial.print("T:");
    Serial.print(bmp.readTemperature());
    Serial.print("*C ");
    
    Serial.print("P");
    Serial.print(bmp.readPressure());
    Serial.print("Pa ");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Alt:");
    Serial.print(bmp.readAltitude(SEA_LEVEL_PRESSURE));
    Serial.println("m");
    */
    
    temp = bmp.readTemperature();
    //sprintf(temp, "%f", temp1);
    
    pres = bmp.readPressure();
    //sprintf(pres, "%l", temp2);
    
    altit = bmp.readAltitude(SEA_LEVEL_PRESSURE);
    //sprintf(altit, "%f", temp1);
    /*
     s += "," + String(temp) 
        + "," + String(pres)
        + "," + String(altit);
        
     */
     //Serial.println(s);
}
