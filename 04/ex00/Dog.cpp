#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal("Dog") {
}
Dog::Dog(const Dog& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	*this = old;
}

Dog &Dog::operator=(const Dog& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

Dog::~Dog( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
