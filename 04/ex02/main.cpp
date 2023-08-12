#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void checkleaks(void){
	system("leaks -q animalkingdom");
}

int main()
{
	// const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// std::cout << meta->getType() << " should be AAnimal type" << std::endl;
	std::cout << j->getType() << " should be Dog type" << std::endl;
	std::cout << i->getType() << " should be Cat type" << std::endl;
	// meta->makeSound();	
	i->makeSound();
	j->makeSound();

	// delete meta;
	delete j;
	delete i;
	const WrongAnimal* Beta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	Beta->makeSound(); 
	k->makeSound();
	delete Beta;
	delete k;

	AAnimal* animalArray[4];
	for (int i = 0; i < 2; i++) {
        animalArray[i] = new Dog();
    }
	for (int i = 2; i < 4; i++) {
        animalArray[i] = new Cat();
    }
	for (int i = 0; i < 4; i++) {
        animalArray[i]->makeSound();
    }

	Cat *cat = (Cat *)animalArray[3];
	Cat copyCat(*cat);

	copyCat.addIdea(0, "Ideetje");
	std::cout << "Cat:	" << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy:	" << copyCat.getBrain()->getIdea(0) << std::endl;

	for (int i = 0; i < 4; i++) {
        delete animalArray[i];
    }
	//atexit(checkleaks);
	return 0;
}
// To test whether your copies are deep copies, 
// you would need to create copies of objects that contain pointers to other objects and 
// then check if changes made to the data in the copied objects affect the original objects 
// or vice versa. If they do not, then your copies are considered deep copies. 
// If changes in one object affect the other, then you would need to adjust your copying mechanism
// to achieve a deep copy.
