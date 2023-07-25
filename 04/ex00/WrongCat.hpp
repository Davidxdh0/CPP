#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "_Debug.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat( void );
		WrongCat(const WrongCat& old);
		WrongCat& operator=(const WrongCat& old);
		~WrongCat( void );
};

#endif
