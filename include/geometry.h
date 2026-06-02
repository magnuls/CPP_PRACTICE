#pragma once

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
