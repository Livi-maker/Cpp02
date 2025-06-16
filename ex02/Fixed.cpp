#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : value(number << fractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fractional)))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (value >> fractional);
}

float	Fixed::toFloat(void) const
{
	return (float(value) / (1 << fractional));
}

Fixed::Fixed(const Fixed& old)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

Fixed& Fixed::operator = (const Fixed& old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = old.getRawBits();
	return (*this);
}

bool	Fixed::operator < (const Fixed& toCompare) const
{
	if (toCompare.toFloat() < this->toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator > (const Fixed& toCompare) const
{
	if (toCompare.toFloat() > this->toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator >= (const Fixed& toCompare) const
{
	if (toCompare.toFloat() >= this->toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed& toCompare) const
{
	if (toCompare.toFloat() <= this->toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator == (const Fixed& toCompare) const
{
	if (toCompare.toFloat() == this->toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator != (const Fixed& toCompare) const
{
	if (toCompare.toFloat() != this->toFloat())
		return (true);
	return (false);
}

float	Fixed::operator + (const Fixed& toAdd) const
{
	return (this->toFloat() + toAdd.toFloat());
}

float	Fixed::operator - (const Fixed& toAdd) const
{
	return (this->toFloat() - toAdd.toFloat());
}

float	Fixed::operator * (const Fixed& toAdd) const
{
	return (this->toFloat() * toAdd.toFloat());
}

float	Fixed::operator / (const Fixed& toAdd) const
{
	return (this->toFloat() / toAdd.toFloat());
}

// Fixed&	operator ++(const Fixed& toIncrement)
// {
// 	float a = toIncrement.toFloat();
// 	a += (1 >> fractional);
// 	return (Fixed(a));
// }

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream& operator<< (std::ostream& os, const Fixed& old)
{
	os << old.toFloat();
	return (os);
}