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
typename T::iterator easyfind(T& x, int i){
	if (x.empty())
		throw runtime_error("Error: Empty container will segmentation fault cause of x.end");
	typename T::iterator position = find(x.begin(), x.end(), i);
	if (position != x.end()){
		// cout << "Found i: " << *position << " - index: " << distance(x.begin(), position) << endl;
		return (position);
	}
	// cout << "Not found in container" << endl;
	return x.end();	
} 
#endif
