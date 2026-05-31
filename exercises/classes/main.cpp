#include <iostream>

class Point {
   private:
    int x, y;

   public:
    Point(int u, int v) : x{u}, y{v} {}
    void setX(int l);
};

void Point::setX(int newX) { x = newX; }

int main() { return 0; }
