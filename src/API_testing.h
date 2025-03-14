// #include <Arduino.h>
// #include <WiFi.h>
// #include <HTTPClient.h>

// const char WIFI_SSID[] = "Server";
// const char WIFI_PASSWORD[] = "12345678901";

// String HOST_NAME   = "https://wildtechalert-39e415aada0a.herokuapp.com/health";

// void setup() {
//   Serial.begin(115200);

//   // Wi-Fi connection
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.print("Connected to WiFi network with IP Address: ");
//   Serial.println(WiFi.localIP());

//   HTTPClient http;

//   http.begin(HOST_NAME);
//   http.setAuthorization("7f89940a-bdc5-47bc-9743-f4b2ba20f64e");
//   int httpCode = http.GET();

//   // httpCode will be negative on error
//   if (httpCode > 0) {
//     // file found at server
//     if (httpCode == HTTP_CODE_OK) {
//       String payload = http.getString();
//       Serial.println(payload);
//     } else {
//       // HTTP header has been send and Server response header has been handled
//       Serial.printf("[HTTP] GET... code: %d\n", httpCode);
//     }
//   } else {
//     Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//   }

//   http.end();
// }

// void loop() {
  
// }