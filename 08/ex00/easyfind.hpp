#ifndef Easy_HPP
#define Easy_HPP
#include <iostream>
#include <algorithm> // find
#include <deque>
#include <list>
#include <set>
#include <vector>

template <typename T> 
typename T::iterator easyfind(T& x, int i){
	if (x.empty())
		throw std::runtime_error("Error: Empty container will segmentation fault cause of x.end");
	return std::find(x.begin(), x.end(), i);
} 

template <typename T> 
typename T::const_iterator easyfind(const T& x, int i){
	if (x.empty())
		throw std::runtime_error("Error: Empty container will segmentation fault cause of x.end");
	return std::find(x.begin(), x.end(), i);
} 
#endif
