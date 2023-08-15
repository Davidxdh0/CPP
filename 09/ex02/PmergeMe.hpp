#ifndef PME_HPP
#define PME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits.h>

class PmergeMe {
	private:
		std::string			_input;
		std::vector<int> 	_vect;
		std::deque<int>		_deque;
	public:
		PmergeMe();
		PmergeMe(char argv[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int>	getVect();
		std::deque<int>		getDeque();
		void				checkInput();
		void				MakeContainers();
		void				sortVect(std::vector<int>& sortvect);
		void				sortDeque(const std::deque<int>& sortdeque);
		template <typename T>
		void	showstack(const T k);

};

template <typename T>
void	PmergeMe::showstack(const T k){
	typename T::const_iterator begin = k.begin();
	typename T::const_iterator end = k.end();
	for (; begin < end; begin++){
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}

#endif
