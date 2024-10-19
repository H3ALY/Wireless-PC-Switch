# Wireless PC Switch

The Wireless PC Switch allows you to "physically" power on your PC over WLAN (Wireless Local Area Network). This project utilizes the ESP8266 microcontroller to enable remote power control of your PC using the MQTT (Message Queuing Telemetry Transport) protocol.

With this project, users can seamlessly power on their PCs from anywhere within the Wi-Fi network. The ESP8266 connects to your local Wi-Fi, communicates with an MQTT broker, and responds to power commands, making it a valuable addition to your home automation system.

## Features

- **Wi-Fi Connectivity**: Seamlessly connects to your local Wi-Fi network for remote access.
- **MQTT Protocol**: Utilizes MQTT for lightweight and efficient communication between devices.
- **Remote Power Control**: Enables users to power on their PC from anywhere within the Wi-Fi range.
- **Status Monitoring**: Monitors the power state detected by the ESP8266, indicating whether the connected device (PC) is powered on or off.
- **Configurable**: Simple adjustments can be made to the settings for Wi-Fi and MQTT broker in the `config.h` file.
- **Optional OTA Updates**: Supports Over-The-Air (OTA) firmware updates (can be enabled or disabled as needed).
- **Modular Design**: Organized code structure with separate files for improved readability, maintainability, and development ease.

## Installation

For detailed installation instructions and configuration steps, please refer to the [Wiki](https://github.com/H3ALY/Wireless-PC-Switch/wiki)

## Acknowledgements

This project uses the following libraries:

- **PubSubClient**: MQTT library for Arduino (Licensed under [MIT License](https://github.com/knolleary/pubsubclient/blob/master/LICENSE))
- **SimpleTimer**: Simple timer library for Arduino (Licensed under [MIT License](https://github.com/jfturcot/SimpleTimer/blob/master/LICENSE))
- **ArduinoOTA**: Arduino Over-the-Air Updates (Licensed under [MIT License](https://github.com/esp8266/Arduino/blob/master/libraries/ArduinoOTA/LICENSE))

These libraries are included in this project and are subject to their respective licenses.
