#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#ifndef TESTS
#define TESTS 0
#endif

#include <iostream>

struct Data{
	int id;
	std::string field;;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	public:	
		~Serializer();

		static uintptr_t 	serialize(Data* ptr);
		static 				Data* deserialize(uintptr_t raw);
};

#endif
