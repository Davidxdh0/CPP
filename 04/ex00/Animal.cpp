#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ){
	type = "Animal";
}
Animal::Animal(const Animal& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	*this = old;
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
	if (getType() == "Cat")
		std::cout << "Bark " << std::endl;
	if (getType() == "Cat")
		std::cout << "Miaauw " << std::endl;
	if (getType() == "Animal")
		std::cout << "Animal sounds" << std::endl;
}

void Animal::makeSound() const {
	if (getType() == "Cat")
		std::cout << "Bark " << std::endl;
	if (getType() == "Cat")
		std::cout << "Miaauw " << std::endl;
	if (getType() == "Animal")
		std::cout << "Animal sounds" << std::endl;
}

Animal::~Animal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructor " << type << " called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
