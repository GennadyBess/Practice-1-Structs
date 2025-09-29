#include <iostream>

// void init(float kx, float ky) {
//     x = kx;
//     y = ky;
// }

// void print() {
//     std::cout << x << " " << y;
// }

int main() {
    struct Point {
        float x, y;

    };

    struct Circle {
        float center_coords[2];
        float r;
    };

    struct Square {
        float coords[2];
        float length;
    };

    Point a;
    a.x = 1.22;
    a.y = 2.22;
    Circle b;
    b.center_coords[0] = 0;
    b.center_coords[1] = 0;
    b.r = 3;
    std::cout << Point_within_Circle(a, b);


}

bool Point_within_Circle(Point &point, Circle &circle) {
    if (pow(point.x - circle.center_coords[0]) + pow(point.y - circle.center_coords[1]) <= circle.r) return true;
    else return false;
}