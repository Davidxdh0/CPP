#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// void checkleaks(void){
// 	system("leaks -q poly");
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " should be Dog type" << std::endl;
	std::cout << i->getType() << " should be Cat type" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	const WrongAnimal* Beta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	Beta->makeSound(); 
	k->makeSound();
	delete Beta;
	delete k;
	// atexit(checkleaks);
	return 1;
}
// To test whether your copies are deep copies, 
// you would need to create copies of objects that contain pointers to other objects and 
// then check if changes made to the data in the copied objects affect the original objects 
// or vice versa. If they do not, then your copies are considered deep copies. 
// If changes in one object affect the other, then you would need to adjust your copying mechanism
// to achieve a deep copy.
