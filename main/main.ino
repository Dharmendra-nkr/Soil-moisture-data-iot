#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "secrets.h"

// Pins
const int SoilMoist = A0;
const int LED = D0;

// Relay logic
const byte relayOnState  = LOW;
const byte relayOffState = HIGH;

// WiFi (FROM secrets.h)
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiClient client;

// ThingSpeak
unsigned long myChannelNumber = SECRET_CH_ID;
const char *myWriteAPIKey = SECRET_WRITE_APIKEY;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== ESP8266 START ===");

  pinMode(SoilMoist, INPUT);
  pinMode(LED, OUTPUT);

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {

  // ----- READ SENSOR -----
  int raw = analogRead(A0);
  float moisture =
    100.0 - ((raw / 1023.0) * 100.0);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  // ----- RELAY / LED -----
  if (moisture <= 50) {
    digitalWrite(LED, relayOnState);
  } else {
    digitalWrite(LED, relayOffState);
  }

  // ----- WIFI -----
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting to WiFi: ");
    Serial.println(ssid);

    WiFi.begin(ssid, pass);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
      delay(500);
      Serial.print(".");
      attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nWiFi Connected");
    } else {
      Serial.println("\nWiFi FAILED");
      delay(5000);
      return;
    }
  }

  // ----- THINGSPEAK -----
  int status = ThingSpeak.writeField(
    myChannelNumber,
    1,
    moisture,
    myWriteAPIKey
  );

  if (status == 200) {
    Serial.println("ThingSpeak update SUCCESS");
  } else {
    Serial.print("ThingSpeak error: ");
    Serial.println(status);
  }

  Serial.println("--------------------");
  delay(20000);
}
