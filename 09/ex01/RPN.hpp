#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

class RPN {
	private:
		std::string			_input;
		std::stack<int>		_integers;
		std::stack<char>	_operations;
	public:
		RPN();
		RPN(char argv[]);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void	checkStacks();
		void	makeStacks();
		void	operations();
		double	calculate(double first, double second, char operation);
		std::stack<int>		getInt();
		std::stack<char>	getOpr();
		template <typename T>
	    void 	showstack(T k);

};

template <typename T>
void	RPN::showstack(T k){
	size_t size = k.size();
	for (size_t i = 0; i < size; i++){
		std::cout << k.front() << " ";
		k.pop();
	}
	std::cout << std::endl;
}

#endif
