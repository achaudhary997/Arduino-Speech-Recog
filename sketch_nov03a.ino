#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
int led1 = 13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(38400);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(led1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Genotronex.available()) {
    BluetoothData = Genotronex.read();
    if (BluetoothData == '1') { // if number 1 pressed ....
      digitalWrite(led1, 1);
      Genotronex.println("LED  On D13 ON ! ");
    }
    if (BluetoothData == '0') { // if number 0 pressed ....
      digitalWrite(led1, 0);
      Genotronex.println("LED  On D13 Off ! ");
    }
  }
  delay(100);// prepare for next data ...
}
