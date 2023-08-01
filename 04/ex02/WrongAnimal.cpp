#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){
	type = "WrongAnimal";
	if (MESSAGE == 1)
		std::cout << "Constructed " << type << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ){
	type = name;
	if (MESSAGE == 1)
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
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Animal sounds" << std::endl;
}

WrongAnimal::~WrongAnimal( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed WrongAnimal " << type << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
