#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& old);
		Fixed& operator = (const Fixed& old);
		~Fixed(void);
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;

	private:
		int					value;
		static const int	fractional = 8;
};

std::ostream& operator<< (std::ostream& os, const Fixed& old);

#endif