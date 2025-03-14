#include <Arduino.h>
//Incuding arduino default SPI library
#include <SPI.h>
//Incuding LoRa library
#include <LoRa.h>

//define the pins used by the transceiver module
#define NSS 4
#define RST 5
#define DI0 2

// Source: https://embeddedthere.com/esp32-lora-tutorial-using-arduino-ide/


void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);

  //Attaching an Interrupt to pin 25 (BUTTON pin) 
  Serial.println("LoRa Sender");
  //setup LoRa sender
  LoRa.setPins(NSS, RST, DI0);
  //Select the frequency accordng to your location
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
  // Change sync word (0xF1) to match the receiver LoRa
  // This code ensure that you don't get LoRa messages
  // from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF8);
  Serial.println("LoRa Initializing Successful!");
}

int count = 0;

void loop() {
  String output = "on-" + String(count);
  Serial.print("Sending packet: ");
  //If the button_status is 1, Send LoRa packet "on" to receiver LoRa
  LoRa.beginPacket();
  LoRa.print(output.c_str());
  LoRa.endPacket();
  Serial.println("sent lora to " + output);
  delay(5000);
  count++;
}