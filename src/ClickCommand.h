#pragma once

#include "stdint.h"
#include "WebServerBase.h"

const char CLICK_COMMAND[] PROGMEM = R"=====(
<fieldset style='display: inline-block; width: 300px'>
<legend>Click command %d</legend>
Command:<br>
<input type="text" name="command%d" value="%s">
</fieldset>
)=====";

struct ClickCommandSettings {
    char command[32];
};

class ClickCommand {
    public:
        ClickCommand(uint8_t index, ClickCommandSettings* command);
        char* getCommand();
        bool shouldExec(uint8_t hour, uint8_t minute);
        void get_config_page(char* buffer); 
        void parse_config_params(WebServerBase* webServer);

    private:
        int8_t getExecutionHour();
        int8_t getExecutionMinute();

        uint8_t _index;
        ClickCommandSettings* _command;
        uint32_t lastExec = 0;
};
