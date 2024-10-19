#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H

#include <ESP8266WiFi.h>
#include "config.h"

class WiFiManager {
public:
    void setup_wifi() {
        Serial.print("Connecting to ");
        Serial.print(ssid);  // Use Serial.print instead of Serial.println
        WiFi.begin(ssid, password);

        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }

        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
};

#endif
