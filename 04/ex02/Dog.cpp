#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : AAnimal("Dog") {
	brain = new Brain();
	std::cout << "Constructed " << type << " with brain" << std::endl;
}

Dog::Dog(const Dog& old): AAnimal(old) {
	brain = new Brain(*old.brain);
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
}

Dog &Dog::operator=(const Dog& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		AAnimal::operator=(old);
		this->type = old.type;
		delete brain;
		brain = new Brain(*old.brain);
	}
	return *this;
}
void Dog::makeSound() const {
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Barking sounds" << std::endl;
}

Dog::~Dog( void ){
	delete brain;
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}
