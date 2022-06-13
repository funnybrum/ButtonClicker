#include "Settings.h"
#include "Clicker.h"

Settings::Settings()
    :SettingsBase(&logger) {
}

void Settings::initializeSettings() {
    strcpy(settingsData.network.hostname, HOSTNAME);
    settingsData.click.click_ms = 250;
    settingsData.click.pause_ms = 500;
    settingsData.click.timeOffset_h = 3;
    strcpy(settingsData.command1.command, "0800:p");
    strcpy(settingsData.command2.command, "1200:p");
    strcpy(settingsData.command3.command, "1600:p");
    strcpy(settingsData.command4.command, "2200:p");
}

SettingsData* Settings::getSettings() {
    return &settingsData;
}

Empty* Settings::getRTCSettings() {
    return NULL;
}
