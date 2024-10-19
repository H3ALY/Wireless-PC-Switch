#include <SimpleTimer.h>
#include "wifi_setup.h"
#include "mqtt_handler.h"
#include "power_control.h"
#include "ota_setup.h"
#include "config.h"

WiFiClient espClient;
MqttClient mqttClient(espClient);
PowerController powerController(14, 16, mqttClient.client);
OtaManager otaManager;
SimpleTimer timer;

void mqttCallback(char* topic, byte* payload, unsigned int length) {
    payload[length] = '\0';
    String command = String((char*)payload);
    powerController.handleCommand(command);
}

void setup() {
    Serial.begin(115200);
    WiFiManager wifiManager;
    wifiManager.setup_wifi();

    mqttClient.setCallback(mqttCallback);
    mqttClient.setupMqtt();

    powerController.setup();
    otaManager.setupOTA();

    timer.setInterval(3000, []() { powerController.sensePower(); });
    timer.setInterval(120000, []() { mqttClient.publish(check_in_topic, "OK"); });
}

void loop() {
    mqttClient.loop();
    otaManager.handleOTA();
    timer.run();
}
