#pragma once

#include "stdint.h"

class ClickExecutor {
    public:
        ClickExecutor(uint8_t pin);
        void click();

    private:
        uint8_t pin;
};
