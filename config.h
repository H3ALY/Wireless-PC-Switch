#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi Settings
const char* ssid = "YOUR_WIRELESS_SSID";
const char* password = "YOUR_WIRELESS_PASSWORD";

// MQTT Settings
const char* mqtt_server = "YOUR_MQTT_SERVER_ADDRESS";
const int mqtt_port = 1883;
const char *mqtt_user = "YOUR_MQTT_USERNAME";
const char *mqtt_pass = "YOUR_MQTT_PASSWORD";
const char *mqtt_client_name = "YOUR_MQTT_CLIENT_NAME";

// OTA Settings
const char *ota_hostname = "YOUR_OTA_HOSTNAME";
const bool enable_ota = true;

#endif
