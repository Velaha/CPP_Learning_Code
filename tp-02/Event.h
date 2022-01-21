#pragma once

#include <iostream>
#include <string>
#include <utility>

// Contains the number of minutes first, and then the number of seconds.
using Time = std::pair<unsigned int, unsigned int>;

class Event {
public:
    Event(const Time& notif_time, const std::string& message)
        : _notif_time { notif_time }
        , _message { message } {}

    bool notify_time(int current_min, int current_sec) {
        if ((int)_notif_time.first == current_min && (int)_notif_time.second == current_sec) {
            std::cout << _message << std::endl;
            return true;
        }
        return false;
    }

private:
    Time        _notif_time;
    std::string _message;
};
