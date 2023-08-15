#include "BitcoinExchange.hpp"

// void	leaks()
// {
// 	system("leaks -q btc");
// }

int main(int argc, char *argv[]){
	if (argc < 2 || argc > 2 ){
		std::cout << "Arguments are wrong." << std::endl;
		return 1;
	}
	// atexit(leaks);
	try {
		std::ifstream indata("data.csv");
		if (!indata.is_open())
			throw std::runtime_error("Can't open 'data.csv'");
		BitcoinExchange Codam(indata, argv[1]);
		Codam.Exchange();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	} catch (...){
		std::cerr << "Unknow error" << std::endl;
	}
	return 0;
}
