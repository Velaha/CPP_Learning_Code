#pragma once

#include "Person.h"

class Phone {
public:
    virtual ~Phone() {}

    virtual void ring() const = 0;

protected:
    const Person& _owner;

    Phone(const Person& owner)
        : _owner { owner } {}
};
