#include <math.h>

struct Point {
    float x, y;
};

struct Circle {
    Point center_coords;
    float r;

};

struct Square {
    Point top_left_coords;
    float side;
};