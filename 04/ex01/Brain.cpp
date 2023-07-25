#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) {}

Brain::Brain(const Brain& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor brain" << std::endl{
			;
		}
	*this = old;
}

Brain &Brain::operator=(const Brain& old){
	_index = old._index;
	if (MESSAGE == 1)
		std::cout << "Copy assignment brain" << std::endl;
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

bool Brain::checkIdeas(std::string idea, unsigned int index){
	if (index < 100){
		_ideas[index] = idea;
	return true;
	}
	return false;;
}
void Brain::addIdea(std::string idea){
	_ideas[_index] = idea;
	_index++;
	_index %= 100;
}

std::string	Brain::getIdea(int index) const{
	if(index >= 0 && index < 100)
		return _ideas[index];
	return "";
}
void Brain::showBrain(void) const{
	for(int i = 1; i <= 100; i++)
		std::cout << "Idea " << i << ": " + _ideas[i -1] << std::endl;
}