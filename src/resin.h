#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#ifndef Resin_H
#define Resin_H

class Resin {
    public:
    Resin();
    ~Resin();

    void Setup(const char* applicationUUID, const char* ssid, const char* password, bool led=true);
    void Loop();

    private:
        ESP8266WebServer _httpServer;
        ESP8266HTTPUpdateServer _httpUpdater;

        const char* _applicationUUID;
        const char* _ssid;
        const char* _password;
        bool _led;
};

#endif
