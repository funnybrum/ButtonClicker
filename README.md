# Button Clicker

The ESP8266 button clicker is button clicker that can execute predefined set of click commands on scheduled intervals.

Buttons are wired through mini SSRs (VO1400AEF) on D5, D6, D7 and D8. Scheduler relies on the standard Network Time Protocol and the microcontroller should be connected to a WiFi network with internet access.

On first launch the device will create WiFi access point named "clicker". To configure the WiFi network SSID and password connect to that network and open http://192.168.0.1 . A web page will pop up and allow to specify the network access settings. Click save and reboot to complete the setup process.

PCB can be found on https://oshwlab.com/funnybrum/clicker .

## Building the project

The project uses a common set of tools that are availabe in another repo - https://github.com/funnybrum/esp8266-base. Clone the esp8266-base repo in the lib folder:

```
mkdir lib
cd lib
git clone git@github.com:funnybrum/esp8266-base.git
```

Note: Initial compilation will result in failure. Open the lib/esp8266-base/esp8266-base.h and comment out the #include "RS485Server.h" line.