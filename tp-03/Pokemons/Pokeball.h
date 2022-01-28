#pragma once

// A ball where Pokemon sleep.
class Pokeball {
public:
    bool empty() { return _empty; }

private:
    bool _empty = true;
};