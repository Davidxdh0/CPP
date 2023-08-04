#include "ScalarConverter.hpp"
#include <sstream>
#include <stdexcept>
#include <limits.h>
#include <string.h>
#include <limits>

ScalarConverter::ScalarConverter(){
	std::cout << "Contructed ScalarConverter"<< std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other) {
	std::cout << "Copy constructor called ScalarConverter" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	std::cout << "Copy assignment called ScalarConverter" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "Decontructed ScalarConverter" << std::endl;
}

/*
Once a std::istringstream object has been created, 
then the string can be streamed and stored using the extraction operator(>>). 
The extraction operator will read until whitespace is reached or until the stream fails.
*/

void	ScalarConverter::converter(const std::string& input){
		
		convertint(input);
		convertdouble(input);
		convertfloat(input);
		std::cout << std::endl;
}		
void	ScalarConverter::convertint(const std::string& input)
{
	std::istringstream readinput(input);
	int result = 0;
	try {
		if (!(readinput >> result)) 
        	throw std::invalid_argument("impossible");
		std::cout << "Int: " << result << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Int: " << e.what() << std::endl;
    }
}

void	ScalarConverter::convertdouble(const std::string& input)
{
	std::istringstream readinput(input);
	double result = 0;
	try {
		if (!(readinput >> result))
        	throw std::invalid_argument("impossible");
		std::cout << "Double: " << result << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Double: " << e.what() << std::endl;
    }
}

void	ScalarConverter::convertfloat(const std::string& input)
{
	std::istringstream readinput(input);
	float result = 0;
	try {
		if (!(readinput >> result))
        	throw std::invalid_argument("impossible");
		// if (readinput == nan)
		std::cout << "float: " << result << ".0f" << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "float: " << e.what() << "f" << std::endl;
    }
}

/*
float f = std::numeric_limits<float>::infinity();
int a = std::numeric_limits<int>::infinity();
int b = std::numeric_limits<double>::infinity(); //negative infinity

std::string intStr7 = std::to_string(std::numeric_limits<int>::infinity());
std::string intStr8 = std::to_string(std::numeric_limits<int>::infinity() * -1);
*/