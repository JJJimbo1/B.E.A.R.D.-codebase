/*
CS:   Pin 10
SCK:  Pin 13
MOSI: Pin 11
MISO: Pin 12
5 Volts
*/

#include <SPI.h>
#include <SD.h>

const int sd_chipSelect = 10;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  SD.begin(sd_chipSelect);
  // Uncomment to reset the log
  // reset_log();
}

void loop() {
  write_log();
  read_log();
  delay(1000);
}

void write_log() {
  File dataFile = SD.open("datalog.txt");
  if (!dataFile) { Serial.println("write_log: Error opening datalog.txt"); return; }

  String text = String(dataFile.parseInt() + 1);

  dataFile.close();

  dataFile = SD.open("datalog.txt", FILE_WRITE | O_TRUNC);

  if (dataFile) {
    dataFile.println(text);
  }

  dataFile.close();
}

void read_log() {
  if (!Serial) { return; }
  File dataFile = SD.open("datalog.txt");
  if (!dataFile) { Serial.println("read_log: Error opening datalog.txt"); return; }

  Serial.print("Dangerous Driving Events: ");
  Serial.println(dataFile.parseInt());

  dataFile.close();
}

void reset_log() {
  if (SD.exists("datalog.txt")) {
    SD.remove("datalog.txt");
  }
  SD.open("datalog.txt", FILE_WRITE).close();
}
