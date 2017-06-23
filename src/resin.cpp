#include "resin.h"

Resin::Resin(){}
Resin::~Resin(){}

void Resin::Setup(const char* applicationUUID, const char* ssid, const char* password, bool led) {
    _applicationUUID = applicationUUID;
    _ssid = ssid;
    _password = password;
    _led = led;

    Serial.begin(115200);

    if (_led) {
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, HIGH);
    }

    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    WiFi.begin(_ssid, _password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
    }

    _httpServer = ESP8266WebServer(80);
    _httpUpdater = ESP8266HTTPUpdateServer();

    _httpServer.on("/id", [&](){
        _httpServer.send(200, "text/plain", _applicationUUID);
    });

    _httpServer.begin();
    _httpUpdater.setup(&_httpServer);
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
