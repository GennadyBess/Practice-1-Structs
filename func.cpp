#include "func.h"
#include <iostream>
#include <cmath>

void point_init(Point &a) {
    std::cin >> a.x;
    std::cin >> a.y;
}

void point_print(Point &a) {
    std::cout << "x:" << a.x << std::endl;
    std::cout << "y:" << a.y << std::endl;
}



void circle_init(Circle &a) {
    std::cin >> a.center_coords.x;
    std::cin >> a.center_coords.y;
    std::cin >> a.r;
}

float circle_area(Circle &a) {
    return M_PI * a.r * a.r;
}

float circle_length(Circle &a) {
    return 2 * M_PI * a.r;
}

void circle_print(Circle &a) {
    std::cout << "x:" << a.center_coords.x << std::endl;
    std::cout << "y:" << a.center_coords.y << std::endl;
    std::cout << "r:" << a.r << std::endl;
}



void square_init(Square &a) {
    std::cin >> a.top_left_coords.x;
    std::cin >> a.top_left_coords.y;
    std::cin >> a.side;
}

float square_area(Square &a) {
    return a.side * a.side;
}

float square_perimeter(Square &a) {
    return a.side * 4;
}

void square_print(Square &a) {
    std::cout << "x:" << a.top_left_coords.x << std::endl;
    std::cout << "y:" << a.top_left_coords.y << std::endl;
    std::cout << "side:" << a.side << std::endl;
}



bool point_within_circle(Point &p, Circle &c) {
    if (pow(p.x - c.center_coords.x, 2) + pow(p.y - c.center_coords.y, 2) < pow(c.r, 2)) return true;
    else return false;
}

bool point_within_square(Point &p, Square &s) {
    if ((s.top_left_coords.x < p.x && p.x < s.top_left_coords.x + s.side) && (s.top_left_coords.y < p.y && p.y < s.top_left_coords.y - s.side)) {
        return true;
    } else {
        return false;
    }
}



bool point_within_on_square(float x, float y, Square &s) {
    if ((s.top_left_coords.x <= x && x <= s.top_left_coords.x + s.side) && (s.top_left_coords.y >= y && y >= s.top_left_coords.y - s.side)) {
        return true;
    } else {
        return false;
    }
}

bool point_within_on_circle(float x, float y, Circle &c) {
    if (pow(x - c.center_coords.x, 2) + pow(y - c.center_coords.y, 2) <= pow(c.r, 2)) return true;
    else return false;
}



bool point_on_circle(Point &p, Circle &c) {
    if (pow(p.x - c.center_coords.x, 2) + pow(p.y - c.center_coords.y, 2) == pow(c.r, 2)) return true;
    else return false;
}

bool point_on_square(Point &p, Square &s) {
    if (((s.top_left_coords.x <= p.x && p.x <= s.top_left_coords.x + s.side) && (p.y == s.top_left_coords.y || p.y == s.top_left_coords.y - s.side)) || ((s.top_left_coords.y >= p.y && p.y >= s.top_left_coords.y - s.side) && (p.x == s.top_left_coords.x || p.x == s.top_left_coords.x + s.side))) {
        return true;
    } else {
        return false;
    }
}



bool overlap_circles(Circle &c1, Circle &c2) {
    if (pow(c1.center_coords.x - c2.center_coords.x, 2) + pow(c1.center_coords.y - c2.center_coords.y, 2) <= pow(c1.r + c2.r, 2)) return true;
    else return false;
}

bool overlap_squares(Square &s1, Square &s2) {
    if (point_within_on_square(s1.top_left_coords.x, s1.top_left_coords.y, s2)) return true;
    if (point_within_on_square(s1.top_left_coords.x + s1.side, s1.top_left_coords.y, s2)) return true;
    if (point_within_on_square(s1.top_left_coords.x, s1.top_left_coords.y - s1.side, s2)) return true;
    if (point_within_on_square(s1.top_left_coords.x + s1.side, s1.top_left_coords.y - s1.side, s2)) return true;

    if (point_within_on_square(s2.top_left_coords.x, s2.top_left_coords.y, s1)) return true;
    if (point_within_on_square(s2.top_left_coords.x + s2.side, s2.top_left_coords.y, s1)) return true;
    if (point_within_on_square(s2.top_left_coords.x, s2.top_left_coords.y - s2.side, s1)) return true;
    if (point_within_on_square(s2.top_left_coords.x + s2.side, s2.top_left_coords.y - s2.side, s1)) return true;
    return false;
}

bool overlap_circle_square(Circle &c1, Square &s2) {
    if (point_within_on_circle(s2.top_left_coords.x, s2.top_left_coords.y, c1)) return true;
    if (point_within_on_circle(s2.top_left_coords.x + s2.side, s2.top_left_coords.y, c1)) return true;
    if (point_within_on_circle(s2.top_left_coords.x, s2.top_left_coords.y - s2.side, c1)) return true;
    if (point_within_on_circle(s2.top_left_coords.x + s2.side, s2.top_left_coords.y - s2.side, c1)) return true;

    if (point_within_on_square(c1.center_coords.x, c1.center_coords.y, s2)) return true;
    return false;
}



bool circle_within_circle(Circle &c1, Circle &c2) {
    if (pow(pow(c1.center_coords.x - c2.center_coords.x, 2) + pow(c1.center_coords.y - c2.center_coords.y, 2), 0.5) + c1.r <= c2.r) return true;
    else return false;
}

bool square_within_square(Square &s1, Square &s2) {
    if (point_within_on_square(s1.top_left_coords.x, s1.top_left_coords.y, s2) == false) return false;
    if (point_within_on_square(s1.top_left_coords.x + s1.side, s1.top_left_coords.y, s2) == false) return false;
    if (point_within_on_square(s1.top_left_coords.x, s1.top_left_coords.y - s1.side, s2) == false) return false;
    if (point_within_on_square(s1.top_left_coords.x + s1.side, s1.top_left_coords.y - s1.side, s2) == false) return false;
    return true;
}

bool square_within_circle(Square &s1, Circle &c2) {
    if (point_within_on_circle(s1.top_left_coords.x, s1.top_left_coords.y, c2) == false) return false;
    if (point_within_on_circle(s1.top_left_coords.x + s1.side, s1.top_left_coords.y, c2) == false) return false;
    if (point_within_on_circle(s1.top_left_coords.x, s1.top_left_coords.y - s1.side, c2) == false) return false;
    if (point_within_on_circle(s1.top_left_coords.x + s1.side, s1.top_left_coords.y - s1.side, c2) == false) return false;
    return true;
}

bool circle_within_square(Circle &c1, Square &s2) {
    if (point_within_on_square(c1.center_coords.x, c1.center_coords.y, s2) == false) return false;
    if (point_within_on_square(c1.center_coords.x + c1.r, c1.center_coords.y, s2) == false) return false;
    if (point_within_on_square(c1.center_coords.x - c1.r, c1.center_coords.y, s2) == false) return false;
    if (point_within_on_square(c1.center_coords.x, c1.center_coords.y + c1.r, s2) == false) return false;
    if (point_within_on_square(c1.center_coords.x, c1.center_coords.y - c1.r, s2) == false) return false;
    return true;
}