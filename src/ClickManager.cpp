#include "Clicker.h"

ClickManager::ClickManager(ClickExecutor clickers[], ClickCommand commands[], ClickSettings* settings) {
    this->_clickers = clickers;
    this->_commands = commands;
    this->_settings = settings;
}

void ClickManager::begin() {

}

void ClickManager::loop() {
    
}

void ClickManager::get_config_page(char* buffer) {
    // TODO
} 

void ClickManager::parse_config_params(WebServerBase* webServer) {
    // TODO
}
