#include <iostream>

#include "geometry.h"

int main() {
    Point p{3, 4};
    p.setX(7);
    std::cout << "(" << p.getX() << ", " << p.getY() << ")\n";

    Point* q = new Point();
    std::cout << q->getX() << q->getY() << '\n';
    delete q;

    return 0;
}
