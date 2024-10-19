#ifndef OTA_SETUP_H
#define OTA_SETUP_H

#include <ArduinoOTA.h>
#include "config.h"

class OtaManager {
public:
    void setupOTA() {
        ArduinoOTA.setHostname(ota_hostname);
        ArduinoOTA.begin();
    }

    void handleOTA() {
        ArduinoOTA.handle();
    }
};

#endif
