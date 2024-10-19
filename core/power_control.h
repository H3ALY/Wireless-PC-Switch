#ifndef POWER_CONTROL_H
#define POWER_CONTROL_H

#include <PubSubClient.h>
#include <SimpleTimer.h>

class PowerController {
private:
    const int powerButtonPin;
    const int powerSensePin;
    String currentStatus = "OFF";
    String oldStatus = "OFF";
    PubSubClient& client;

public:
    PowerController(int btnPin, int sensePin, PubSubClient& mqttClient)
        : powerButtonPin(btnPin), powerSensePin(sensePin), client(mqttClient) {}

    void setup() {
        pinMode(powerSensePin, INPUT_PULLDOWN_16);
        pinMode(powerButtonPin, OUTPUT);
    }

    void sensePower() {
        if (pulseIn(powerSensePin, HIGH, 300000) > 100) {
            setStatus("ON");
        } else if (digitalRead(powerSensePin) == HIGH) {
            setStatus("ON");
        } else {
            setStatus("OFF");
        }
    }

    void setStatus(String status) {
        if (currentStatus != status) {
            currentStatus = status;
            client.publish("state/PC", status.c_str(), true);
            oldStatus = currentStatus;
        }
    }

    void handleCommand(const String& command) {
        if (command == "ON" && currentStatus == "OFF") {
            pressPowerButton();
        } else if (command == "OFF" && currentStatus == "ON") {
            pressPowerButton();
        } else if (command == "FORCE OFF") {
            pressPowerButton(10000);
        }
    }

private:
    void pressPowerButton(int pressDuration = 1000) {
        digitalWrite(powerButtonPin, HIGH);
        delay(pressDuration);
        digitalWrite(powerButtonPin, LOW);
    }
};

#endif
