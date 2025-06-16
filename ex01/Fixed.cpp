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

std::ostream& operator<< (std::ostream& os, const Fixed& old)
{
	os << old.toFloat();
	return (os);
}

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