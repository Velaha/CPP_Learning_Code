#pragma once
#include "point.hpp"

#include <list>

class Shape;

using PointContainer = std::list<Point>;

// forward-declare the Line class in order to use it for intersection
class Line;

class Shape {
public:
    virtual PointContainer intersect(const Shape& other) const = 0;
    virtual PointContainer intersect(const Line& ln) const     = 0;
    virtual ~Shape() {}

    virtual std::ostream& print(std::ostream& os) const { return os << "some shape"; }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s) { return s.print(os); }
};
