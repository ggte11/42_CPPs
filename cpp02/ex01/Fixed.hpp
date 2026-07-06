#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
private:
	int val;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int val);
	Fixed(const float val);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif