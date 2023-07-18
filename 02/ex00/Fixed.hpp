/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 00:49:16 by dyeboa        #+#    #+#                 */
/*   Updated: 2023/07/11 15:55:14 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
//Orthodox Canonical Form ?
// equals operator
// 
class Fixed
{
private:
	int _number;
	static const int _fractBits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	
	Fixed(const Fixed& child);
	Fixed& operator=(const Fixed& child);
	Fixed& operator<<(const Fixed& child);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
};

#endif
