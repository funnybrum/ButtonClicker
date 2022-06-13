#include "Clicker.h"

Logger logger = Logger();
Settings settings = Settings();

WiFiManager wifi = WiFiManager(&logger, &settings.getSettings()->network);
WebServer webServer = WebServer(&logger, &settings.getSettings()->network);
WiFiUDP ntpUDP;
NTPClient ntpClient = NTPClient(ntpUDP);
ClickCommand* clickCommands = new ClickCommand[4] {
    ClickCommand(1, &settings.getSettings()->command1),
    ClickCommand(2, &settings.getSettings()->command2),
    ClickCommand(3, &settings.getSettings()->command3),
    ClickCommand(4, &settings.getSettings()->command4)    
};

ClickManager clickManager = ClickManager(
    new ClickExecutor[4] {
        ClickExecutor(D1),
        ClickExecutor(D2),
        ClickExecutor(D3),
        ClickExecutor(D4)
    },
    clickCommands,
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

    wifi.connect();
    ntpClient.begin();
    clickManager.begin();
    // Set update interval to 4 hours
    ntpClient.setUpdateInterval(4 * 60 * 60 * 1000);
    // Set the current time offset
    ntpClient.setTimeOffset(settings.getSettings()->click.timeOffset_h * 3600);
}

void loop() {
    wifi.loop();
    webServer.loop();
    settings.loop();
    ntpClient.update();
    clickManager.loop();

    delay(100);
}
