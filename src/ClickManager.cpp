#include "Clicker.h"

ClickManager::ClickManager(ClickExecutor clickers[], ClickCommand commands[], ClickSettings* settings) {
    this->_clickers = clickers;
    this->_commands = commands;
    this->_settings = settings;
}

void ClickManager::begin() {
}

void ClickManager::loop() {
    for (uint8_t i = 0; i < COMMANDS_COUNT; i++) {
        if (this->_commands[i].shouldExec(ntpClient.getHours(), ntpClient.getMinutes())) {
            logger.log("Time is %d:%02d", ntpClient.getHours(), ntpClient.getMinutes());
            this->execute(i);
        }
    }
}

void ClickManager::get_config_page(char* buffer) {
    for (uint8_t i = 0; i < COMMANDS_COUNT; i++) {
        logger.log("Command %d, executes at %d:%02d", i, _commands[i].getExecutionHour(), _commands[i].getExecutionMinute());
    }
    sprintf_P(
        buffer,
        CLICK_MANAGER,
        this->_settings->click_ms,
        this->_settings->pause_ms,
        this->_settings->timeOffset_h,
        ntpClient.getHours(),
        ntpClient.getMinutes());
} 

void ClickManager::parse_config_params(WebServerBase* webServer) {
    webServer->process_setting("click_ms", this->_settings->click_ms);
    webServer->process_setting("pause_ms", this->_settings->pause_ms);
    webServer->process_setting("timezone", this->_settings->timeOffset_h);
}

void ClickManager::execute(uint8_t commandIndex) {
    logger.log("Executing command %d", commandIndex+1);
    if (commandIndex >= COMMANDS_COUNT) {
        return;
    }
    char* steps = this->_commands[commandIndex].getCommand();
    while (*steps != 0) {
        const char s = *steps;
        uint8_t clicker_index;
        switch(s) {
            case '1':
            case '2':
            case '3':
            case '4':
                clicker_index = s - '0' - 1;
                this->_clickers[clicker_index].click(this->_settings->click_ms);
                delay(this->_settings->pause_ms);
                break;
            case 'p':
                delay(this->_settings->click_ms);
                delay(this->_settings->pause_ms);
                break;
        }
        steps++;
    }
}
