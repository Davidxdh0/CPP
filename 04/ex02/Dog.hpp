#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "_Debug.hpp"

class Dog : public AAnimal {
	private:
		Brain* brain;
		
	public:
		Dog( void );
		Dog(const Dog& old);
		Dog& operator=(const Dog& old);
		void 	makeSound() const;
		void	addIdea(int index, std::string idea);
		Brain* 	getBrain(void);
		virtual ~Dog( void );
};

#endif
