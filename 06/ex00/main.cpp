#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2 && TESTS == 0 ){
		std::cout << "Not enough values for " << argv[0] << std::endl;
	}
	//	./tester.sh & normal
	if (argv[1])
		ScalarConverter::converter(argv[1]);
	if (TESTS == 3)
		ScalarConverter::mytester();
	return 0;
}
