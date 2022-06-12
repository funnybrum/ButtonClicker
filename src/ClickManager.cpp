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
        ClickCommand command = this->_commands[i];
        if (command.shouldExec(ntpClient.getHours(), ntpClient.getMinutes())) {
            char* steps = command.getCommand();
            while (*steps != 0) {
                const char s = *steps;
                uint8_t clicker_index;
                switch(s) {
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                        clicker_index = s - '0';
                        this->_clickers[clicker_index].click(this->_settings->click_ms);
                        delay(this->_settings->pause_ms);
                        break;
                    case 'p':
                        delay(this->_settings->click_ms);
                        delay(this->_settings->pause_ms);
                        break;
                }
            }
        }
    }
}

void ClickManager::get_config_page(char* buffer) {
    sprintf_P(
        buffer,
        CLICK_MANAGER,
        this->_settings->click_ms,
        this->_settings->pause_ms);
} 

void ClickManager::parse_config_params(WebServerBase* webServer) {
    webServer->process_setting("click_ms", this->_settings->click_ms);
    webServer->process_setting("pause_ms", this->_settings->pause_ms);
}
