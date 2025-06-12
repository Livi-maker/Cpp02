#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& old);
		Fixed& operator = (const Fixed& old);
		~Fixed(void);
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	fractional;
};

#endif