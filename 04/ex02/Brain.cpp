#include "Brain.hpp"

Brain::Brain( void ) {
	if (MESSAGE == 1)
		std::cout << "Constructed Brain" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = "Default";
}

Brain::Brain(const Brain& old){
	if (MESSAGE == 1)
		std::cout << "Copy constructor Brain" << std::endl;
	*this = old;
}

Brain &Brain::operator=(const Brain& old){
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
		std::cout << "Deconstructed Brain" << std::endl;
}

void Brain::addIdea(int index, std::string idea){
	if (index < 0){
		std::cout << "index < 0, idea not added" << std::endl;

	}
	if (index > 100){
		std::cout << "index > 100, idea not added" << std::endl;

	}
	if(index >= 0 && index < 100){
		std::cout << "Idea "<< idea << " added at index " << index << std::endl;
		_ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index) const{
	if(index >= 0 && index < 100)
		return _ideas[index];
	return "";
}
