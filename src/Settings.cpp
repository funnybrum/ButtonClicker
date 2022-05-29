#include "Settings.h"
#include "Clicker.h"

Settings::Settings()
    :SettingsBase(&logger) {
}

void Settings::initializeSettings() {
    strcpy(settingsData.network.hostname, HOSTNAME);
}

SettingsData* Settings::getSettings() {
    return &settingsData;
}

Empty* Settings::getRTCSettings() {
    return NULL;
}
