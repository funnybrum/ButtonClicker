#pragma once

#include "stdint.h"
#include "ClickExecutor.h"
#include "ClickCommand.h"

const char CLICK_MANAGER[] PROGMEM = R"=====(
<fieldset style='display: inline-block; width: 300px'>
<legend>Click settings</legend>
Click duration:<br>
<input type="text" name="click_ms" value="%d"><br>
<small><em>in milliseconds, 1000 = 1 second click</em></small><br><br>
Pause duration:<br>
<input type="text" name="pause_ms" value="%d"><br>
<small><em>in milliseconds, 1000 = 1 second pause</em></small><br><br>
Time zone:<br>
GMT+<input type="text" name="timezone" value="%d"><br>
<small><em>in hours, for GMT+2 enter "2". Current time is %d:%02d</em></small><br><br>
</fieldset>
)=====";

struct ClickSettings {
    uint16_t click_ms;
    uint16_t pause_ms;
    int8_t timeOffset_h;
};


class ClickManager {
    public:
        ClickManager(ClickExecutor clickers[], ClickCommand[], ClickSettings* settings);
        void begin();
        void loop();
        void execute(uint8_t commandIndex);
        void get_config_page(char* buffer); 
        void parse_config_params(WebServerBase* webServer);

    protected:

    private:
        uint8_t pin;
        ClickExecutor* _clickers;
        ClickCommand* _commands;
        ClickSettings* _settings;
};
