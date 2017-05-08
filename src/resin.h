#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#ifndef Resin_H
#define Resin_H

class Resin {
    public:
        Resin();
        ~Resin();

        void Setup(String applicationUUID, String ssid, String password, bool led=true);
        void Loop();

    private:
        ESP8266WebServer _httpServer;
        ESP8266HTTPUpdateServer _httpUpdater;

        String _applicationUUID;
        String _ssid;
        String _password;
        bool _led;
};

#endif
