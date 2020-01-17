# ESP32_Cayenne_Basic
Basic setup of ESP32s-aithinker with DHT11 sensor with Cayenne myDevices.

The sketch reads temperature and humidity from a DHT11 sensor and upload the data on two channels in Cayenne myDevices platform on a predefined period.
ESP32 is put in deep sleep mode when not used, which disables all commucation of the chip.

## What you need 
* ESP32s NodeMcu ai-thinker or other ESP8266/ESP32 board
* DHT11 sensor
* Cayenne myDevices account

## Libraries used
* [Cayenne MQTT ESP32 library] (https://github.com/myDevicesIoT/Cayenne-MQTT-ESP)
* [DHT sensor library] (https://github.com/adafruit/DHT-sensor-library)