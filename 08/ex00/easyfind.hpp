#ifndef Easy_HPP
#define Easy_HPP
#include <iostream>
#include <algorithm> // find
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

template <typename T> 
int easyfind(T x, int i){
	try {
		if (x.empty())
			throw std::runtime_error("Error: Empty container - return fail ");
		typename T::iterator position = x.begin();
		position = std::find(x.begin(), x.end(), i);
		if (position == x.end() || x.empty())
			throw std::runtime_error("Can't be found in container - return last value: ");
		else
			std::cout << "Found i: " << *position << " - return index: " << std::distance(x.begin(), position) << std::endl;
		return std::distance(x.begin(), position);
	} catch (const std::exception& e) {
        
		if (x.empty()){
			std::cerr << e.what() << "-1" << std::endl;
			return (-1);
		}
		std::cerr << e.what() << *(std::prev(x.end()))<< std::endl;
		return (*(std::prev(x.end())));
	}
}
#endif
