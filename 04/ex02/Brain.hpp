#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "_Debug.hpp"
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
		unsigned int _index;
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain & old);
		Brain& operator=(const Brain & old);
		void		addIdea(unsigned int index, std::string idea);
		std::string	getIdea(int index) const;
	
};

#endif
