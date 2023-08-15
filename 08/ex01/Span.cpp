#include "Span.hpp"

Span::Span(const unsigned int N) : _N(N), _Vect(){
	// std::cout << "Constructor Span" << std::endl;
	if (_N == 0)
		throw std::runtime_error("Error: Vector[0]");
}

Span::Span(const Span& other) : _N(other._N), _Vect(other._Vect){
}

Span& Span::operator=(const Span& other){
	if (this != &other) {
		_N = other._N;
		_Vect = other._Vect;
	}
	return (*this);
}

Span::~Span(){
	// std::cout << "Deconstructor Span" << std::endl;
}

void 	Span::addNumber(const int i){
	if (_Vect.size() == _N)
		throw std::runtime_error("Error: Vector is full");
	_Vect.push_back(i);
}

void 	Span::addManyNumbers(const int low, const int high){
	std::random_device 					rd;
	std::mt19937 						rng(rd()); 
	std::uniform_int_distribution<int> 	distribution(low, high);

	unsigned int size_vect = _Vect.size();
	if (size_vect == _N)
		throw std::runtime_error("Error: Vector is full");
	while (size_vect < _N){
		_Vect.push_back(distribution(rng));
		size_vect++;
	}
}

int	Span::shortestSpan(){
if (_Vect.size() < 2)
		throw std::runtime_error("Span can't be found");
	std::vector<int> differences(_Vect.size());
	
	std::sort(_Vect.begin(), _Vect.end());
	std::adjacent_difference(_Vect.begin(), _Vect.end(), differences.begin());
	int span = *(std::min_element(differences.begin() + 1, differences.end()));
	return span;
}

int 	Span::longestSpan(){
	if (_Vect.size() < 2)
		throw std::runtime_error("Span can't be found");
	
	int low = *(std::min_element(_Vect.begin(), _Vect.end()));
	int max = *(std::max_element(_Vect.begin(), _Vect.end()));
	int span = abs(max - low);
	return span;
}

std::vector<int> 	Span::getVect(){
	return _Vect;
}
