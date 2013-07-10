/*
  SD card datalogger
 
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 

 */
// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;


File logFile;
char filename[15];
char fastname[15];

void setup_SDcard() {
  Serial.print(F("Initializing SD card..."));
  
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println(F("Card failed, or not present"));
    // don't do anything more:
    return;
  }
  Serial.println(F("card initialized."));
  
  
  byte file_no = 0;

  do {
    sprintf(filename, "Log%d.txt", file_no);
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
  
    file_no++;
  }while(SD.exists(filename)); 
    
    logFile.close();
    sprintf(filename, "Log%d.txt", file_no-1);
    sprintf(fastname, "Fast%d.txt", file_no-1);
    Serial.print("Fis");
    Serial.println(filename);
    
       
}

void dump2SD(String s){
    
    logFile = SD.open(filename, FILE_WRITE);
    logFile.println(s);
    logFile.close();
  
}

void dumpRC2SD(String s){
    
    logFile = SD.open(fastname, FILE_WRITE);
    logFile.print(s);
    logFile.print(",");
    logFile.print(temp);
    logFile.print(",");
    logFile.print(pres);
    logFile.print(",");
    logFile.print(altit);
    logFile.println(";");
    logFile.close();
    
    Serial.println(s);
}


