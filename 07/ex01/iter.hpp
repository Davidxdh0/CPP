#ifndef iter_HPP
#define iter_HPP
#include <iostream>

template <typename T, typename Func>
void iter(T *a, size_t b, Func test){
    for (size_t i = 0; i < b; i++) {
        test(a[i]);
    }
}

template <typename T> 
void showarray(T &k){
	std::cout << k << " ";
};

#endif
