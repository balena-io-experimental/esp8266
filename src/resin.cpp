#include "resin.h"

Resin::Resin(){}
Resin::~Resin(){}

void Resin::Setup(String  deviceType, String applicationUUID, String split, String ssid, String password, bool led) {
    _deviceType = deviceType;
    _applicationUUID = applicationUUID;
    _split = split;
    _ssid = ssid;
    _password = password;
    _led = led;

    if (_led) {
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, HIGH);
    }

    String host = _deviceType + _split + _applicationUUID + _split + ESP.getChipId();

    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    WiFi.hostname(host);
    WiFi.begin(_ssid.c_str(), _password.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
    }

    while (!MDNS.begin(host.c_str())) {
        delay(250);
    }

    _httpServer = ESP8266WebServer(80);
    _httpUpdater.setup(&_httpServer);
    _httpServer.begin();

    MDNS.addService("http", "tcp", 80);
}

void Resin::Loop() {
    _httpServer.handleClient();

    if (_led) {
        if (WiFi.isConnected()) {
            digitalWrite(LED_BUILTIN, LOW);
        } else {
            digitalWrite(LED_BUILTIN, HIGH);
        }
    }
}
