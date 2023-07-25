#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "_Debug.hpp"
#include <iostream>

class Dog; 
class Cat;

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal(const WrongAnimal& old);
		WrongAnimal& operator=(const WrongAnimal& old);
		WrongAnimal& operator=(const Dog& old);
		WrongAnimal& operator=(const Cat& old);
		std::string getType( void ) const ;
		void makeSound( void ) const ;
		~WrongAnimal( void );
};

#endif
