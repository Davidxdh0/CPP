#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "_Debug.hpp"

class Dog : public Animal {
	public:
		Dog( void );
		Dog(const Dog& old);
		Dog& operator=(const Dog& old);
		void makeSound() const ;
		virtual ~Dog( void );
};

#endif
