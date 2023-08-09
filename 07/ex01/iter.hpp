#ifndef iter_HPP
#define iter_HPP
#include <iostream>

template <typename T> 
void iter(T *a, size_t b, void (*showarray)(T &)){
	for (size_t i = 0; i < b; i++){
		showarray(a[i]);
	}
};

template <typename T> 
void iter(const T *a, size_t b, void (*showarray)(const T &)){
	for (size_t i = 0; i < b; i++){
		showarray(a[i]);
	}
};

template <typename T> 
void showarray(T &k){
	std::cout << k << " ";
};

#endif
