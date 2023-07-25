#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "_Debug.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog( void );
		Dog(const Dog& old);
		Dog& operator=(const Dog& old);
		~Dog( void );
};

#endif
