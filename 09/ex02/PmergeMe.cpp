#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _input(""), _vect(), _deque() {}

PmergeMe::PmergeMe(char argv[]) : _input(argv), _vect(), _deque(){}

PmergeMe::PmergeMe(const PmergeMe& other) : _input(other._input), _vect(other._vect), _deque(other._deque){}

PmergeMe& PmergeMe::PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other){
		_input = other._input;
		_vect = other._vect;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::checkInput(){
	bool digitbool = false;
	for (size_t i = 0; _input[i] != '\0'; i++){
		if (std::isdigit(_input[i]))
			digitbool = true;
		else if (_input[i] == ' ')
			continue;
		else
			throw std::runtime_error("Error: Positive integers only.");
	}
	if (digitbool == false)
		throw std::runtime_error("Error: No digits.");
}

void	PmergeMe::MakeContainers(){
	std::istringstream iss(_input);
	double number;
    while (iss >> number) {
		if (number < INT_MIN || number > INT_MAX)
			throw std::runtime_error("Error: Incorrect input, integers only.");
		int b = static_cast<int>(number);
        _vect.push_back(b);
		_deque.push_back(b);
    }
}

std::vector<int>	PmergeMe::getVect(){
	return _vect;
}

std::deque<int>		PmergeMe::getDeque(){
	return _deque;
}
