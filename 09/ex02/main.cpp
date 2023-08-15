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
		
		std::vector<int> bigVect = big.getVect();
		std::cout << std::endl;
		big.sortVect(bigVect);
		std::cout << std::endl;
		big.showstack(big.getVect());
		
		// big.sortDeque(big.getDeque());
		// big.showstack(big.getDeque());

	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	} catch (...){
		std::cout << "Unknown error" << std::endl;
	}
	return 0;
}
