#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ): AAnimal("Cat"){
	brain = new Brain();
	std::cout << "Constructed " << type << " with brain" << std::endl;
}

Cat::Cat(const Cat& old): AAnimal(old) {
	brain = new Brain(*old.brain);
	if (MESSAGE == 1)
		std::cout << "Copy constructor " << type << " called" << std::endl;
}

//Shallow copy - Same Brain object
// Cat::Cat(const Cat& old): AAnimal(old), brain(old.brain){
// 	if (MESSAGE == 1)
// 		std::cout << "Copy constructor " << type << " called" << std::endl;
// }

Cat &Cat::operator=(const Cat& old){
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

//Shallow copy - Same Brain object
// Cat& Cat::operator=(const Cat& old) {
//     if (MESSAGE == 1)
//         std::cout << "Copy assignment " << type << " operator called" << std::endl;
//     if (this != &old) {
//         AAnimal::operator=(old);
//         this->type = old.type;
//         if (brain != old.brain) {
//             delete brain;
//         }
//         brain = old.brain;
//     }
//     return *this;
// }

void Cat::makeSound() const {
	std::cout << "MakingSound called: ";
	std::cout << "I am " << type << ", I make Miauw sounds" << std::endl;
}

Cat::~Cat( void ){
	delete brain;
	if (MESSAGE == 1)
		std::cout << "Deconstructed " << type << " called" << std::endl;
}

void	Cat::addIdea(unsigned int index, std::string idea){
	this->brain->addIdea(index, idea);
}

Brain* Cat::getBrain(void){
	return this->brain;
}
