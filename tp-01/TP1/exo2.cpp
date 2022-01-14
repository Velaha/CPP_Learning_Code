#include <iostream>

int main(int argc, char const* argv[]) {
    short s0;
    // const short s1;

    const int i1 = 2;

    // bool b2 { false };
    bool b3 { i1 };
    // bool b4;

    unsigned       u5 { 0x10 };
    unsigned short us6 = -10;
    unsigned long  ul7 { b3 + u5 + us6 };
    std::cout << ul7 << std::endl;

    // char c8 { "a" };
    // char c9 = -10;
    //
    // double       d10 { i1 };
    // double&      d11 { d10 };
    // double&      d12;
    // const double d13 { .0f };
    //
    // int        i14 = i1;
    // int&       i15 = i1;
    // int&       i16 = b2;
    // const int& i17 { i14 };

    return 0;
}
