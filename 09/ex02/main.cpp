#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
	if (argc < 2 || argc > 2 ){
		std::cout << "Error: Need positive integer sequence as argument " << argv[0] <<std::endl;
		return 1;
	}
	try {
		PmergeMe big(argv[1]);
		big.checkInput();
		big.MakeContainers();
		
		auto start = std::chrono::high_resolution_clock::now();
		big.sortDeque(big.getDeque());
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		
		auto start1 = std::chrono::high_resolution_clock::now();
		big.sortVect(big.getVect());
		auto end1 = std::chrono::high_resolution_clock::now();
		auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();
		
		std::cout << std::endl;
		std::cout << "Deque took  " << duration << " microseconds" << std::endl;
		std::cout << "Vector took " << duration1 << " microseconds" << std::endl;
		
		std::cout << std::endl;
		big.showstack(big.getDeque());
		std::cout << std::endl << std::endl;
		big.showstack(big.getVect());
		
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	} catch (...){
		std::cout << "Unknown error" << std::endl;
	}
	return 0;
}
