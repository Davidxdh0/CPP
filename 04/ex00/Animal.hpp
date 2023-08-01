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
		Animal( const std::string name );
		Animal(const Animal& old);
		Animal& operator=(const Animal& old);
		std::string getType( void ) const ;
		virtual void makeSound( void ) const;
		virtual ~Animal( void ) ;
};

#endif
