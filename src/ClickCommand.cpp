#include "Clicker.h"

ClickCommand::ClickCommand(uint8_t index, ClickCommandSettings* command) {
    this->_index = index;
    this->_command = command;
}

char* ClickCommand::getCommand() {
    return this->_command->command+5;
}

int8_t ClickCommand::getExecutionHour() {
    char buf[3];
    buf[0] = this->_command->command[0];
    buf[1] = this->_command->command[1];
    buf[0] = 0;
    return atoi(buf);
}

int8_t ClickCommand::getExecutionMinute() {
    char buf[3];
    buf[0] = this->_command->command[2];
    buf[1] = this->_command->command[3];
    buf[0] = 0;
    return atoi(buf);
}

void ClickCommand::get_config_page(char* buffer) {
    sprintf_P(
        buffer,
        CLICK_COMMAND,
        this->_index,
        this->_index,
        this->_command->command);
}

void ClickCommand::parse_config_params(WebServerBase* webServer) {
    char key[10];
    sprintf(key, "command%d", this->_index);
    webServer->process_setting(key, _command->command, sizeof(_command->command));
}

bool ClickCommand::shouldExec(uint8_t hour, uint8_t minute) {
    if (this->getExecutionHour() == hour &&
        this->getExecutionMinute() == minute &&
        millis() - this->lastExec > 60 * 60 * 1000) {
        this->lastExec = millis();
        return true;
    }
    
    return false;
}