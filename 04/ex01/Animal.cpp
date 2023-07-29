#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ){
	type = "Animal";
	if (MESSAGE == 1)
		std::cout << "Constructed " << type << std::endl;
}

Animal::Animal( std::string name ){
	type = name;
	if (MESSAGE == 1)
		std::cout << "Constructed Animal " << type << std::endl;
}

Animal::Animal(const Animal& old): type(old.type) {
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
}

Animal &Animal::operator=(const Animal& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Virtual MakingSound called: ";
	std::cout << "I am " << type << ", I make Animal sounds" << std::endl;
}

Animal::~Animal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed Animal " << this->type << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
