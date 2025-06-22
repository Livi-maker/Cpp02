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
		bool	operator < (const Fixed& toCompare) const;
		bool	operator > (const Fixed& toCompare) const;
		bool	operator >= (const Fixed& toCompare) const;
		bool	operator <= (const Fixed& toCompare) const;
		bool	operator == (const Fixed& toCompare) const;
		bool	operator != (const Fixed& toCompare) const;
		float	operator + (const Fixed& toCompare) const;
		float	operator - (const Fixed& toCompare) const;
		float	operator * (const Fixed& toCompare) const;
		float	operator / (const Fixed& toCompare) const;
		Fixed	operator ++(void);
		Fixed	operator ++(int);
		Fixed	operator --(void);
		Fixed	operator --(int);
		static Fixed&	min(Fixed& n1, Fixed& n2);
		static const Fixed&	min(const Fixed& n1, const Fixed& n2);
		static Fixed&	max(Fixed& n1, Fixed& n2);
		static const Fixed&	max(const Fixed& n1, const Fixed& n2);

	private:
		int					value;
		static const int	fractional = 8;
};

std::ostream& operator<< (std::ostream& os, const Fixed& old);

#endif