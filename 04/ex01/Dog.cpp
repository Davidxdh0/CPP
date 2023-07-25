#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal("Dog") {
	brain = new Brain();
}
Dog::Dog(const Dog& old){
	brain = new Brain();
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
	delete brain;
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
