#include "Clicker.h"

char buffer[4096];

WebServer::WebServer(Logger* logger, NetworkSettings* networkSettings)
    :WebServerBase(networkSettings, logger) {
}

void WebServer::registerHandlers() {
    server->on("/", std::bind(&WebServer::handle_root, this));
    server->on("/settings", std::bind(&WebServer::handle_settings, this));
    server->on("/test", std::bind(&WebServer::handle_test, this));
}

void WebServer::handle_root() {
    server->sendHeader("Location","/settings");
    server->send(303);
}

void WebServer::handle_settings() {
    wifi.parse_config_params(this);
    clickManager.parse_config_params(this);
    clickCommands[0].parse_config_params(this);
    clickCommands[1].parse_config_params(this);
    clickCommands[2].parse_config_params(this);
    clickCommands[3].parse_config_params(this);

    char network_settings[strlen_P(NETWORK_CONFIG_PAGE) + 32];
    wifi.get_config_page(network_settings);

    char click_settings[strlen_P(CLICK_MANAGER) + 16];
    clickManager.get_config_page(click_settings);

    char command0[strlen_P(CLICK_COMMAND) + 48];
    clickCommands[0].get_config_page(command0);

    char command1[strlen_P(CLICK_COMMAND) + 48];
    clickCommands[1].get_config_page(command1);

    char command2[strlen_P(CLICK_COMMAND) + 48];
    clickCommands[2].get_config_page(command2);

    char command3[strlen_P(CLICK_COMMAND) + 48];
    clickCommands[3].get_config_page(command3);

    sprintf_P(
        buffer,
        CONFIG_PAGE,
        network_settings,
        click_settings,
        command0,
        command1,
        command2,
        command3);
    server->send(200, "text/html", buffer);

    ntpClient.setTimeOffset(settings.getSettings()->click.timeOffset_h * 3600);
}

void WebServer::handle_test() {
    int8_t command = -1;
    if (server->args() == 1 && server->argName(0).equals("cmd")) {
        command = atoi(server->arg(0).c_str());
        if (1 <= command && command <= COMMANDS_COUNT) {
            this->handle_root();
            clickManager.execute(command-1);
            return;
        }
    }
    
    server->send(400);
}