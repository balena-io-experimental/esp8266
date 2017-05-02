#include <resin.h>

Resin resin;
const char* applicationUUID = "1234567890";
const char* ssid = "resin-hotspot";
const char* password = "resin-hotspot";

void setup(void) {
    resin.Setup(applicationUUID, ssid, password);
}

void loop(void) {
    resin.Loop();
    delay(1000);
}
