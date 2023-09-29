#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  digitalWrite(D1, pinValue); // Control the LED
}

BLYNK_WRITE(V2) {
  String voiceCommand = param.asStr();
  if (voiceCommand == "turn on the light") {
    Blynk.virtualWrite(V1, 1); // Turn on the LED
  } else if (voiceCommand == "turn off the light") {
    Blynk.virtualWrite(V1, 0); // Turn off the LED
  }
}
