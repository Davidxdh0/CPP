#include "ScalarConverter.hpp"

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
	printChar(input);
	printInt();
	printFloat();
	printDouble();
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
	try {
		if (std::isnan(_float) || std::isnan(_double))
			throw std::runtime_error("Impossible");
		else
			std::cout << _int << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
	std::cout.rdbuf(prevcoutbuf);
	_pi = buffer.str();
	std::cout << _pi;
}

void	ScalarConverter::printFloat(){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Float: ";
	try {
		if (_float < std::numeric_limits<float>::lowest() && _float != -std::numeric_limits<float>::infinity())
			throw std::runtime_error("Impossible");
		if (_float > std::numeric_limits<float>::max() && _float != std::numeric_limits<float>::infinity())
			throw std::runtime_error("Impossible");
		if (std::isinf(_float) && std::isinf(-_float))
			std::cout << _float << "f" << std::endl;
		else if (std::fmod(_float, 1.0) == 0.0 && (std::to_string(_float).length() < 14 && _float >= 0))
			std::cout << _float << ".0f" << std::endl;
		else if (std::fmod(_float, 1.0) == 0.0 && (std::to_string(_float).length() < 15 && _float <= 0))
			std::cout << _float << ".0f" << std::endl;
		else
			std::cout << _float << "f" << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
	std::cout.rdbuf(prevcoutbuf);
	_pf = buffer.str();
	std::cout << _pf;
}

void	ScalarConverter::printDouble(){
	std::stringstream buffer;
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	std::cout << "Double: ";
	try {
		if (_double < std::numeric_limits<double>::lowest() && _double != -std::numeric_limits<double>::infinity())
			throw std::runtime_error("Impossible");
		if (_double > std::numeric_limits<double>::max() && _double != std::numeric_limits<double>::infinity())
			throw std::runtime_error("Impossible");
		else if (std::fmod(_double, 1.0) == 0.0 && std::to_string(_double).length() < 14 && _double >= 0)
			std::cout << _double << ".0" << std::endl;
		else if (std::fmod(_double, 1.0) == 0.0 && std::to_string(_double).length() < 15 && _double <= 0)
			std::cout << _double << ".0" << std::endl;
		else
			std::cout << _double << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
	std::cout.rdbuf(prevcoutbuf);
	_pd = buffer.str();
	std::cout << _pd;	
}

void	ScalarConverter::convertChar(const std::string& input){
	// std::cout << input << std::endl;
	char i = input.front();
	// std::cout << i << std::endl;
	double b = 0;
	try {
		if (isDouble(input) || isFloat(input)){
			b = stod(input);
			std::cout << b << std::endl;
			if (b >= 0 && b <= 255 )
				i = b;}
		}
		catch (std::out_of_range &range){
			;}
		catch (std::invalid_argument &range){
			;}
	if (TESTS == 1)
		std::cout << "Charconvert = " << i << std::endl <<"b = " << b << std::endl;
	// std::cout << i << std::endl;
	_char = static_cast<char>(i);
	_float = static_cast<float>(i);
	_double = static_cast<double>(i);
	_int = static_cast<int>(i);
}

void	ScalarConverter::convertInt(const std::string& input){
	int result = 0;
	try {
		result = stoi(input);
		if (TESTS == 1)
			std::cout << "convertint: " << result << std::endl;
		_int = result;
		_char = static_cast<char>(result);
		_float = static_cast<float>(result);
		_double = static_cast<double>(result);
	}
	catch (std::out_of_range &range){
		if (TESTS == 1)
			std::cout << "int: " << result << std::endl;
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		if (TESTS == 2)
			std::cout << "-----------------------" << std::endl;
		exit(1);
		}
	catch (std::invalid_argument &range){
		std::cout << "Char: Impossible" << std::endl;}
}

void	ScalarConverter::convertDouble(const std::string& input){
	double result = 0;
	try {
		result = std::stod(input);
		if (TESTS == 1)
			std::cout << "convertDouble: " << result << std::endl;
		_double = result;
		_char 	= static_cast<char>(result);
		_float 	= static_cast<float>(result);
		_int 	= static_cast<int>(result);	
	}
	catch (std::out_of_range &range){
		if (TESTS == 1)
			std::cout << "Double: " << result << std::endl;
	
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		if (TESTS == 2)
			std::cout << "-----------------------" << std::endl;
		exit(1);
		}
}

void	ScalarConverter::convertFloat(const std::string& input){
	float i = 0;
	try {
		i = std::stof(input);
		if (TESTS == 1)
			std::cout << "convertfloat: " << i << std::endl;
		_float = i;
		_char = static_cast<char>(i);
		_int = static_cast<int>(i);
		_double = static_cast<double>(i);
		}
	catch (std::out_of_range &range){
		if (TESTS == 1)
			std::cout << "convertfloat: " << i << std::endl;
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		if (TESTS == 2)
			std::cout << "-----------------------" << std::endl;
		exit(1);
	}
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
	exit(1);
}
