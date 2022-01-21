#include "SecondHand.cpp"

#include <iostream>

class Clock {
private:
    SecondHand _sec_hand { _min_hand };
    MinuteHand _min_hand;

public:
    void tick() { _sec_hand.advance(); }
    int  get_minutes() { return _min_hand.get_minutes(); }
    int  get_seconds() { return _sec_hand.get_seconds(); }

    friend std::ostream& operator<<(std::ostream& out, const Clock& clock);
};

std::ostream& operator<<(std::ostream& out, Clock& clock) {
    return out << clock.get_minutes() << " min " << clock.get_seconds() << " sec";
}