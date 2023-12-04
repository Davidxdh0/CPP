#include "RPN.hpp"

RPN::RPN() : _input("") {}

RPN::RPN(char argv[]) : _input(argv), _integers(), _operations(){}

RPN::RPN(const RPN& other) : _input(other._input), _integers(other._integers), _operations(other._operations){}

RPN& RPN::RPN::operator=(const RPN& other) {
	if (this != &other){
		_input = other._input;
		_integers = other._integers;
		_operations = other._operations;
	}
	return *this;
}

RPN::~RPN(){}

// void	RPN::checkStacks(){
// 	for (size_t i = 0; _input[i] != '\0'; i++){
// 		if (std::isdigit(_input[i]) || \
// 			(_input[i] == '*' || _input[i] == '/' || _input[i] == '-' || _input[i] == '+' \
// 			|| _input[i] == ' '))
// 			continue;
// 		else
// 			throw std::runtime_error("Error: expression is wrong");
// 	}
// }

void	RPN::checkStacks(){
	int integer = 0;
	for (size_t i = 0; _input[i] != '\0'; i++){
		if (std::isdigit(_input[i]) && integer == 0)
			integer++;
		else if (_input[i] == '*' || _input[i] == '/' || _input[i] == '-' || _input[i] == '+' || _input[i] == ' '){
			integer = 0;
		}
		else
			throw std::runtime_error("Error: expression is wrong");
	}
}

void	RPN::makeStacks(){
	bool digitinstack = 0;
	for (size_t i = 0; _input[i] != '\0'; i++){
		if (std::isdigit(_input[i])){
			_integers.push(_input[i] - 48);
			digitinstack = 1;
		}
		else if (_input[i] == '*' || _input[i] == '/' || _input[i] == '-' || _input[i] == '+'){
			_operations.push(_input[i]);
			operations();
		}
	}
	if (!digitinstack || _operations.size() > 0 || _integers.size() > 1){
		throw std::runtime_error("Error: expression is wrong");
	}
	std::cout << _integers.top() << std::endl;
}

double	RPN::calculate(double first, double second, char operation){
	double result = 0;
	if (operation == '*')
		result = second * first;
	else if (operation == '/'){
		if (first == 0)
			throw std::runtime_error("Error: can't divise by 0");
		result = second / first;
	}
	else if (operation == '-')
		result = second - first;
	else if (operation == '+')
		result = second + first;
	return result;
}

void	RPN::operations(){
	if (_integers.size() > 1 && _operations.size() > 0){
		double first	= _integers.top();
		_integers.pop();
		double second	= _integers.top();
		char operateChr = _operations.top();
		_operations.pop();
		_integers.top() = calculate(first, second, operateChr);
		// std::cout << second << " " << operateChr << " " << first << " = " << _integers.top() << std::endl;
	}
	else
		throw std::runtime_error("Error: expression is wrong");
}

std::stack<int>		RPN::getInt(){
	return _integers;
}

std::stack<char>	RPN::getOpr(){
	return _operations;
}
