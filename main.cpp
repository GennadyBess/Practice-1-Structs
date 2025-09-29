#include "func.cpp"
#include <iostream>

int main() {
    Square s1;
    s1.top_left_coords.x = 1;
    s1.top_left_coords.y = 4;
    s1.side = 4;

    Circle c1;
    c1.center_coords.x = 0;
    c1.center_coords.y = 0;
    c1.r = 1;

    Circle c2;
    c2.center_coords.x = 0;
    c2.center_coords.y = 0;
    c2.r = 13;

    Square s2;
    s2.top_left_coords.x = -1;
    s2.top_left_coords.y = 1;
    s2.side = 2;


    // Point b;
    // b.x = 4.999999;
    // b.y = 0;

    std::cout << circle_within_square(c1, s2);
    // Circle a2;
    // a2.center_coords.x = 5;
    // a2.center_coords.y = 5;
    // a2.r = 1;
    // Point p;
    // p.x = 10;
    // p.y = 5;


}