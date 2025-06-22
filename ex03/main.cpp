#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point const a(5, 0);
	Point const b(5, 0);
	Point const c (3, 7);
	Point const point(6, 2);
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
