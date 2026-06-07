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
    void print_point() const;
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
        length = size;
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
    // Desructor
    ~PointArray() {
        delete[] ptr;
        // std::cout << "Object Destroyed!" << '\n';L:w
    }

    // Member functions
    void print_array() const;
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

class Polygon {
   protected:
    PointArray p_array;
    static int cnt;

   public:
    // Constructor
    Polygon(const Point array[], const int size) : p_array(array, size) {
        cnt++;
    }

    // Copy Constructor
    Polygon(const Polygon& object) : p_array(object.p_array) { cnt++; }

    // Destructor
    ~Polygon() { cnt--; }
    // Member Functions
    static int getNumPolygons() { return cnt; }

    const PointArray* getPoints() { return &p_array; }

    virtual double area() = 0;

    int getNumSides() { return p_array.getSize(); }
};

class Rectangle : public Polygon {
   public:
    // Constructor: lowerleft and upper right
    Rectangle(const Point& lower_l, const Point& upper_r);
    // Constructor: from 4 ints
    Rectangle(const int a, const int b, const int c, const int d);

    // Methods
    double area() override;
};

class Triangle : public Polygon {
   public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);

    // Methods
    double area() override;
};
