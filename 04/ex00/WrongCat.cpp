#include "WrongCat.hpp"


WrongCat::WrongCat( void ): WrongAnimal("WrongCat"){
}
WrongCat::WrongCat(const WrongCat& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	*this = old;
}

WrongCat &WrongCat::operator=(const WrongCat& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Miauw sounds" << std::endl;
}

WrongCat::~WrongCat( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed WrongCat " << this->type << std::endl;
}
