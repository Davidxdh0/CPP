#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "_Debug.hpp"
#include <iostream>

class Dog; 
class Cat;

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal( void );
		AAnimal( std::string name );
		AAnimal(const AAnimal& old);
		AAnimal& operator=(const AAnimal& old);
		std::string getType( void ) const ;
		virtual void makeSound( void ) const = 0;
		virtual ~AAnimal( void ) = 0;
};

#endif
