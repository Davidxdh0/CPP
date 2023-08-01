#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal("Dog") {
	brain = new Brain();
	std::cout << "Constructed " << type << std::endl;
}

Dog::Dog(const Dog& old): Animal(old) {
	brain = new Brain(*old.brain);
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << std::endl;
}

Dog &Dog::operator=(const Dog& old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment " << type << " operator called" << std::endl;
	if (this != &old){
		Animal::operator=(old);
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

void	Dog::addIdea(int index, std::string idea){
	this->brain->addIdea(index, idea);
}

Dog::~Dog( void ){
	delete brain;
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << std::endl;
}
