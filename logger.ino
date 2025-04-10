/*
CS:   Pin 10
SCK:  Pin 13
MOSI: Pin 11
MISO: Pin 12
*/

void write_log(float gforce_magnitude) {
  String text = String(gforce_magnitude, 3);
  File dataFile = SD.open("datalog.txt");

  if (dataFile) {
    dataFile.write(text);
  }

  dataFile.close();
}

void read_log() {
  if (!Serial) {
    return;
  }
  File dataFile = SD.open("datalog.txt");

  if (dataFile) {
    Serial.write(dataFile.read());
  }

  dataFile.close();
}
