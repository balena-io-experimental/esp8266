#include <resin.h>

Resin resin;
String applicationUUID = "1234567890";
String ssid = "resin-hotspot";
String password = "resin-hotspot";

void setup(void) {
    resin.Setup(applicationUUID, ssid, password);
}

void loop(void) {
    resin.Loop();
    delay(1000);
}
