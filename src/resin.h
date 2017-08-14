#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266mDNS.h>

#ifndef Resin_H
#define Resin_H

class Resin {
    public:
    Resin();
    ~Resin();

    void Setup(String deviceType, String applicationUUID, String split, String ssid, String password, bool led=true);
    void Loop();

    private:
        ESP8266WebServer _httpServer;
        ESP8266HTTPUpdateServer _httpUpdater;

        String _deviceType;
        String _applicationUUID;
        String _split;
        String _ssid;
        String _password;
        bool _led;
};

#endif
