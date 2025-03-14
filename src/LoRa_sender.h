#include <Arduino.h>
//Incuding arduino default SPI library
#include <SPI.h>
//Incuding LoRa library
#include <LoRa.h>

#include <ArduinoJson.h>

//define the pins used by the transceiver module
#define NSS 4
#define RST 5
#define DI0 2

// Source: https://embeddedthere.com/esp32-lora-tutorial-using-arduino-ide/

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);

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

  // Change sync word (0xF8) to match the receiver LoRa
  // This code ensure that you don't get LoRa messages
  // from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF8);
  Serial.println("LoRa Initializing Successful!");
}

int count = 0;

String message = "";

void loop() {

  JsonDocument doc;

  doc["confidence_score"] = random(70,99)/100.0;
  doc["device_id"] = 753;

  serializeJson(doc, message);

  unsigned long currentTime = millis();

  while(true){

    String LoRaData = "";

    // LoRa data packet size received from LoRa sender
    int packetSize = LoRa.parsePacket();

    // if the packer size is not 0, then execute this if condition
    if (packetSize) {
      
      // received a packet
      Serial.print("Received packet: ");

      // receiving the data from LoRa sender
      while (LoRa.available()) {
        LoRaData = LoRa.readString();
      }
      Serial.println(LoRaData);
    }

    if(LoRaData == "Received"){
      break;
    }

    if(millis()-currentTime >= 2000){
      Serial.println("Sending packet: " + message);

      // Start sending message via LoRa
      LoRa.beginPacket();
      LoRa.print(message.c_str());
      LoRa.endPacket();
      currentTime = millis();
    }
  }
}