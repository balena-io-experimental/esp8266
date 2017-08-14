#include <resin.h>

Resin resin;
String applicationUUID = "1234567890";
String deviceType = "ESP8266";
String split = "_";
String ssid = "resin-hotspot";
String password = "resin-hotspot";

void setup(void) {
    resin.Setup(deviceType, applicationUUID, split, ssid, password);
}

void loop(void) {
    resin.Loop();
    delay(1000);
}
