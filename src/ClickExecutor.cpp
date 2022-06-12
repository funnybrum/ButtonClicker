#include "Clicker.h"

ClickExecutor::ClickExecutor(uint8_t pin) {
    this->_pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void ClickExecutor::click(uint16_t duration) {
    digitalWrite(this->_pin, HIGH);
    delay(duration);
    digitalWrite(this->_pin, LOW);
}
