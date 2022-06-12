#pragma once

#include "stdint.h"
#include "WebServerBase.h"

const char CLICK_COMMAND[] PROGMEM = R"=====(
<fieldset style='display: inline-block; width: 300px'>
<legend>Click settings</legend>
Click duration:<br>
<input type="text" name="click_ms" value="%d"><br>
<small><em>in milliseconds, 1000 = 1 second click</em></small><br><br>
Pause duration:<br>
<input type="text" name="pause_ms" value="%d"><br>
<small><em>in milliseconds, 1000 = 1 second pause</em></small><br><br>
</fieldset>
)=====";

struct ClickCommandSettings {
    char command[32];
};

class ClickCommand {
    public:
        ClickCommand(uint8_t index, ClickCommandSettings* command);
        char* getCommand();
        void get_config_page(char* buffer); 
        void parse_config_params(WebServerBase* webServer);

    private:
        uint8_t _index;
        ClickCommandSettings* _command;
};
