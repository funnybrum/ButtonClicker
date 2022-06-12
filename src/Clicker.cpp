#include "Clicker.h"

Logger logger = Logger();
Settings settings = Settings();

WiFiManager wifi = WiFiManager(&logger, &settings.getSettings()->network);
SystemCheck systemCheck = SystemCheck(&logger);
WebServer webServer = WebServer(&logger, &settings.getSettings()->network);

ClickManager clickManager = ClickManager(
    new ClickExecutor[4] {
        ClickExecutor(D1),
        ClickExecutor(D2),
        ClickExecutor(D3),
        ClickExecutor(D4)
    },
    new ClickCommand[1] {
        ClickCommand(0, &settings.getSettings()->command1)
    },
    &settings.getSettings()->click);

void setup()
{ 
    Serial.begin(74880);
    while (! Serial) {
        delay(1);
    }
    settings.begin();
    wifi.begin();
    webServer.begin();
    systemCheck.begin();

    wifi.connect();
}

void loop() {
    wifi.loop();
    webServer.loop();
    settings.loop();
    systemCheck.loop();

    delay(100);
}
