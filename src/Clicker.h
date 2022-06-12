#pragma once

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266mDNS.h>

#include "user_interface.h"

#include "esp8266-base.h"
#include "ClickManager.h"
#include "NTPClient.h"

#define HTTP_PORT 80
#define HOSTNAME "clicker"
#define COMMANDS_COUNT 4
#define CLICKERS_COUNT 4

extern Logger logger;
extern Settings settings;
extern WiFiManager wifi;
extern NTPClient ntpClient;
extern ClickManager clickManager;
extern ClickCommand* clickCommands;