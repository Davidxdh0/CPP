#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_number = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	_number = number << _fractBits; 
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	this->_number = roundf(number * (1 << _fractBits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& child)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = child;
}

Fixed& Fixed::operator=(const Fixed& child)
{
	if (this != &child)
	{
		// std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed& fx) const
{
	return this->_number > fx._number;
}

bool Fixed::operator<(const Fixed& fx) const
{
	return this->_number < fx._number;
}

bool Fixed::operator>=(const Fixed& fx) const
{
	return this->_number >= fx._number;	
}

bool Fixed::operator<=(const Fixed& fx) const
{
	return this->_number <= fx._number;	
}

bool Fixed::operator==(const Fixed& fx) const
{
	return this->_number == fx._number;	
}

bool Fixed::operator!=(const Fixed& fx) const
{
	return this->_number != fx._number;	
}

Fixed Fixed::operator+(const Fixed& fx)
{
	Fixed result;
	
    result._number = this->_number + fx._number;
    return result;
}

Fixed Fixed::operator-(const Fixed& fx)
{
	Fixed result;

    result._number = this->_number - fx._number;
    return result;
}

//how to make it safely that the number doesnt go over int? no need?
Fixed Fixed::operator*(const Fixed& fx)
{
	Fixed result;

	result._number = this->_number * fx._number >> _fractBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& fx)
{
	Fixed result;
	
	result._number = (this->_number  << _fractBits) / fx._number;
	return result;
}

Fixed& Fixed::operator++ ()
{
	this->_number++;
	return *this;
}
	
Fixed Fixed::operator++ (int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator-- ()
{
	this->_number--;
	return *this;
}
Fixed Fixed::operator-- (int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return b;
	else
		return a;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)	
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}
