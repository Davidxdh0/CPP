#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

class Span {
	public:
		unsigned int 		_N;
		std::vector<int> 	_Vect;

		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(const int i);
		void 	addManyNumbers(int low, int high);
		int		shortestSpan();
		int 	longestSpan();
};

#endif
