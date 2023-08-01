#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "_Debug.hpp"
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain & old);
		Brain& operator=(const Brain & old);
		void		addIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif
