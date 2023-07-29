#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ): Animal("Cat"){}

Cat::Cat(const Cat& old): Animal(old) {
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	// *this = old;
}

Cat &Cat::operator=(const Cat& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		Animal::operator=(old);
		this->type = old.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Miauw sounds" << std::endl;
}

Cat::~Cat( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed Cat " << this->type << std::endl;
}
