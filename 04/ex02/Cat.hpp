#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "_Debug.hpp"

class Cat : public AAnimal {
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
