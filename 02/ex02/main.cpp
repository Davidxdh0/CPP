#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed 		f( Fixed( 5 ) / Fixed( 2 ) );
	Fixed const c(3.14f);
	Fixed 		d(2.5f);
    Fixed const e(5.05f);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << f << std::endl;
	std::cout << "c: " << c << std::endl;                         
    std::cout << "d: " << d << std::endl;            
    std::cout << "e: " << e << std::endl;      
	const Fixed& minVal = Fixed::min(e, c);          
    const Fixed& maxVal = Fixed::max(e, c);    
	const Fixed& maxOftwo = d.max(d, e);     
	const Fixed& maxOftwo2 = d.max(d, c);   

                  
    std::cout << "Min(e, c): " << minVal << std::endl;       
    std::cout << "Max(e, c): " << maxVal << std::endl;         
	std::cout << "max of cde: "<<Fixed::max( maxOftwo, maxOftwo2 ) << std::endl;

    return 0;
}
