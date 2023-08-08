#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#ifndef TESTS
#define TESTS 0
#endif

#include <iostream>

struct Data{
	int id = 1;
	std::string field = "Test";
};

class Serializer {
	private:
		Serializer();
	public:	
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

		static uintptr_t 	serialize(Data* ptr);
		static 				Data* deserialize(uintptr_t raw);
};

#endif
