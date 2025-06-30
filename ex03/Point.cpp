#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(0), y(0)
{}

Point::Point(const float x, const float y) : x(x), y(y)
{}

Point::~Point(void)
{}

Point::Point(const Point& old) : x(old.x), y(old.y)
{}

Point& Point::operator = (const Point&)
{
	return (*this);
}

float	Point::getX(void) const
{
	return (x.toFloat());
}

float	Point::getY(void) const
{
	return (y.toFloat());
}

bool	Point::isSame(Point const b) const
{
	if (this->getX() == b.getX() && this->getY() == b.getY())
		return (true);
	return (false);
 }


