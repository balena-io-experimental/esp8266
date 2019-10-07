#include "resin.h"

Resin resin;
String applicationUUID = "1520447";
String deviceType = "ESP8266";
String split = "_";
String ssid = "balena-hotspot";
String password = "balena-hotspot";

void setup(void)
{
    Serial.begin(115200);
    resin.Setup(deviceType, applicationUUID, split, ssid, password);
}

void loop(void)
{
    resin.Loop();
    delay(1000);
}
