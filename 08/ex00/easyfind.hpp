#ifndef Easy_HPP
#define Easy_HPP
#include <iostream>
#include <algorithm> // find
#include <deque>
#include <list>
#include <set>
#include <vector>

template <typename T> 
typename T::const_iterator easyfind(const T& x, int i){
	return std::find(x.begin(), x.end(), i);
} 
#endif
