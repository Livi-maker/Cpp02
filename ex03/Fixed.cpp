#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(const int number) : value(number << fractional)
{
}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fractional)))
{
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
	*this = old;
}

Fixed& Fixed::operator = (const Fixed& old)
{
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

Fixed	Fixed::operator ++(void)
{
	this->value += 1;
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed	copy(*this);

	this->value += 1;
	return (copy);
}

Fixed	Fixed::operator --(void)
{
	this->value -= 1;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	copy(*this);

	this->value -= 1;
	return (copy);
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.value < n2.value)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.value < n2.value)
		return (n1);
	return (n2);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.value > n2.value)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.value > n2.value)
		return (n1);
	return (n2);
}

Fixed::~Fixed(void)
{
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
