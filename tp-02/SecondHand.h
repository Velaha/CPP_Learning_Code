#pragma once

#include "MinuteHand.h"

class SecondHand {
private:
    int         _seconds = 0;
    MinuteHand& _min_hand;

public:
    int get_seconds() { return _seconds; }

    SecondHand(MinuteHand& minuteHand)
        : _min_hand(minuteHand) {}

    void advance() {
        _seconds += 1;
        if (_seconds == 60) {
            _seconds = 0;
            _min_hand.advance();
        }
    }
};