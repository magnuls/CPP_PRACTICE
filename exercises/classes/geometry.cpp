#include "geometry.h"

#include <iostream>
#include <stdexcept>

int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(const int new_x) { x = new_x; }
void Point::setY(const int new_y) { y = new_y; }

void PointArray::push_back(const Point& p) {
    int og_length{length};
    if (og_length == 0)
        PointArray::resize(2);
    else
        PointArray::resize(length * 2);
    ptr[og_length + 1] = p;
}

// Position is zero indexed
void PointArray::insert(const int position, const Point& p) {
    int og_length{length};
    if (position >= og_length) throw std::runtime_error("Posiition >= Length");
    if (position == og_length - 1) {
        push_back(p);
        return;
    }
    resize(og_length * 2);

    Point* temp = ptr[position];
    for (int i = position - 1; i < length; ++i) {
        ptr[i + 1] = ptr[i];
    }
}

void remove(const int pos);
int PointArray::getSize() const { return length; }
void clear();
// Point* get(const int position);
// const Point* get(const int position) const;
