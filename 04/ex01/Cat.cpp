#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ): Animal("Cat"){
	brain = new Brain();
}
Cat::Cat(const Cat& old){
	brain = new Brain();
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
	delete brain;
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
