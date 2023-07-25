#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "_Debug.hpp"

class Cat : public Animal {
	public:
		Cat( void );
		Cat(const Cat& old);
		Cat& operator=(const Cat& old);
		// void makeSound( void );
		~Cat( void );
};

#endif
