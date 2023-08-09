#include "Array.hpp"

int main(void) {
    std::cout << "-----copy constructor & assignment-----" << std::endl;
    Array<int> intarray(12);
	Array<int> intarrays1 = intarray;
	Array<int> intarrays2;
	Array<int> intarrays3(0);
	intarrays2 = intarray;
	intarray[0] = 5;
	for (size_t i = 0; i < intarray.size(); i++) {
        std::cout << intarray[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < intarrays1.size(); i++) {
        std::cout << intarrays1[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < intarrays2.size(); i++) {
        std::cout << intarrays2[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < intarrays3.size(); i++) {
        std::cout << intarrays3[i];
    }
    std::cout << std::endl;

	std::cout << intarray[0] << " != " << intarrays1[0] << intarrays2[0] << intarrays2[0] << std::endl;
	std::cout << "-------Outside of [index]-------" << std::endl;
	try {
		intarray[13] = 5;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "-------show rest of array-------" << std::endl;
    for(unsigned int i = 0; i < intarray.size(); i++){
		std::cout << intarray[i];
	}
    std::cout << std::endl;
    std::cout << "-------Default is empty-------" << std::endl;
    Array<int> intarraydefa;
    for(unsigned int i = 0; i < intarraydefa.size(); i++){
        std::cout << intarraydefa[i];
	}
	std::cout << std::endl;
    std::cout << "-----chaning characters--------" << std::endl;
    Array<char> chararray(15);
    for(unsigned int i = 0; i < chararray.size(); i++){
		chararray[i] = i + 'A';
        std::cout << chararray[i];
	}
    std::cout << std::endl;
	std::cout << "--------double array------" << std::endl;
    Array<double> doublearray(15);
    for(unsigned int i = 0; i < doublearray.size(); i++)
        std::cout << doublearray[i];
    std::cout << std::endl;
    return 0;
}
