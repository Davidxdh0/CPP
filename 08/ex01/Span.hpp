#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

class Span {
	private:
		unsigned int 		_N;
		std::vector<int> 	_Vect;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void				addNumber(const int i);
		void 				addManyNumbers(const int low, const int high);
		int					shortestSpan();
		int 				longestSpan();
		std::vector<int>  	getVect();
};

#endif
