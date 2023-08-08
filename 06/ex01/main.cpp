#include "Serializer.hpp"

int main(void) {
	Data crypt;
	crypt.id = 1;
	crypt.field = "test";
	std::cout << "id: " << crypt.id << ", field: " << crypt.field << std::endl;
	
	uintptr_t p = Serializer::serialize(&crypt);
	uintptr_t k = Serializer::serialize(NULL);
	
	std::cout << "id: " << crypt.id << ", field: " << crypt.field << std::endl;
	
	Data* unencrypt = Serializer::deserialize(p);
	Data* kunencrypt = Serializer::deserialize(k);
	
	std::cout << "Deserialised id: " << unencrypt->id << ", Deserialised field: " << unencrypt->field << std::endl;
	std::cout << "kunencrypt " << kunencrypt << std::endl;
	std::cout << "id: " << crypt.id << ", field: " << crypt.field << std::endl;

	return 1;
}