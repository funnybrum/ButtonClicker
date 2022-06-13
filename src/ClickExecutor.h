#pragma once

#include "stdint.h"

class ClickExecutor {
    public:
        ClickExecutor(uint8_t pin);
        void click(uint16_t duration);
    private:
        uint8_t _pin;
};
