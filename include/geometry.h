#pragma once
#include <iostream>

class Point {
   private:
    int x;
    int y;

   public:
    Point(int k = 0, int l = 0) : x(k), y(l) {}
    int getX() const;
    int getY() const;
    void setX(int new_x);
    void setY(int new_y);
};

class PointArray {
   private:
    Point* ptr;
    int length;

   public:
    PointArray(const Point points[], const int size) {
        ptr = new Point[size];
        for (int i = 0; i < size; ++i) {
            ptr[i] = points[i];
        }
    }

    // Copy Constructor
    PointArray(const PointArray& pv) {
        length = pv.length;
        ptr = new Point[pv.length];
        for (int i = 0; i < pv.length; ++i) {
            Point copy(pv.ptr[i]);
            ptr[i] = copy;
        }
    }
    // Constructors
    ~PointArray() {
        delete[] ptr;
        std::cout << "Object Destroyed!" << '\n';
    }

    // Member functions
    void push_back(const Point& p);
    void insert(const int position, const Point& p);
    void remove(const int pos);
    int getSize() const;
    void clear();
    Point* get(const int position);
    const Point* get(const int position) const;

   private:
    void resize(int n) {
        Point* new_ptr = new Point[n];
        for (int i = 0; i < std::min(length, n); ++i) {
            new_ptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = new_ptr;
        length = n;
    }
};
