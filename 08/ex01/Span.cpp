#include "Span.hpp"

Span::Span(){std::cout << "Default constructor Span" << std::cout;}

//welke container optimaal? slapen
Span::Span(unsigned int N) : _N(N){
	std::cout << "Constructor Span" << std::cout;
}

Span::Span(const Span& other){
	;
}

Span::Span& operator=(const Span& other){
	;
}

Span::~Span(){
	std::cout << "Deconstructor Span" << std::cout;
}


void 	Span::addNumber(){
	
}

void 	Span::addManyNumbers(){
	
}

void 	Span::shortestSpan(){
	
}

void 	Span::longestSpan(){
	
}

