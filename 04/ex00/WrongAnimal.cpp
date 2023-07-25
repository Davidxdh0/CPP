#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ){
	type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(const WrongAnimal& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	*this = old;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	if (getType() == "Dog")
		std::cout << "Miauwing " << getType() <<std::endl;
	if (getType() == "Cat")
		std::cout << "Barking " << getType() <<  std::endl;
	if (getType() == "WrongAnimal")
		std::cout << "sounds RightAnimal" << std::endl;
}

void WrongAnimal::makeSound() const {
	if (getType() == "Cat")
		std::cout << "Bark " << std::endl;
	if (getType() == "Cat")
		std::cout << "Miaauw " << std::endl;
	if (getType() == "WrongAnimal")
		std::cout << "WrongAnimal sounds" << std::endl;
}

WrongAnimal::~WrongAnimal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructor " << type << " called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
