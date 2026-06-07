#include "geometry.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(const int new_x) { x = new_x; }
void Point::setY(const int new_y) { y = new_y; }
void Point::print_point() const {
    std::cout << '(' << getX() << ", " << getY() << ')';
}

void PointArray::push_back(const Point& p) {
    int og_length{length};
    if (og_length == 0)
        PointArray::resize(1);
    else
        PointArray::resize(length + 1);
    ptr[og_length] = p;
}

// Position is zero indexed
void PointArray::insert(const int position, const Point& p) {
    int og_length{length};
    if (position >= og_length) throw std::runtime_error("Posiition >= Length");
    if (position == og_length - 1) {
        push_back(p);
        return;
    }
    resize(length + 1);

    for (int i = og_length - 1; i >= position; --i) {
        ptr[i + 1] = ptr[i];
    }
    ptr[position] = p;
}

void PointArray::remove(const int pos) {
    if (pos >= length || pos < 0) throw std::runtime_error("pos out of bounds");
    if (pos == length - 1) {
        resize(length - 1);
        return;
    }
    for (auto i = pos; i < length; i++) {
        ptr[i] = ptr[i + 1];
    }
    resize(length - 1);
}
int PointArray::getSize() const { return length; }

void PointArray::clear() {
    Point* new_ptr = new Point[0];
    delete[] ptr;
    ptr = new_ptr;
    length = 0;
}

Point* PointArray::get(const int position) {
    if (position >= length | position < 0) return nullptr;

    return &ptr[position];
}
const Point* PointArray::get(const int position) const {
    if (position >= length || position < 0)
        throw std::runtime_error("pos out of bounds");

    return &ptr[position];
}
void PointArray::print_array() const {
    std::cout << '[';
    for (int i{}; i < length - 1; ++i) {
        ptr[i].print_point();
        std::cout << ", ";
    }
    ptr[length - 1].print_point();
    std::cout << ']' << '\n';
}
// Creates a Point Array and returns a pointer
Point constructorPoints[4];

Point* updateConstructorPoints(const Point& p1, const Point& p2,
                               const Point& p3, const Point& p4 = Point(0, 0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

// Rectangle information
int Polygon::cnt{};

Rectangle::Rectangle(const Point& lower_l, const Point& upper_r)
    : Polygon(updateConstructorPoints(
                  lower_l, Point(upper_r.getX(), lower_l.getY()), upper_r,
                  Point(lower_l.getX(), upper_r.getY())),
              4) {}

Rectangle::Rectangle(const int a, const int b, const int c, const int d)
    : Polygon(updateConstructorPoints(a, b, c, d), 4) {}

double Rectangle::area() {
    Point p1{*p_array.get(0)};
    Point p2{*p_array.get(2)};

    int base(abs(p1.getX() - p2.getX()));
    int height(abs(p1.getY() - p2.getY()));

    return base * height;
}

// Triangle Inofrmation
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.getX() - p2.getX(), 2) +
                     std::pow(p1.getY() - p2.getY(), 2));
}

double Triangle::area() {
    Point p1{*p_array.get(0)};
    Point p2{*p_array.get(1)};
    Point p3{*p_array.get(2)};

    double side_1{distance(p1, p3)};
    double side_2{distance(p1, p2)};
    double side_3{distance(p2, p3)};

    double s{(side_1 + side_2 + side_3) / 2};

    return std::sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));
}
