#ifndef Mutant_HPP
#define Mutant_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack<T>& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator end();
		iterator begin();
};

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	// cout << "Default constructor MutantStack" << endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
	// cout << "Copy Constructor MutantStack" << endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other){
	std::stack<T>::operator=(other);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(){
	// cout << "Deconstructor MutantStack" << endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return (this->c.begin());
}

#endif
