#include "RPN.hpp"

void leaks(void){
	system("leaks -q RPN");
}

int main(int argc, char *argv[]){
	if (argc < 2 || argc > 2 ){
		std::cout << "Error: Arguments are wrong " << argv[0] << std::endl;
		return 1;
	}
	try {
		RPN calc(argv[1]);
		calc.checkStacks();
		calc.makeStacks();
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	} catch (...){
		std::cout << "unknown error" << std::endl;
	}
	return 0;
}