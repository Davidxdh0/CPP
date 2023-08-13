#include "ScalarConverter.hpp"

/*
Static constructors, will not be used.
Can't be touched, can't be stopped, can't be moved, can't be rocked.
*/
// ScalarConverter::ScalarConverter(){}
// ScalarConverter::ScalarConverter( const ScalarConverter& other) {	*this = other;}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
//     if (this != &other)
//         return *this;
//     return *this;
// }
// ScalarConverter::~ScalarConverter(){}

/*
	Finds the type
	converts the type
	prints the desired output
*/
void	ScalarConverter::converter(const std::string& input){
	if (TESTS == 2)
		std::cout << input << std::endl;
	findType(input);
    void (*conv[])(const std::string&) = 
	{
        &ScalarConverter::convertChar,
        &ScalarConverter::convertFloat,
        &ScalarConverter::convertInt,
        &ScalarConverter::convertDouble,
        &ScalarConverter::impossible 
	};
    (*conv[_type])(input);
	if (_type != 4){
		printChar(input);
		printInt();
		printFloat();
		printDouble();
	}
	if (TESTS == 2)
		std::cout << "-----------------------" << std::endl;
}		

void	ScalarConverter::printChar(const std::string& input){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Char: ";
	if (!input.empty() && _double >= 0 && !std::isnan(_float) && !std::isnan(_double) && !std::isprint(_char))
		std::cout << "Not displayable" << std::endl;
	else if (std::isprint(_char) && !std::isnan(_float) && !std::isnan(_double))
		std::cout << "'" <<_char << "'" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	std::cout.rdbuf(prevcoutbuf);
	_pc = buffer.str();
	std::cout << _pc;
}

void	ScalarConverter::printInt(){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Int: ";
	if (std::isnan(_float) || std::isnan(_double))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << _int << std::endl;
	std::cout.rdbuf(prevcoutbuf);
	_pi = buffer.str();
	std::cout << _pi;
}

void	ScalarConverter::printFloat(){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Float: ";
	if (std::isinf(_float) && std::isinf(-_float))
		std::cout << _float << "f" << std::endl;
	else if (std::fmod(_float, 1.0) == 0.0 && (std::to_string(_float).length() < 14 && _float >= 0))
		std::cout << _float << ".0f" << std::endl;
	else if (std::fmod(_float, 1.0) == 0.0 && (std::to_string(_float).length() < 15 && _float <= 0))
		std::cout << _float << ".0f" << std::endl;
	else
		std::cout << _float << "f" << std::endl;
	std::cout.rdbuf(prevcoutbuf);
	_pf = buffer.str();
	std::cout << _pf;
}

void	ScalarConverter::printDouble(){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Double: ";
	if (std::fmod(_double, 1.0) == 0.0 && std::to_string(_double).length() < 14 && _double >= 0)
		std::cout << _double << ".0" << std::endl;
	else if (std::fmod(_double, 1.0) == 0.0 && std::to_string(_double).length() < 15 && _double <= 0)
		std::cout << _double << ".0" << std::endl;
	else
		std::cout << _double << std::endl;
	std::cout.rdbuf(prevcoutbuf);
	_pd = buffer.str();
	std::cout << _pd;	
}

void	ScalarConverter::convertChar(const std::string& input){
	char i = input.front();
	if (TESTS == 1)
		std::cout << "Charconvert = " << i << std::endl;
	_char = static_cast<char>(i);
	_float = static_cast<float>(i);
	_double = static_cast<double>(i);
	_int = static_cast<int>(i);
}

void	ScalarConverter::convertInt(const std::string& input){
	int result = 0;
	result = stoi(input);
	if (TESTS == 1)
		std::cout << "convertint: " << result << std::endl;
	_int = result;
	_char = static_cast<char>(result);
	_float = static_cast<float>(result);
	_double = static_cast<double>(result);
}

void	ScalarConverter::convertDouble(const std::string& input){
	double result = 0;
	result = std::stod(input);
	if (TESTS == 1)
		std::cout << "convertDouble: " << result << std::endl;
	_double = result;
	_char 	= static_cast<char>(result);
	_float 	= static_cast<float>(result);
	_int 	= static_cast<int>(result);	
}

void	ScalarConverter::convertFloat(const std::string& input){
	float i = 0;
	i = std::stof(input);
	if (TESTS == 1)
		std::cout << "convertfloat: " << i << std::endl;
	_float = i;
	_char = static_cast<char>(i);
	_int = static_cast<int>(i);
	_double = static_cast<double>(i);
}

void	ScalarConverter::impossible(const std::string& input){
	if (TESTS == 1)
		std::cout << "Impossible input: '" << input << "'" << std::endl;
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
	if (TESTS == 2)
			std::cout << "-----------------------" << std::endl;
}
