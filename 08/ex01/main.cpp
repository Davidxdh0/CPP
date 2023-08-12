#include "Span.hpp"

int main()
{
	Span p(5);
	std::cout << "copy constr" << std::endl;
	Span sp = p;
	std::cout << "copy assign" << std::endl;
	Span cpyassig(5);
	cpyassig.addNumber(1);
	for (unsigned int i = 0; i < cpyassig.getVect().size(); i++){
		std::cout << cpyassig.getVect()[i];
	}
	std::cout << std::endl;
	std::cout << "after assign = empty" <<std::endl;
	cpyassig = sp;
	for (unsigned int i = 0; i < cpyassig.getVect().size(); i++){
		std::cout << cpyassig.getVect()[i];
	}
	std::cout << std::endl;
	std::cout << "addnumber" << std::endl;
	sp.addNumber(6);
	sp.addNumber(12);
	sp.addNumber(10);
	sp.addNumber(-9);
	sp.addNumber(-10);
	try{
		std::cout << "add full vector" << std::endl;
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
	std::cout << "shortest span" << std::endl;
	std::cout << big.shortestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "longest span" << std::endl;
	std::cout << big.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "*****" << std::endl;
	return 0;
}