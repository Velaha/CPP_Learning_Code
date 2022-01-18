#pragma once

#include <ostream>

class Rectangle {
public:
    // Rectangle(float length, float width)
    //     : _length { length }
    //     , _width { width }
    // {}
    Rectangle(float length, float width);

    Rectangle(float value);

    Rectangle();

    float get_length() const { return _length; }
    float get_width() const { return _width; }

    // void scale(float ratio) {
    //     _length *= ratio;
    //     _width *= ratio;
    // }
    void scale(float ratio);

    static void set_default_size(float value);

private:
    static float _default_size;

    float _length;
    float _width;
};

std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle);
