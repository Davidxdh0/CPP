#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
	if (argc < 2 || argc > 2 ){
		std::cout << "Not enough values for " << argv[0] << std::endl;
	}
	BitcoinExchange Codam(argc, argv);
	// std::cout << "input = " << Codam.getInput() << std::endl;
	// std::cout << "getmap size = " << Codam.getMap().size() << std::endl;
	// std::string date = "2009-01-08"; // 2009-01-08,1
	// std::string date1 = "2009-01-09";
	// std::string date2 = "2009-01-10"; // 2009-01-11,2
	// std::string date3 = "2-2-2"; // throw error

	// std::cout << "datetodec  = " << Codam.datetodecimal(date) << std::endl;
	// std::cout << "datetodec1 = " << Codam.datetodecimal(date1) << std::endl;
	// std::cout << "datetodec2 = " << Codam.datetodecimal(date2) << std::endl;
	// std::cout << "datetodec3 = " << Codam.datetodecimal(date3) << std::endl;
	
	// std::cout << "getDateValue  = " << Codam.getDataValue(date) << std::endl;
	// std::cout << "getDateValue1 = " << Codam.getDataValue(date1) << std::endl;
	// std::cout << "getDateValue2 = " << Codam.getDataValue(date2) << std::endl;
	// std::cout << "getDateValue3 = " << Codam.getDataValue(date3) << std::endl;

	// std::cout << "\nmain test\n" << std::endl;
	Codam.getListValue();
	



	return 0;
}