#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _number;
	static const int _fractBits = 8;
public:
	Fixed();
	~Fixed();
	
	Fixed(const Fixed& child);
	Fixed& operator=(const Fixed& child);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
