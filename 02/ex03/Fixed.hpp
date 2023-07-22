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
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &child);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
	
	Fixed& operator=(const Fixed &child);
	Fixed& operator++ ();
	Fixed operator++ (int);
	Fixed& operator-- ();
	Fixed operator-- (int);
	Fixed operator+ (const Fixed& fx);
	Fixed operator- (const Fixed& fx);
	Fixed operator* (const Fixed& fx);
	Fixed operator/ (const Fixed& fx);	
	
	bool operator>(const Fixed& fx) const;
    bool operator<(const Fixed& fx) const;
    bool operator>=(const Fixed& fx) const;
    bool operator<=(const Fixed& fx) const;
    bool operator==(const Fixed& fx) const;
    bool operator!=(const Fixed& fx) const;

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& c);
#endif
