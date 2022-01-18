#include "Rectangle.h"

float Rectangle::_default_size = 3.f;

Rectangle::Rectangle(float length, float width)
    : _length { length }
    , _width { width } {
}

Rectangle::Rectangle(float value)
    : Rectangle(value, value) {
}

Rectangle::Rectangle()
    : Rectangle(_default_size) {
}

void Rectangle::scale(float ratio) {
    _length *= ratio;
    _width *= ratio;
}

void Rectangle::set_default_size(float value) {
    _default_size = value;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle) {
    return out << "{ L: " << rectangle.get_length() << ", W: " << rectangle.get_width() << " }";
}
