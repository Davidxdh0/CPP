#include <Array.hpp>

int main(void) {
	std::cout << "****** Start ~10seconds runtime ******" << std::endl;
	try{
		std::cout << "------initialise negative 1-----" << std::endl;
		Array<int> intarray(-1);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-----copy constructor-almost the same----" << std::endl;
		Array<int> intarray(3);
		Array<int> intarraycopy = intarray;
		intarray[2] = 2;
		for (size_t i = 0; i < intarray.size(); i++) {
			std::cout << intarray[i];
		}
		std::cout << std::endl;
		for (size_t i = 0; i < intarraycopy.size(); i++) {
			std::cout << intarraycopy[i];
		}
		std::cout << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-----copy assignment--almost the same---" << std::endl;
		Array<int> intarray(5);
		Array<int> intarraycopy(3);
		intarray[2] = 2;
		intarraycopy = intarray;
		intarray[3] = 1;
		for (size_t i = 0; i < intarray.size(); i++) {
			std::cout << intarray[i];
		}
		std::cout << std::endl;
		for (size_t i = 0; i < intarraycopy.size(); i++) {
			std::cout << intarraycopy[i];
		}
		std::cout << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-----initialize 0 -----" << std::endl;
		Array<int> intarrays3(0);
		for (size_t i = 0; i < intarrays3.size(); i++) {
			std::cout << intarrays3[i];
		}
		std::cout << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-----initialize-0--set[0]=5-------" << std::endl;
		Array<int> intarrays3(0);
		intarrays3[0] = 5;
		for (size_t i = 0; i < intarrays3.size(); i++) {
			std::cout << intarrays3[i];
		}
		std::cout << std::endl;
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "-------Outside of [index]-------" << std::endl;
		Array<int> intarray(2);
		intarray[13] = 5;
		std::cout << "-------show rest of array-------" << std::endl;
		for(unsigned int i = 0; i < intarray.size(); i++){
			std::cout << intarray[i];
		}
		std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	try {
		std::cout << "-------Default is empty- set to 1-------" << std::endl;
		Array<int> intarraydefa;
		intarraydefa[0] = 1;
		for(unsigned int i = 0; i < intarraydefa.size(); i++){
			std::cout << intarraydefa[i];
	}
		std::cout << std::endl;	
	}catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
		std::cout << "-----changing characters--------" << std::endl;
		Array<char> chararray(15);
		for(unsigned int i = 0; i < chararray.size(); i++){
			chararray[i] = i + 'A';
			std::cout << chararray[i];
		}
		std::cout << std::endl;
	} catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	try {
		std::cout << "--------double array------" << std::endl;
		Array<double> doublearray(15);
		for(unsigned int i = 0; i < doublearray.size(); i++)
			std::cout << doublearray[i];
		std::cout << std::endl;
	} catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "******Exit******" << std::endl;
    return 0;
}
