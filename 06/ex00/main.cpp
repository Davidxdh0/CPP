/*
The following rule applies to the entire module and is not optional.
For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense

https://www.geeksforgeeks.org/static_cast-in-cpp/

1. loop over the string and check what type it is. Return 0-4 (4 = impossible for all)
2.Then do the conversion for the type found and return it. (static_cast)
3. Use the new return value to find the functions with that value.
4. Do the functions, minus the one already done.

*/
#include "ScalarConverter.hpp"
#include <limits.h>
#include <string.h>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cassert>
// you have to handle these pseudo literals as well 
// -inf, +inf and nan.
int main(int argc, char *argv[]) {
	if (argc < 2){
		std::cout << "Not enough values" << std::endl;
		return 1;
	}
	// std::istringstream readinput("13.5534344433434f");
	// float result = 1222222222222222;
	// float result = std::stof("13.5534344433434f");

	// std::cout << (result) << std::endl;
	//--------------------------
	//TESTS == 1
	ScalarConverter::converter(argv[1]);
	//--------------------------
	// test return value 
	//--------------------------    
	// ScalarConverter::findType(argv[1]);
	// std::string array[5] = {"char", "float", "int", "double", "not printable"};
	// std::cout << array[ScalarConverter::getType()] << std::endl;
	



	// try {
	// 	std::cout << "inf" << std::endl;
	// 	float negative_infinity1 = INFINITY;
	// 	std::cout << negative_infinity1 << std::endl;
	// 	float doubleinf = INFINITY;
	// 	std::cout << doubleinf << std::endl;

	// 	std::cout << "negativ" << std::endl;
	// 	float anegative_infinity1 = -INFINITY;
	// 	std::cout << anegative_infinity1 << std::endl;
	// 	float adoubleinf = -INFINITY;

	// 	std::cout << adoubleinf << std::endl;
	// 	std::cout << "Testing ints" << std::endl;
	// 	std::cout << "------------------" << std::endl;
	// 	std::string intStr1 = "0";
	// 	std::string intStr2 = "-5";
	// 	std::string intStr3 = "2147483647";
	// 	std::string intStr4 = "-2147483647";
	// 	std::string intStr5 = "21474836455";
	// 	std::string intStr6 = "-21474836499";
	// 	std::string intStr7 = std::to_string(std::numeric_limits<int>::infinity());
	// 	std::string intStr8 = std::to_string(std::numeric_limits<int>::infinity() * -1);
	// 	//double
	// 	std::string intStr9 = "-inf";
	// 	std::string intStr10 = "+inf";
	// 	std::string intStr11= "nan";
	// 	//float
	// 	std::string intStr12 = "inff";
	// 	std::string intStr13 = "+inff";
	// 	std::string intStr14 = "nanf";
	// 	A.ScalarConverter::converter(intStr1);
	// 	A.ScalarConverter::converter(intStr2);
	// 	A.ScalarConverter::converter(intStr3);
	// 	A.ScalarConverter::converter(intStr4);
	// 	A.ScalarConverter::converter(intStr5);
	// 	A.ScalarConverter::converter(intStr6);
	// 	A.ScalarConverter::converter(intStr7);
	// 	A.ScalarConverter::converter(intStr8);
	// 	std::cout << intStr7 << std::endl;
	// 	std::cout << intStr8 << std::endl;
	// 	// int inttest6 = A.ScalarConverter::converter(intStr6);
	// 	// std::cout << "inttest6 = " << inttest6 <<std::endl;
	// } 
	// catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

	// try {
	// 	std::cout << "Testing double" << std::endl;
	// 	std::cout << "------------------" << std::endl;
	// 	std::string doubleStr1 = std::to_string(0.1);
	// 	std::string doubleStr2 = std::to_string(-0.1);
	// 	std::string doubleStr3 = std::to_string(std::numeric_limits<double>::lowest());
	// 	std::string doubleStr4 = std::to_string(std::numeric_limits<double>::max());
	// 	std::string doubleStr5 = std::to_string(std::numeric_limits<double>::lowest() - 1);
	// 	std::string doubleStr6 = std::to_string(std::numeric_limits<double>::max() + 1);
	// 	double doubletest1 = A.ScalarConverter::convertdouble(doubleStr1);
	// 	std::cout << "doubletest1 = " << doubletest1 <<std::endl;
	// 	double doubletest2 = A.ScalarConverter::convertdouble(doubleStr2);
	// 	std::cout << "doubletest2 = " << doubletest2 <<std::endl;
	// 	// double doubletest3 = A.ScalarConverter::convertdouble(doubleStr3);
	// 	// std::cout << "doubletest3 = " << doubletest3 <<std::endl;
	// 	// double doubletest4 = A.ScalarConverter::convertdouble(doubleStr4);
	// 	// std::cout << "doubletest4 = " << doubletest4 <<std::endl;
	// 	// double doubletest5 = A.ScalarConverter::convertdouble(doubleStr5);
	// 	// std::cout << "doubletest5 = " << doubletest5 <<std::endl;
	// 	// double doubletest6 = A.ScalarConverter::convertdouble(doubleStr6);
	// 	// std::cout << "doubletest6 = " << doubletest6 <<std::endl;
	// } 
	// catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }
	return 1;
}
