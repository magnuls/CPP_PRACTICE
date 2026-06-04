#include <iostream>

#include "geometry.h"

int main() {
    Point* ptr;
    ptr = new Point[3];
    std::cout << ptr[0].getX();

    return 0;
}
