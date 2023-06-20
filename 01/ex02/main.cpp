#include <iostream>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *PTR = &brain;
	std::string	&REF = brain;

	std::cout << &brain << std::endl;
	std::cout << &PTR << std::endl;
	std::cout << &REF << std::endl;

	std::cout << brain << std::endl;
	std::cout << *PTR << std::endl;
	std::cout << REF << std::endl;
}