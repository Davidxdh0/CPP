#ifndef PME_HPP
#define PME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits.h>
#include <chrono>

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

		std::vector<std::pair<int, int>>	MergeVect(std::vector<std::pair<int, int>>& first, std::vector<std::pair<int, int>>& second);	
		std::vector<std::pair<int, int>>	SortVectBig(std::vector<std::pair<int, int>>& pairs);
		void								sortVect(std::vector<int> sortvect);
		
		std::deque<std::pair<int, int>>		MergeDeque(std::deque<std::pair<int, int>>& first, std::deque<std::pair<int, int>>& second);	
		std::deque<std::pair<int, int>>		SortDequeBig(std::deque<std::pair<int, int>>& pairs);
		void								sortDeque(const std::deque<int> sortdeque);

		template <typename T>
		void	showstackpair(const T& k);
		template <typename T>
		void	showstack(const T& k);

};

template <typename T>
void	PmergeMe::showstackpair(const T &k){
	for(auto& vect : k){
		std::cout << vect.first << " ";
	}
	std::cout << std::endl;
	for(auto& vect2 : k){
		std::cout << vect2.second << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::showstack(const T &k){
	for(auto& vect : k){
		std::cout << vect << " ";
	}
}

#endif
