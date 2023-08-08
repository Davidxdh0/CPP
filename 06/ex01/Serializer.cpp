#include "Serializer.hpp"

Serializer::Serializer(){std::cout << "Contructed Serializer"<< std::endl;}

Serializer::Serializer( const Serializer& other) {
	std::cout << "Copy constructor called Serializer" << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other){
	std::cout << "Copy assignment called Serializer" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

Data* Serializer::deserialize(uintptr_t raw){
	struct Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t seri = reinterpret_cast<uintptr_t>(ptr);
	return seri;
}