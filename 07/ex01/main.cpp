#include "iter.hpp"

int main(void) {
	std::cout << "arraychar: ";
	const char *arraychar[] = {"one", "two", "three"};
	iter(arraychar, 3, showarray<const char *>);
	std::cout << std::endl;
	std::cout << "arraystr: ";
	std::string arrstr[] = {"String", "another", "Done"};
	iter(arrstr, 3, showarray<const std::string>);
	std::cout << std::endl;
	std::cout << "arrayint: ";
	int arrint[] = {1, 4, 5, 3, 1};
	iter(arrint, 5, showarray<int>);
	std::cout << std::endl;
	std::cout << "const arrayint: ";
	iter(arrint, 5, showarray<const int>);
	std::cout << std::endl;
	return 0;
}
