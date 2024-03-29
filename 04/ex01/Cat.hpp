#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "_Debug.hpp"

class Cat : public Animal {
	private:
		Brain* brain;
		
	public:
		Cat( void );
		Cat(const Cat& old);
		Cat& operator=(const Cat& old);
		void 	makeSound() const;
		void	addIdea(int index, std::string idea);
		Brain* 	getBrain(void);
		virtual ~Cat( void );
};


#endif
