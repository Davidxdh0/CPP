#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "_Debug.hpp"
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
		static int _index;
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain & old);
		Brain& operator=(const Brain & old);
		bool 			checkIdeas(std::string idea, unsigned int index);
		void 			addIdea(std::string idea);
		std::string		getIdea(int index) const;
		void			showBrain(void) const;
};

#endif
