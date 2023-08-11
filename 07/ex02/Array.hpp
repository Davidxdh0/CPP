#ifndef Array_HPP
#define Array_HPP
#include <iostream>

template <typename T> class Array {
	private:
		T*				_data;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T*				getData();
		unsigned int	size() const;
		T& 				operator[](unsigned int index);
		const T& 		operator[](unsigned int index) const;

		class Err_Message : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array(void){
	this->_data = nullptr;
	this->_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n){
	if (n < 0)
		throw Err_Message();
	this->_data = new T[n];
	this->_size = n;
	for(unsigned int i = 0; i < n; i++)
		this->_data[i] = 0;
};

template <typename T>
Array<T>::Array(const Array& other) : _data(new T[other.size()]), _size(other.size()){
	for (unsigned int i = 0; i < other.size(); i++)
		this->_data[i] = other._data[i];
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
	if (_data == nullptr)
		throw Err_Message();
	if (this->_size - 1 < index)
		throw Err_Message();
	return (this->_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (_data == nullptr)
		throw Err_Message();
	if (this->_size - 1 < index)
		throw Err_Message();
	return (this->_data[index]);
}

template <typename T>
Array<T>::~Array(){
	// std::cout << "Deconstructed array" << std::endl;
}

template <typename T>
unsigned int	Array<T>::size() const{
	return this->_size;
}

template <typename T>
T*	Array<T>::getData(){
	return this->_data;
}

template <typename T>
const char * Array<T>::Err_Message::what() const throw(){
    return "Error exception: Check your values";
}
#endif