#include "Span.hpp"

// void	leaks()
// {
// 	system("leaks -q span");
// }
int main(void) {
	// atexit(leaks);
	try{
		std::cout << "try vector[0]" << std::endl;
		Span sp(0);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span p(5);
	std::cout << "copy constr" << std::endl;
	Span cpyassig(6);
	cpyassig.addNumber(1);
	Span test = cpyassig;
	cpyassig.addNumber(2);
	for (unsigned int i = 0; i < cpyassig.getVect().size(); i++){
		std::cout << cpyassig.getVect()[i];
		std::cout << " == ";
		if (i < test.getVect().size())
			std::cout << test.getVect()[i] << std::endl;
		else
			std::cout << "test empty" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "copy assygn" <<std::endl;
	Span sp = cpyassig;
	sp.addNumber(6);
	sp.addNumber(12);
	sp.addNumber(10);
	sp.addNumber(-9);
	for (unsigned int i = 0; i < sp.getVect().size(); i++){
		std::cout << sp.getVect()[i];
		std::cout << " == ";
		if (i < cpyassig.getVect().size())
			std::cout << cpyassig.getVect()[i] << std::endl;
		else
			std::cout << "sp empty" << std::endl;
	}
	std::cout << std::endl;
	try{
		std::cout << "addnumber full vector" << std::endl;
		sp.addNumber(-5);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "shortest span" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "longest span" << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	Span wrong;
	try{
		std::cout << "wrong shortest span" << std::endl;
		std::cout << wrong.shortestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		std::cout << "wrong longest span" << std::endl;
		std::cout << wrong.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span defa;
	try{
		std::cout << "default add" << std::endl;
		defa.addNumber(-5);
		std::cout << defa.getVect()[0] << std::endl;
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span big(100000);
	try{
		std::cout << "addmanynumbers" << std::endl;
		big.addManyNumbers(-50000, 50000);
		std::cout << "size: " << big.getVect().size() << std::endl;
		// for (unsigned int i = 0; big.getVect()[i]; i++){
		// 	std::cout << big.getVect()[i];
		// }
		// std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "shortest span" << std::endl;
	std::cout << big.shortestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "longest span" << std::endl;
	std::cout << big.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "*****" << std::endl;
	Span TestOne(5);
	TestOne.addNumber(1);
	try {
		std::cout << "TestOne shortest span" << std::endl;
		std::cout << TestOne.shortestSpan() << std::endl;
		std::cout << std::endl;
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "TestOne longest span" << std::endl;
		std::cout << TestOne.longestSpan() << std::endl;
		std::cout << std::endl;
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "*****" << std::endl;

	return 0;
}
