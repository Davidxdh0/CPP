/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 00:49:16 by dyeboa        #+#    #+#                 */
/*   Updated: 2023/07/18 17:04:18 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
