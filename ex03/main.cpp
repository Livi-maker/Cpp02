#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point const a(5, 0);
	Point const b(5, 0);
	Point const c (3, 7);
	Point const d (10, 0);
	Point const point(6, 2);
	bsp(a, b, c, point);
	bsp(b, c, point, a);
	bsp(a, c, d, point);
	bsp(a, c, d, Point(15, 20.59));
	return 0;
}
