#include <iostream>
#include <ostream>

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

void polygon_test() {
    Rectangle rect(Point(1, 1), Point(3, 3));

    print_header("Test lower_l upper_r Constructor");
    // Print the Points
    rect.getPoints()->print_array();
    // Print area
    print_header("Area");
    std::cout << "Rectangle area: " << rect.area() << '\n';
}

void triangle_test() {
    Triangle tri(Point(1, 1), Point(3, 1), Point(2, 7));
    std::cout << "Area: " << tri.area() << '\n';
}

void printAttributes(Polygon* polyptr) {
    std::cout << "Points: ";
    polyptr->getPoints()->print_array();
    std::cout << "Area: " << polyptr->area() << '\n';
    std::cout << std::endl;
}

int main() {
    // p_array_test();
    // polygon_test();
    // triangle_test();
    std::cout << "Give lower left x: ";
    int lower_lx{};
    std::cin >> lower_lx;
    std::cout << "Give lower left y: ";
    int lower_ly{};
    std::cin >> lower_ly;
    Point lower_l(lower_lx, lower_ly);

    std::cout << "Give upper right x: ";
    int upper_rx{};
    std::cin >> upper_rx;
    std::cout << "Give upper right y: ";
    int upper_ry{};
    std::cin >> upper_ry;
    Point upper_r(upper_rx, upper_ry);

    print_header("Rectangle");
    Rectangle rect(lower_l, upper_r);
    printAttributes(&rect);

    std::cout << "Give p1 x: ";
    int p1x{};
    std::cin >> p1x;
    std::cout << "Give p1 y: ";
    int p1y{};
    std::cin >> p1y;
    std::cout << std::endl;

    std::cout << "Give p2 x: ";
    int p2x{};
    std::cin >> p2x;
    std::cout << "Give p2 y: ";
    int p2y{};
    std::cin >> p2y;

    std::cout << "Give p3 x: ";
    int p3x{};
    std::cin >> p3x;
    std::cout << "Give p3 y: ";
    int p3y{};
    std::cin >> p3y;
    std::cout << std::endl;

    Point p1(p1x, p1y);
    Point p2(p2x, p2y);
    Point p3(p3x, p3y);

    Triangle tri(p1, p2, p3);
    print_header("Triangle Attributes");
    printAttributes(&tri);

    return 0;
}
