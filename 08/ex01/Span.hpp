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
		Span(unsigned int N=1);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void				addNumber(const int i);
		void 				addManyNumbers(const int low, const int high);
		int					shortestSpan();
		double 				longestSpan();
		std::vector<int>  	getVect();
		const int& 			operator[](unsigned int index) const;
		int& 				operator[](unsigned int index); 
};


#endif
