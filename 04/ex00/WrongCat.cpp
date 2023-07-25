#include "WrongCat.hpp"
#include <iostream>

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

WrongCat::~WrongCat( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
