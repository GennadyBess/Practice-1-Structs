#include "struct.h"

void point_init(Point &a);
void point_print(Point &a);

void circle_init(Circle &a);
float circle_area(Circle &a);
float circle_length(Circle &a);
void circle_print(Circle &a);

void square_init(Square &a);
float square_area(Square &a);
float square_perimeter(Square &a);
void square_print(Square &a);

bool point_within_circle(Point &p, Circle &c);
bool point_within_square(Point &p, Square &s);
bool point_within_on_square(float x, float y, Square &s);

bool point_on_circle(Point &p, Circle &c);
bool point_on_square(Point &p, Square &s);

bool overlap_circles(Circle &c1, Circle &c2);
bool overlap_squares(Square &s1, Square &s2);
bool overlap_circle_square(Circle &c1, Square &s2);

bool circle_within_circle(Circle &c1, Circle &c2);
bool square_within_square(Square &s1, Square &s2);
bool square_within_circle(Square &s1, Circle &c2);


