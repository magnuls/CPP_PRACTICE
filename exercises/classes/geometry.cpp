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
void PointArray::print_array() {
    for (int i = 0; i < length; ++i) {
        std::cout << "Pointer " << i << ": ";
        std::cout << ptr[i].getX() << ", " << ptr[i].getY() << '\n';
    }
}

class Polygon {
   protected:
    PointArray p_array;
    static int instace_count;

   public:
};
