#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ){
	type = "WrongAnimal";
	std::cout << "Constructed " << type << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ){
	type = name;
	std::cout << "Constructed " << type << std::endl;
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
	if (getType() == "WrongDog")
		std::cout << "Miauwing " << getType() <<std::endl;
	if (getType() == "WrongCat")
		std::cout << "I am Barking " << getType() <<  std::endl;
	if (getType() == "WrongAnimal")
		std::cout << "I am WrongAnimal, I make RightAnimal sounds" << std::endl;
}

WrongAnimal::~WrongAnimal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
