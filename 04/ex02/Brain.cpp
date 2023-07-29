#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) {}

Brain::Brain(const Brain& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor brain" << std::endl;
	*this = old;
}

Brain &Brain::operator=(const Brain& old){
	_index = old._index;
	if (MESSAGE == 1)
		std::cout << "Copy assignment Brain" << std::endl;
	if (this != &old){
		for(int i = 0; i < 100; i++)
			_ideas[i] = old._ideas[i];
	}
	return *this;
}

Brain::~Brain( void ){
	if (MESSAGE == 1)
		std::cout << "Deconstructed brain" << std::endl;
}

void Brain::addIdea(unsigned int index, std::string idea){
	_ideas[index] = idea;
	if (MESSAGE == 1)
		std::cout << "Idea "<< idea << " added at index " << index << std::endl;
}

std::string	Brain::getIdea(int index) const{
	if (MESSAGE == 1)
		// std::cout << "Get idea from index " << index << _ideas[index]<< std::endl;
	if(index >= 0 && index < 100)
		return _ideas[index];
	return "";
}
