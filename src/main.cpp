#include <Arduino.h>
/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" <mac>.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

const char* applicationUUID = "1234567890";
const char* ssid = "resin-hotspot";
const char* password = "resin-hotspot";

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

void setup(void) {
    Serial.begin(115200);
    Serial.println();

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(2, HIGH);

    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    WiFi.hostname(applicationUUID);

    Serial.print("Connecting");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected");

    MDNS.begin(applicationUUID);
    httpUpdater.setup(&httpServer);
    httpServer.begin();
    MDNS.addService("http", "tcp", 90);
}

void loop(void) {
    if (WiFi.isConnected() == true) {
        digitalWrite(2, LOW);
        Serial.println("Connected");
    } else {
        digitalWrite(2, HIGH);
        Serial.println("Disconnected");
    }
    httpServer.handleClient();

    // Uncomment for blinky lights :)
    /* digitalWrite(LED_BUILTIN, LOW); */
    /* delay(100); */
    /* digitalWrite(LED_BUILTIN, HIGH); */
    /* delay(100); */
}
