#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

class Span {
	private:
		unsigned int _N;
		//container[N]
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void 	addNumber();
		void 	addManyNumbers();
		void 	shortestSpan();
		void 	longestSpan();
};

#endif
