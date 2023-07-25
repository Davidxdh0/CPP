#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ): Animal("Cat"){
}
Cat::Cat(const Cat& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
	*this = old;
}

Cat &Cat::operator=(const Cat& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		this->type = old.type;
	}
	return *this;
}

Cat::~Cat( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
