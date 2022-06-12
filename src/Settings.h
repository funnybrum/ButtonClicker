#pragma once

#include "SettingsBase.h"
#include "WiFi.h"
#include "ClickManager.h"

struct SettingsData {
    NetworkSettings network;
    ClickSettings click;
    ClickCommandSettings command1;
    ClickCommandSettings command2;
    ClickCommandSettings command3;
    ClickCommandSettings command4;
};

struct Empty {};

class Settings: public SettingsBase<SettingsData, Empty> {
    public:
        Settings();
        SettingsData* getSettings();

    protected:
        void initializeSettings();
        Empty* getRTCSettings();

    private:
        SettingsData settingsData;
};
