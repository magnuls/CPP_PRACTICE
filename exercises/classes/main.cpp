#include <iostream>

#include "geometry.h"

void print_point(const Point& point) {
    std::cout << point.getX() << ", " << point.getY() << '\n';
}

void print_header(const std::string message) {
    std::cout << std::string(25, '-') << " " << message << " "
              << std::string(25, '-') << '\n';
}

void p_array_test() {
    Point array[3];
    for (int i = 0; i < 3; ++i) {
        array[i] = Point(i, i);
    }
    PointArray p_array(array, 3);

    // Test push_back
    print_header("Test Push Back");
    p_array.push_back(Point(3, 3));
    p_array.print_array();

    // Test Insert
    print_header("Test Insert");
    p_array.insert(3, Point(15, 15));
    p_array.print_array();

    // Test Remove
    print_header("Test Remove");
    p_array.remove(0);
    p_array.remove(0);
    p_array.print_array();
    // Test Clear
    print_header("Test Clear");
    p_array.clear();
    p_array.print_array();
    std::cout << p_array.getSize() << '\n';
    // Test get
    print_header("Test Get");
    Point array_2[] = {Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray new_array(array_2, 4);
    Point* point{new_array.get(2)};
    print_point(*point);
    point->setX(0);
    point->setY(0);
    print_point(*point);
    new_array.print_array();
}

int main() {
    p_array_test();

    return 0;
}
