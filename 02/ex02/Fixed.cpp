#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	_number = number << _fractBits; 
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	this->_number = roundf(number * (1 << _fractBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& child)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = child;
}

Fixed& Fixed::operator=(const Fixed& child)
{
	if (this != &child)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_number = child.getRawBits();
	}
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

int Fixed::toInt( void ) const
{
	return int(_number >> _fractBits);
}
float Fixed::toFloat( void ) const
{
	return float(float(_number)) / (float)(1 << _fractBits);
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _number;
}
void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

bool Fixed::operator>(const Fixed& fx)
{
	;
}

bool Fixed::operator<(const Fixed& fx)
{
	;	
}

bool Fixed::operator>=(const Fixed& fx)
{
	;	
}

bool Fixed::operator<=(const Fixed& fx)
{
	;	
}

bool Fixed::operator==(const Fixed& fx)
{
	;	
}

bool Fixed::operator!=(const Fixed& fx)
{
	;	
}

Fixed Fixed::operator+(const Fixed& fx)
{}
Fixed Fixed::operator-(const Fixed& fx)
{}
Fixed Fixed::operator*(const Fixed& fx)
{}
Fixed Fixed::operator/(const Fixed& fx)
{}
Fixed Fixed::operator++ ()
{}
Fixed Fixed::operator++(int)
{}
Fixed Fixed::operator-- ()
{}
Fixed Fixed::operator--(int)
{}

A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.

• A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.

• A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.

• A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.
