#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "_Debug.hpp"
#include <iostream>

class Dog; 
class Cat;

class Animal {
	protected:
		std::string type;
	public:
		Animal( void );
		Animal(const Animal& old);
		Animal& operator=(const Animal& old);
		Animal& operator=(const Dog& old);
		Animal& operator=(const Cat& old);
		std::string getType( void ) const ;
		void makeSound( void ) const ;
		~Animal( void );
};

#endif
