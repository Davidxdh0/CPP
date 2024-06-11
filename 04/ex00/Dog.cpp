#include "Dog.hpp"
#define MESSAGE 1

Dog::Dog( void ) : Animal("Dog") {}

Dog::Dog(const Dog& old): Animal(old) {
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

void Dog::makeSound() const {
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Barking sounds" << std::endl;
}

Dog::~Dog( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed Dog " << this->type << std::endl;
}
