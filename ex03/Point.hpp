#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		~Point(void);
		Point(const Point& old);
		Point& operator = (const Point&);
		float	getX(void) const;
		float	getY(void) const;

	private:
		Fixed const x;
		Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
float   vectorialProduct(Point const a, Point const b, Point const point);

#endif
