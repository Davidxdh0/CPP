#include "Span.hpp"

Span::Span() : _N(0), _Vect(){
	// std::cout << "Default constructor Span" << std::endl;
}

Span::Span(const unsigned int N) : _N(N), _Vect(){
	// std::cout << "Constructor Span" << std::endl;
}

Span::Span(const Span& other){
	*this = other;
}

Span& Span::operator=(const Span& other){
	if (this != &other) {
		this->_N = other._N;
		this->_Vect = other._Vect;
	}
	return (*this);
}

Span::~Span(){
	// std::cout << "Deconstructor Span" << std::endl;
}

void 	Span::addNumber(const int i){
	if (_Vect.size() == _N)
		throw std::runtime_error("Error: Vector is full");
	this->_Vect.push_back(i);
}

void 	Span::addManyNumbers(const int low, const int high){
	std::random_device rd;
	std::mt19937 rng(rd()); 
	std::uniform_int_distribution<int> distribution(low, high);
	unsigned int size_vect = _Vect.size();
	if (size_vect == _N)
		throw std::runtime_error("Error: Vector is full");
	while (size_vect < _N){
		this->_Vect.push_back(distribution(rng));
		size_vect++;
	}
}

int	Span::shortestSpan(){
	unsigned int size_vect = this->_Vect.size();
	int Span = -1;
	for (unsigned i = 0; i < size_vect; i++){
		if (size_vect - 1 != i){
			int low = abs(_Vect[i] - _Vect[i + 1]);
			if (low < Span || Span == -1)
				Span = low;
		}
	}
	if (Span == -1)
		throw std::runtime_error("Span cant be found");
	return Span;
}

int 	Span::longestSpan(){
	unsigned int size_vect = _Vect.size();
	int span = -1;
	for (unsigned i = 0; i < size_vect; i++){
		if (size_vect - 1 != i){
			int high = abs(_Vect[i] + _Vect[i + 1]);
			if (high > span || span == -1)
				span = high;
		}
	}
	if (span == -1)
		throw std::runtime_error("Span cant be found");
	return span;
}

std::vector<int> 	Span::getVect(){
	return this->_Vect;
}