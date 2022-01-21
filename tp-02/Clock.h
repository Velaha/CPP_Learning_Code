#pragma once

#include "Event.h"
#include "SecondHand.h"

#include <iostream>
#include <vector>

class Clock {
private:
    SecondHand _sec_hand { _min_hand };
    MinuteHand _min_hand;
    // Question 8:
    // std::vector n'est pas le meilleur conteneur pour stocker les Event car il s'agit d'un morceau contigus
    // de mémoire, ce qui n'est pas très optimisé quand on manipule des objets complexes.
    std::vector<Event> _events;

public:
    void tick() {
        bool ret = false;
        for (std::size_t i = 0; i < _events.size(); i++) {
            ret = _events[i].notify_time(_min_hand.get_minutes(), _sec_hand.get_seconds());
            if (ret) {
                _events.erase(_events.begin() + i);
            }
        }
        _sec_hand.advance();
    }
    int  get_minutes() { return _min_hand.get_minutes(); }
    int  get_seconds() { return _sec_hand.get_seconds(); }
    void add_event(const Event& event) { _events.emplace_back(event); }
};

std::ostream& operator<<(std::ostream& out, Clock& clock) {
    return out << clock.get_minutes() << " min " << clock.get_seconds() << " sec";
}