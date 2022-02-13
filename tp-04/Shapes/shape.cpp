#include "shape.hpp"

// évite les déclarations circulaire pour intersect(Circle c)
PointContainer Shape::intersect(const Circle& other) const {
    return Shape::intersect(other);
}