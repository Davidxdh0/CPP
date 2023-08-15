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
	bool digitbool = 0;
	for (size_t i = 0; _input[i] != '\0'; i++){
		if (std::isdigit(_input[i]))
			digitbool = 1;
		else if (_input[i] == ' ')
			continue;
		else
			throw std::runtime_error("Error: Positive integers only.");
	}
	if (digitbool == 0)
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
template <typename T>
bool	PmergeMe::isSorted(T& k){
	for (size_t i = 0; i < k.size() - 2; i += 2){
		if (k[i] > k[i + 2])
			return (1);
	}
	return (0);
}

//Ford–Johnson algorithm 
void	PmergeMe::sortVect(std::vector<int>& sortvect){
	size_t sizevect = sortvect.size();
	//recursion till here
	if (sizevect <= 1)
        return ;
	std::vector<int> big;
	std::vector<int> small;
	// step 1
	int unpaired = 0;
	// step 2
	static bool makepairs = 1;
	
	for(size_t i = 0; i < sizevect - 1 && makepairs == 1;){
		big.push_back(std::max(sortvect[i], sortvect[i + 1]));
		big.push_back(std::min(sortvect[i], sortvect[i + 1]));
		i += 2;
	}
	if (sizevect % 2 != 0){
		unpaired = big.back();
		std::cout << "UNEVEN" << std::endl;
	}
	makepairs = 0;
	int i = 0;
	int p = 0;	
	std::cout << std::endl;
	showstack(big);
	std::cout << std::endl;
	while (isSorted(big)){
		for(auto it = big.begin(); it + 2!= big.end(); it += 2){
			if (*it > *(it + 2)) {
				std::swap(*it, *(it + 2));
				std::swap(*(it + 1), *(it + 3));
        	}
		}
		i++;
	}

	std::cout << p << std::endl;
	showstack(big);
	//step 3
	// sortVect(big);
	// _vect.clear();
	// _vect.reserve(sizevect);
	
	// // big wortd niet goed gesorteerd.
	// // size_t index = 0;
	// // for (size_t num = 0; num < big.size(); num++) {
    // //     if (index < big.size()) {
    // //         _vect.insert(_vect.begin(), big[index]);
    // //         index++;
    // //     }
    // // }
	// //step 4
	// _vect.insert(_vect.begin(), unpaired);
	// //step 5
	// for (size_t i = 0; i < small.size(); i++){
	// 	std::vector<int>::iterator pos = std::lower_bound(_vect.begin(), _vect.end(), small[i]);
	// 	_vect.insert(pos, small[i]);
	// }
}

void	PmergeMe::sortDeque(const std::deque<int>& sortdeque){
	size_t sizedeque = sortdeque.size();
	//recursion till here
	if (sizedeque <= 1)
        return ;
	std::deque<int> big;
	std::deque<int> small;
	// step 1
	int unpaired = 0;
	// step 2
	// std::cout << "1";
	for(size_t i = 0; i + 1 < sizedeque;){
		big.push_back(std::max(sortdeque[i], sortdeque[i + 1]));
		small.push_back(std::min(sortdeque[i], sortdeque[i + 1]));
		_deque[i] 		= std::min(sortdeque[i], sortdeque[i + 1]);
		_deque[i + 1] 	= std::max(sortdeque[i], sortdeque[i + 1]);
		i += 2;
	}
	if (sizedeque % 2 != 0)
		unpaired = sortdeque.back();
	//step 3
	sortDeque(big);
	_deque.clear();
	_deque.resize(sizedeque);
	_deque = big;
	//step 4
	_deque.insert(_deque.begin(), unpaired);
	//step 5
	for (size_t i = 0; i < small.size(); i++){
		std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), small[i]);
		_deque.insert(pos, small[i]);
	}
}

// void	PmergeMe::makeStacks(){
// 	bool digitinstack = 0;
// 	for (size_t i = 0; _input[i] != '\0'; i++){
// 		if (std::isdigit(_input[i])){
// 			_vect.push(_input[i] - 48);
// 			digitinstack = 1;
// 		}
// 		else if (_input[i] == '*' || _input[i] == '/' || _input[i] == '-' || _input[i] == '+'){
// 			_deque.push(_input[i]);
// 			_deque();
// 		}
// 	}
// 	if (!digitinstack || _deque.size() > 0 || _vect.size() > 1){
// 		throw std::runtime_error("Error: expression is wrong");
// 	}
// 	std::cout << _vect.top() << std::endl;
// }

// double	PmergeMe::calculate(double first, double second, char operation){
// 	double result = 0;
// 	if (operation == '*')
// 		result = second * first;
// 	else if (operation == '/'){
// 		if (first == 0){
// 			throw std::runtime_error("Error: can't divise by 0");
// 		}
// 		result = second / first;
// 	}
// 	else if (operation == '-')
// 		result = second - first;
// 	else if (operation == '+')
// 		result = second + first;
// 	return result;
// }

// void	PmergeMe::_deque(){
// 	if (_vect.size() > 1 && _deque.size() > 0){
// 		double first	= _vect.top();
// 		_vect.pop();
// 		double second	= _vect.top();
// 		char oper		= _deque.top();
// 		_deque.pop();
// 		_vect.top() = calculate(first, second, oper);
// 	}
// 	else
// 		throw std::runtime_error("Error: expression is wrong");
// }

std::vector<int>	PmergeMe::getVect(){
	return _vect;
}

std::deque<int>		PmergeMe::getDeque(){
	return _deque;
}
