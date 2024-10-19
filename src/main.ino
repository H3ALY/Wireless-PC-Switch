#include <SimpleTimer.h>
#include "config.h"
#include "core/wifi_setup.h"
#include "core/mqtt_handler.h"
#include "core/power_control.h"

#if enable_ota
#include "core/ota_setup.h"
#endif

WiFiClient espClient;
MqttClient mqttClient(espClient);
PowerController powerController(14, 16, mqttClient.client);
#if enable_ota
OtaManager otaManager;
#endif
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
#if enable_ota
    otaManager.setupOTA();
#endif

    timer.setInterval(3000, []() { powerController.sensePower(); });
    timer.setInterval(120000, []() { mqttClient.publish(check_in_topic, "OK"); });
}

void loop() {
    mqttClient.loop();
#if enable_ota
    otaManager.handleOTA();
#endif
    timer.run();
}
