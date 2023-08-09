#ifndef Array_HPP
#define Array_HPP
#include <iostream>

template <typename T> class Array {
	private:
		T*				_data;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T*				getData();
		unsigned int	size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
};

template <typename T>
Array<T>::Array(){
	this->_data = NULL;
	this->_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n){
	this->_data = new T[n];
	this->_size = n;
	for(unsigned int i = 0; i < n; i++)
		this->_data[i] = 0;
};

template <typename T>
Array<T>::Array(const Array& other){
	this->_data = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		this->_data[i] = other[i];
};

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] this->_data;
		this->_data = new T[other.size()];
		this->_size = other.size();
		for (unsigned int i = 0; i < other.size(); i++){
			this->_data[i] = other[i];
		}
	}
	return *this;
};

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (this->_size - 1 < index)
		throw std::runtime_error("Index out of bounds");
	return (this->_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	try {
		if (this->_size - 1 < index)
			throw std::runtime_error("Index out of bounds");
		return (this->_data[index]);
	}
	catch(...){
		return NULL;
	}
}

template <typename T>
Array<T>::~Array(){
	std::cout << "Deconstructed array" << std::endl;
	delete[] this->_data;
}

template <typename T>
unsigned int	Array<T>::size() const{
	return this->_size;
}

template <typename T>
T*	Array<T>::getData(){
	return this->_data;
}

#endif