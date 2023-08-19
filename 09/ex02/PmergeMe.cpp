#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :  _vect(), _deque(), _eval() {}

PmergeMe::PmergeMe(const PmergeMe& other) :  _vect(other._vect), _deque(other._deque), _eval(other._eval){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other){
		_vect = other._vect;
		_deque = other._deque;
		_eval = other._eval;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::checkInput(int argc, char* input[], bool cont){

	if (cont == 1){
		_vect.reserve(argc - 1);
	}
	int argvindex = 1;
	while(argvindex < argc){
		bool digitbool = false;
		for (size_t i = 0; input[argvindex][i] != '\0'; i++){
			if (std::isdigit(input[argvindex][i]))
				digitbool = true;
			else
				throw std::runtime_error("Error: Positive integers only.");
		}
		if (digitbool == false)
			throw std::runtime_error("Error: No digits.");
		MakeContainers(argc, input[argvindex], cont, argvindex);
		argvindex++;
	}
}

void	PmergeMe::MakeContainers(int argc, char *argv, bool cont, int i){
	
	double number = strtod(argv, nullptr);
	if (number < INT_MIN || number > INT_MAX)
		throw std::runtime_error("Error: Incorrect input, integers only.");
	if (cont == 1)
		_vect.emplace_back(static_cast<int>(number));
	else
		_deque.push_back(static_cast<int>(number));
	if (i < 7)
		_eval.emplace_back(static_cast<int>(number));
	argc++;
	// I don't mind duplicates, but if you do, uncomment.
	// if (cont == 1){
	// 	for (int number : _vect) {
	// 		if (std::count(_vect.begin(), _vect.end(), number) > 1)
	// 			throw std::runtime_error("Error: duplicate.");
	// 	}
	// }
	// else {
	// 	for (int number : _deque) {
	// 		if (std::count(_deque.begin(), _deque.end(), number) > 1)
	// 			throw std::runtime_error("Error: duplicate.");
	// 	}
	// }
}


void	PmergeMe::showInput(int argc, char *array[]){
	for (int i = 1; i < argc; i++){
		if (i == 5 && argc > 6)
			break;
		std::cout << array[i] << " ";
	}
	if (argc > 6)
		std::cout << "[...]";
	std::cout << std::endl;
}

std::vector<int>&	PmergeMe::getVect(){
    return this->_vect;
}

std::deque<int>&	PmergeMe::getDeque(){
    return this->_deque;
}



std::vector<int>&	PmergeMe::getEval(){
    return this->_eval;
}
