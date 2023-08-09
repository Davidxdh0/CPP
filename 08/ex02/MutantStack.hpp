#ifndef Mutant_HPP
#define Mutant_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

//geenidee
class Mutant {
	private:
		unsigned int _N;
		//container[N]
	public:
		Mutant();
		Mutant(unsigned int N);
		Mutant(const Mutant& other);
		Mutant& operator=(const Mutant& other);
		~Mutant();

		void 	iterate();
		void 	deiterate();

};

#endif
