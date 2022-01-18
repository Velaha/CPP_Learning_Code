#include "Rectangle.h"

#include <iostream>

int main() {
    Rectangle rect(2.f, 4.f);
    std::cout << rect << std::endl;

    rect.scale(3);
    std::cout << rect << std::endl;

    Rectangle square(2.5f);

    /* some instruction saying that next squares's size will be 3.f */
    Rectangle s1;
    Rectangle s2;

    /* some instruction saying that next squares's size will now be 5.f */
    Rectangle::set_default_size(5.f);

    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    // At this point, size of s1 and s2 should be 3.f, and size of s3, s4 and s5 should be 5.f.

    return 0;
}
