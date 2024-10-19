#ifndef CONFIG_VALIDATOR_H
#define CONFIG_VALIDATOR_H

#include <Arduino.h>
#include "config.h"

bool validate_config() {
    bool valid = true;

    if (strcmp(ssid, "YOUR_WIRELESS_SSID") == 0 || strcmp(password, "YOUR_WIRELESS_PASSWORD") == 0) {
        Serial.println("Error: Wi-Fi settings are not properly configured.");
        valid = false;
    }

    if (strcmp(mqtt_server, "YOUR_MQTT_SERVER_ADDRESS") == 0 ||
        strcmp(mqtt_user, "YOUR_MQTT_USERNAME") == 0 ||
        strcmp(mqtt_pass, "YOUR_MQTT_PASSWORD") == 0 ||
        strcmp(mqtt_client_name, "YOUR_MQTT_CLIENT_NAME") == 0) {
        Serial.println("Error: MQTT settings are not properly configured.");
        valid = false;
    }

    if (enable_ota && strcmp(ota_hostname, "YOUR_OTA_HOSTNAME") == 0) {
        Serial.println("Warning: OTA is enabled but the hostname is not properly configured.");
    }

    return valid;
}

#endif
