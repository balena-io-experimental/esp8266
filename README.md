# ESP8266
edge-node-manager compatible firmware for the ESP8266

### Getting started
 - Ensure you have [PlatformIO Core](http://docs.platformio.org/en/latest/installation.html) installed on your local machine
 - Sign up on [resin.io](https://dashboard.resin.io/signup)
 - Work through the [getting started guide](https://docs.resin.io/raspberrypi3/nodejs/getting-started/)
 - Create a dependent application called `esp8266`
 - Set these variables in the `Fleet Configuration` dependent application side tab
    - `RESIN_SUPERVISOR_DELTA=1`
    - `RESIN_HOST_TYPE=esp8266`
 - Clone this repository to your local workspace
 - Add the dependent application `resin remote` to your local workspace
 - Retrieve the dependent application ID from the [Dependent Applications](application_id.png) page on the Resin dashboard
 - Change [line 4](https://github.com/resin-io-projects/esp8266/blob/master/src/main.cpp#L4) in `src/main.cpp` `String applicationUUID = "1234567890";` to point to your dependent application ID e.g. `String applicationUUID = "540116";`
 - Connect the ESP8266 to your computer using a USB cable
 - Run `platformio run --environment huzzah --target upload` to compile the initial firmware and flash the ESP8266 (replace `huzzah` with a different board ID from the table below if you are not using the `huzzah`)
 - Push code to resin as normal :)

### Note
You will need to ensure your Raspberry Pi 3 has a spare WiFi interface

### Supported ESP8266 boards
The supported boards are shown below, if you are not using the `huzzah` you will need to change [line 9](https://github.com/resin-io-projects/esp8266/blob/master/Dockerfile#L9) in the `Dockerfile` to the ID of the board you are using

| ID               | MCU     | Frequency | Flash  | RAM  | Name                                  |
|------------------|---------|-----------|--------|------|---------------------------------------|
| huzzah           | ESP8266 | 80Mhz     | 4096kB | 80kB | Adafruit HUZZAH ESP8266               |
| esp_wroom_02     | ESP8266 | 80Mhz     | 4096kB | 80kB | ESP-WROOM-02                          |
| espduino         | ESP8266 | 80Mhz     | 4096kB | 80kB | ESPDuino (ESP-13 Module)              |
| espino           | ESP8266 | 80Mhz     | 4096kB | 80kB | ESPino                                |
| espectro         | ESP8266 | 80Mhz     | 4096kB | 80kB | ESPrectro Core                        |
| espresso_lite_v1 | ESP8266 | 80Mhz     | 4096kB | 80kB | ESPresso Lite 1.0                     |
| espresso_lite_v2 | ESP8266 | 80Mhz     | 4096kB | 80kB | ESPresso Lite 2.0                     |
| esp12e           | ESP8266 | 80Mhz     | 4096kB | 80kB | Espressif ESP8266 ESP-12E             |
| esp01_1m         | ESP8266 | 80Mhz     | 1024kB | 80kB | Espressif Generic ESP8266 ESP-01 1M   |
| esp01            | ESP8266 | 80Mhz     | 512kB  | 80kB | Espressif Generic ESP8266 ESP-01 512k |
| esp07            | ESP8266 | 80Mhz     | 4096kB | 80kB | Espressif Generic ESP8266 ESP-07      |
| esp8285          | ESP8266 | 80Mhz     | 423kB  | 80kB | Generic ESP8285 Module                |
| nodemcu          | ESP8266 | 80Mhz     | 4096kB | 80kB | NodeMCU 0.9 (ESP-12 Module)           |
| nodemcuv2        | ESP8266 | 80Mhz     | 4096kB | 80kB | NodeMCU 1.0 (ESP-12E Module)          |
| modwifi          | ESP8266 | 80Mhz     | 2048kB | 80kB | Olimex MOD-WIFI-ESP8266(-DEV)         |
| phoenix_v1       | ESP8266 | 80Mhz     | 1019kB | 80kB | Phoenix 1.0                           |
| phoenix_v2       | ESP8266 | 80Mhz     | 1019kB | 80kB | Phoenix 2.0                           |
| sparkfunBlynk    | ESP8266 | 80Mhz     | 4096kB | 80kB | SparkFun Blynk Board                  |
| thing            | ESP8266 | 80Mhz     | 512kB  | 80kB | SparkFun ESP8266 Thing                |
| thingdev         | ESP8266 | 80Mhz     | 512kB  | 80kB | SparkFun ESP8266 Thing Dev            |
| esp210           | ESP8266 | 80Mhz     | 4096kB | 80kB | SweetPea ESP-210                      |
| espinotee        | ESP8266 | 80Mhz     | 4096kB | 80kB | ThaiEasyElec ESPino                   |
| d1_mini          | ESP8266 | 80Mhz     | 4096kB | 80kB | WeMos D1 R2 & mini                    |
| d1               | ESP8266 | 80Mhz     | 4096kB | 80kB | WeMos D1(Retired)                     |
| wifinfo          | ESP8266 | 80Mhz     | 423kB  | 80kB | WifInfo                               |
