#include "Serializer.hpp"

int main(void) {
	Data crypt;
	crypt.id = 1;
	crypt.field = "test";
	
	std::cout << "id: " << crypt.id << ", field: " << crypt.field << std::endl;
	
	uintptr_t p = Serializer::serialize(&crypt);
	uintptr_t k = Serializer::serialize(NULL);
	std::cout << "p = " << p <<  std::endl;
	std::cout << "p = " << &p <<  std::endl;
	std::cout << "k = " << k <<  std::endl;
	std::cout << "k = " << &k <<  std::endl;
	
	Data* unencrypt = Serializer::deserialize(p);
	Data* kunencrypt = Serializer::deserialize(k);
	
	std::cout << "'new' id: " << unencrypt->id << ", field: " << unencrypt->field << std::endl;
	std::cout << "'old' id: " << crypt.id << ", field: " << crypt.field << std::endl;
	std::cout << "kunencrypt " << kunencrypt << std::endl;

	return 0;
}