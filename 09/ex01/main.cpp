#include "RPN.hpp"

int main(int argc, char *argv[]){
	if (argc < 2 || argc > 2 ){
		std::cout << "Error: Arguments are wrong."  << std::endl;
		return 1;
	}
	try {
		RPN calc(argv[1]);
		calc.checkStacks();
		calc.makeStacks();
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}