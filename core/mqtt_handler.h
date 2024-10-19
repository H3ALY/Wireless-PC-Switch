#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

#include <PubSubClient.h>
#include "config.h"

class MqttClient {
private:
    WiFiClient& espClient;
    PubSubClient client;
    bool boot;

public:
    MqttClient(WiFiClient& clientRef) 
        : espClient(clientRef), client(clientRef), boot(true) {}

    void setCallback(MQTT_CALLBACK_SIGNATURE) {
        client.setCallback(callback);
    }

    void setupMqtt() {
        client.setServer(mqtt_server, mqtt_port);
    }

    void reconnect() {
        int retries = 0;
        while (!client.connected()) {
            if (retries < 5) {
                Serial.print("Attempting MQTT connection...");
                if (client.connect(mqtt_client_name, mqtt_user, mqtt_pass)) {
                    Serial.println("connected");
                    handleCheckIn();
                    client.subscribe("commands/PC");
                } else {
                    logError("Failed to connect, rc=", client.state());
                    retries++;
                    delay(5000);
                }
            } else {
                ESP.restart();
            }
        }
    }

    void handleCheckIn() {
        const char* checkInMessage = boot ? "Rebooted" : "Reconnected";
        client.publish(check_in_topic, checkInMessage);
        boot = false;  // Set boot to false after first connection
    }

    void loop() {
        if (!client.connected()) {
            reconnect();
        }
        client.loop();
    }

    void publish(const char* topic, const char* message, bool retain = false) {
        client.publish(topic, message, retain);
    }

private:
    void logError(const char* message, int code) {
        Serial.print(message);
        Serial.println(code);
    }
};

#endif
