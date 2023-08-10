#ifndef Easy_HPP
#define Easy_HPP
#include <iostream>
#include <algorithm> // find
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> 
int easyfind(T x, int i){
	try {
		if (x.empty())
			throw runtime_error("Error: Empty container - return fail ");
		typename T::iterator position = find(x.begin(), x.end(), i);
		if (position == x.end() || x.empty())
			throw runtime_error("Can't be found in container - return last value: ");
		cout << "Found i: " << *position << " - return index: " << distance(x.begin(), position) << endl;
		return distance(x.begin(), position);
	} catch (const exception& e) {
        
		if (x.empty()){
			cerr << e.what() << "-1" << endl;
			return (-1);
		}
		cerr << e.what() << *(prev(x.end()))<< endl;
		return (*(prev(x.end())));
	}
}
#endif
