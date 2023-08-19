#ifndef PME_HPP
#define PME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits.h>
#include <chrono>
#include <algorithm>

class PmergeMe {
	private:

		std::vector<int> 	_vect;
		std::deque<int>		_deque;
		std::vector<int> 	_eval;
	public:
		PmergeMe();
		PmergeMe(int argc);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int>&	getVect();
		std::deque<int>&	getDeque();
		std::vector<int>&	getEval();
		void				checkInput(int argc, char* input[], bool cont);
		void				MakeContainers(int argc, char *argv, bool cont, int i);

		std::vector<std::pair<int, int>>	MergeVect(std::vector<std::pair<int, int>>& first, std::vector<std::pair<int, int>>& second);	
		std::vector<std::pair<int, int>>	SortVectBig(std::vector<std::pair<int, int>>& pairs);
		void								sortVect(std::vector<int>& sortvect);
		
		std::deque<std::pair<int, int>>		MergeDeque(std::deque<std::pair<int, int>>& first, std::deque<std::pair<int, int>>& second);	
		std::deque<std::pair<int, int>>		SortDequeBig(std::deque<std::pair<int, int>>& pairs);
		void								sortDeque(std::deque<int>& sortdeque);

		void	showInput(int argc, char *array[]);
		template <typename T>
		void	showstackpair(const T& k);
		template <typename T>
		void	showstack(const T& k);
		template <typename T>
		bool	isSorted(T& k);
		template <typename T>
		void	showeval(const T &k);

};

template <typename T>
void	PmergeMe::showstackpair(const T &k){
	for(auto& vect : k){
		std::cout << "{" << vect.first << ", " << vect.second << "} ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::showstack(const T &k){
	for(auto& vect : k){
		std::cout << vect << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::showeval(const T &k){
	auto size = k.size();
	int i = 0;
	for(auto p = k.begin(); p != k.end(); p++, i++){
		if (i == 4 && size > 5)
			break;
		std::cout << *p << " ";
	}
	if (size > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

template <typename T>
bool	PmergeMe::isSorted(T &k){
	for (size_t i = 0; i < k.size() - 2; i+=2){
		if (k[i] > k[i + 2])
			return (0);
	}
	return (1);
}

#endif
