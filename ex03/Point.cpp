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

float	vectorialProduct(Point const a, Point const b, Point const point)
{
	const float	aX = a.getX();
	const float	bX = b.getX();
	const float	pX = point.getX();
	const float	aY = a.getY();
	const float	bY = b.getY();
	const float	pY = point.getY();

	return ((bX - aX) * (pY - aY) - (bY - aY) * (pX - aX));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	aAngle;
	float	bAngle;
	float	cAngle;

	aAngle = vectorialProduct(a, b, point);
	bAngle = vectorialProduct(b, c, point);
	cAngle = vectorialProduct(c, a, point);
	if (aAngle == 0 || bAngle == 0 || cAngle == 0)
	{
		std::cout << "point on an edge" << std::endl;
		return (false);
	}
	if ((aAngle > 0 && bAngle > 0 && cAngle > 0) || (aAngle < 0 && bAngle < 0 && cAngle < 0))
	{
		std::cout << "point inside the triangle" << std::endl;
		return (true);
	}
	std::cout << "point outside the triangle" << std::endl;
	return (false);
}

