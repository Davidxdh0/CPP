#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ){
	type = "Animal";
	std::cout << "Constructed " << type << std::endl;
}

Animal::Animal( std::string name ){
	type = name;
	std::cout << "Constructed " << type << std::endl;
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
	std::cout << "MakingSound called: ";
	if (getType() == "Dog")
		std::cout << "I am dog, I "<< "Bark " << std::endl;
	if (getType() == "Cat")
		std::cout << "I am cat, I "<< "Miaauw " << std::endl;
	if (getType() == "Animal")
		std::cout << "I am an Animal, I make Animal sounds" << std::endl;
}

Animal::~Animal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
