#ifndef Easy_HPP
#define Easy_HPP
#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

template <typename T> void easyfind(T x, int i){
	try {
		if (std::find(x.begin(), x.end(), i) != x.end())
			std::cout << "found" << std::endl;
		else
			throw std::runtime_error("Can't be found in container");
	}
	catch(std::exception& e){
		std::errc << e.what() << std::endl;
	}
	catch(...){
		std::cout << "std::runtime_error(Can't be found in container)" << std::endl;
	}
}
#endif
