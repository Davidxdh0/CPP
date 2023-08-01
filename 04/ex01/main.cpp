#include "Animal.hpp"
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
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << meta->getType() << " should be Animal type" << std::endl;
	// std::cout << j->getType() << " should be Dog type" << std::endl;
	// std::cout << i->getType() << " should be Cat type" << std::endl;
	// meta->makeSound();	
	// i->makeSound();
	// j->makeSound();

	// delete meta;
	// delete j;
	// delete i;
	// const WrongAnimal* Beta = new WrongAnimal();
	// const WrongAnimal* k = new WrongCat();
	// Beta->makeSound(); 
	// k->makeSound();
	// delete Beta;
	// delete k;

	Animal* animalArray[4];
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
	atexit(checkleaks);
	return 0;
}
