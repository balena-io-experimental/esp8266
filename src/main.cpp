#include <resin.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>

// Network and resin related stuff
Resin resin;
String applicationUUID = "1234567890";
String ssid = "resin-hotspot";
String password = "resin-hotspot";

// OLED display
// https://learn.adafruit.com/adafruit-oled-featherwing/overview
Adafruit_SSD1306 display = Adafruit_SSD1306();

// Temperature and humidity
// https://www.losant.com/blog/getting-started-with-the-esp8266-and-dht22-sensor
#define DHT_PIN 2
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

// Light
// https://learn.adafruit.com/photocells/using-a-photocell
#define LDR_PIN A0

// Time keeping
#define NTP_ADDRESS  "europe.pool.ntp.org"
#define NTP_OFFSET 0
#define NTP_INTERVAL 0
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

// Data publishing
String publishURL = "localhost/api/publish/";

bool httpPost(String topic, float value)
{
    String urlBuilder = publishURL + topic;
    String dataBuilder = "{\"value\": \"" + String(value) + "\", \"created_at\": \"" + String(timeClient.getEpochTime()) + "\"}";

    Serial.print("URL: ");
    Serial.print(urlBuilder);
    Serial.print(" DATA: ");
    Serial.println(dataBuilder);

    HTTPClient http;
    http.begin(urlBuilder);
    http.addHeader("Content-Type", "application/json");
    http.POST(dataBuilder);
    http.end();
}

void readDHT() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    httpPost("humidity", h);
    httpPost("temperature_c", t);
    httpPost("temperature_f", f);
}

void readLDR() {
    float v = analogRead(LDR_PIN);

    if (isnan(v)) {
      Serial.println("Failed to read from LDR sensor!");
      return;
    }

    httpPost("light", v);
}

void setup(void) {
    // Initialise serial
    Serial.begin(9600);
    while(!Serial) { }

    // Initialise OLED display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();

    // Initialse network and resin related stuff
    resin.Setup(applicationUUID, ssid, password);

    // Initialise time keeping
    timeClient.begin();

    Serial.println("Finished initialisation");
}

int count = 0;
void loop(void) {
    // Refresh the dusplay every 100ms
    if (count % 100 == 0) {
        display.display();
    }

    // Process resin events every 500ms
    if (count % 500 == 0) {
        resin.Loop();
    }

    // Read sensor data every 2 seconds
    if (count % 2000 == 0) {
        readDHT();
        readLDR();
    }

    // Sync the time every 5 seconds
    if (count % 5000 == 0) {
        timeClient.update();
    }

    // Reset the counter every 10 seconds
    count += 100;
    if (count % 10000 == 0) {
        count = 0;
    }

    delay(100);
    yield();
}
