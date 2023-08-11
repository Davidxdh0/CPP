#include "Span.hpp"

Span::Span() : _N(0), _Vect(){
	// std::cout << "Default constructor Span" << std::endl;
}

Span::Span(unsigned int N) : _N(N), _Vect(){
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

void 	Span::addManyNumbers(int low, int high){
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
	int shortest = -1;
	for (unsigned i = 0; i < size_vect; i++){
		if (size_vect - 1 != i){
			int low = abs(_Vect[i] - _Vect[i + 1]);
			if (low < shortest || shortest == -1)
				shortest = low;
		}
	}
	if (shortest == -1)
		throw std::runtime_error("ShortestSpan cant be found");
	return shortest;
}

int 	Span::longestSpan(){
	unsigned int size_vect = _Vect.size();
	int longest = -1;
	for (unsigned i = 0; i < size_vect; i++){
		if (size_vect - 1 != i){
			int high = abs(_Vect[i] + _Vect[i + 1]);
			if (high > longest || longest == -1)
				longest = high;
		}
	}
	if (longest == -1)
		throw std::runtime_error("LongestSpan cant be found");
	return longest;
}

