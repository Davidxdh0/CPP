#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ){
	type = "AAnimal";
	if (MESSAGE == 1)
		std::cout << "Constructed " << type << std::endl;
}

AAnimal::AAnimal( std::string name ){
	type = name;
	if (MESSAGE == 1)
		std::cout << "Constructed AAnimal " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& old): type(old.type) {
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "Virtual MakingSound called: ";
	std::cout << "I am " << type << ", I make AAnimal sounds" << std::endl;
}

AAnimal::~AAnimal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed AAnimal " << this->type << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}
