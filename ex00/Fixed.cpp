#include "Fixed.hpp"

static const int fractional = 8;

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
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
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}