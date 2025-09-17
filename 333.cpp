#include <iostream>

int main() {
    struct Point {
        float coords[2];

        void init(float x, float y) {
            coords[0] = x;
            coords[1] = y;
        }
        
        void print() {
            std::cout << coords[0] << " " << coords[1];
        }

    };
    Point a;
    a.init(1.23, 3.232);
    a.print();
}