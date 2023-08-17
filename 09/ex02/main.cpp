#include "PmergeMe.hpp"

// void	leaks(void)
// {
// 	system("leaks -q PmergeMe");
// }

int main(int argc, char *argv[]){
	// atexit(leaks);
	if (argc < 3 ){
		std::cout << "Error" << argv[0] <<std::endl;
		return 1;
	}
	try {
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

		PmergeMe big;
		big.checkInput(argc, argv);
		big.MakeContainers(argc, argv);
		big.sortDeque(big.getDeque());

		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Before: ";
		big.showInput(argc, argv);
		std::cout << "After Deque: ";
		big.showeval(big.getDeque());
		std::cout << "std::Deque with range " << argc - 1 << " took " << duration/10000 << " μs" << std::endl;
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	} catch (...){
		std::cout << "Error" << std::endl;
	}
	try {
		auto start1 = std::chrono::high_resolution_clock::now();

		PmergeMe fast;
		fast.checkInput(argc, argv);
		fast.MakeContainers(argc, argv);
		fast.sortVect(fast.getVect());
		auto end1 = std::chrono::high_resolution_clock::now();
		double duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
		std::cout << "std::Vector with range " << argc - 1 << " took " << duration1/10000 << " μs" << std::endl;
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	} catch (...){
		std::cout << "Error" << std::endl;
	}
	return 0;
}
