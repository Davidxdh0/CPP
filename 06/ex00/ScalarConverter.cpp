#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter(){
	// std::cout << "Contructed ScalarConverter"<< std::endl;
//}

// ScalarConverter::ScalarConverter( const ScalarConverter& other) {
// 	std::cout << "Copy constructor called ScalarConverter" << std::endl;
// 	*this = other;
// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
// 	std::cout << "Copy assignment called ScalarConverter" << std::endl;
//     if (this == &other)
//         return *this;
//     return *this;
// }

// ScalarConverter::~ScalarConverter(){
// 	// std::cout << "Decontructed ScalarConverter" << std::endl;
// }

/*
Once a std::istringstream object has been created, 
then the string can be streamed and stored using the extraction operator(>>). 
The extraction operator will read until whitespace is reached or until the stream fails.
*/
// void int
// 	i = input to int
// 	float(i) to int
// 	double (i)to int
// 	char(i) to int
// void  float
// 	i = to int
// 	to int (i)
// void double
// 	i = to int
// 	to int (i)
// void char
// 	i = to int
// 	to int (i)


void	ScalarConverter::converter(const std::string& input){
	
	findType(input);
    const std::string array[] = {"char", "float", "int", "double", "Impossible"};
    void (*conv[])(const std::string&) = {
        &ScalarConverter::convertchar,
        &ScalarConverter::convertfloat,
        &ScalarConverter::convertint,
        &ScalarConverter::convertdouble,
        &ScalarConverter::Impossible
    };
    (*conv[_type])(input);
	printChar(input);
	printInt();
	printFloat();
	printDouble();
}		

void	ScalarConverter::printChar(const std::string& input){
	std::cout << "Char: ";
	// if (!input.compare("+inf") || !input.compare("+inff") || !input.compare("inff") || !input.compare("inf"))
	// 	std::cout << "∞" << std::endl;
	// else if (!input.compare("-inf") || !input.compare("-inff"))
	// 	std::cout << "-∞" << std::endl;
	if (input.empty() || _int < 0 || _int > 256)
		std::cout << "Impossible" << std::endl;
	else if (isprint(_char))
		std::cout << "'" <<_char << "'" << std::endl;
	else
		std::cout << "Not displayable" << std::endl;
}

void	ScalarConverter::printInt(){
	std::cout << "Int: ";
	try {
		if (_int < INT_MIN || std::isnan(_float) || std::isnan(_double))
			throw std::runtime_error("Impossible");
		if (_int > INT_MAX)
			throw std::runtime_error("Impossible");
		if (_int == INT_MIN && (_double > INT_MAX || _double < INT_MIN))
			std::cout << "Impossible" << std::endl;
		else
			std::cout << _int << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
}

void	ScalarConverter::printFloat(){
	std::cout << "Float: ";
	try {
		if (_float < std::numeric_limits<float>::lowest() && _float != -std::numeric_limits<float>::infinity())
			throw std::runtime_error("Impossible");
		if (_float > std::numeric_limits<float>::max() && _float != std::numeric_limits<float>::infinity())
			throw std::runtime_error("Impossible");
		if (std::isinf(_float) && std::isinf(_double))
			std::cout << _float << "f" << std::endl;
		else if (std::isinf(_float) && !std::isinf(_double))
			std::cout << "Impossible" << std::endl;
		else if (std::fmod(_float, 1.0) == 0.0)
			std::cout << _float << ".0f" << std::endl;
		else
			std::cout << _float << "f" << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
	
}

void	ScalarConverter::printDouble(){
	std::cout << "Double: ";
	try {
		if (_double < std::numeric_limits<double>::lowest() && _double != -std::numeric_limits<double>::infinity())
			throw std::runtime_error("Impossible");
		if (_double > std::numeric_limits<double>::max() && _double != std::numeric_limits<double>::infinity())
			throw std::runtime_error("Impossible");
		else if (std::fmod(_double, 1.0) == 0.0)
			std::cout << _double << ".0" << std::endl;
		else
			std::cout << _double << std::endl;
	}
	catch (std::runtime_error &err){
		std::cout << err.what() << std::endl;
	}
	catch (std::out_of_range &range){
		std::cout << "Impossible" << std::endl;}
}

void	ScalarConverter::convertchar(const std::string& input){
	char i = input.front();
	try {
		if (input.length() - _digits < 8 && input.length() > 1){
			int b = stoi(input);
			if (b > 0 && b < 256 )
				i = b;
		}
		}
		catch (std::out_of_range &range){
			;}
		catch (std::invalid_argument &range){
			;}
	if (TESTS == 1)
		std::cout << "char = " << i << std::endl;
	_char = static_cast<char>(i);
	_float = static_cast<char>(i);
	_double = static_cast<char>(i);
	_int = static_cast<char>(i);
}

void	ScalarConverter::convertint(const std::string& input){
	if (TESTS == 1)
		std::cout << "int" << std::endl;
	std::istringstream readinput(input);
	int result = 0;
	try {
		result = stoi(input);
		_int = result;
		_char = static_cast<int>(result);
		_float = static_cast<int>(result);
		_double = static_cast<int>(result);
	}
	catch (std::out_of_range &range){
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		exit(1);
		}
	catch (std::invalid_argument &range){
		std::cout << "Char: Impossible" << std::endl;}
}

void	ScalarConverter::convertdouble(const std::string& input){
	if (TESTS == 1)
		std::cout << "double" << std::endl;
	
	std::istringstream readinput(input);
	double result = 0;
	try {
		result = std::stod(input);
		_double = result;
		_char = static_cast<double>(result);
		_float = static_cast<double>(result);
		_int = static_cast<double>(result);	
	}
	catch (std::out_of_range &range){
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		exit(1);
		}
}

void	ScalarConverter::convertfloat(const std::string& input){
	if (TESTS == 1)
		std::cout << "float" << std::endl;
	std::istringstream readinput(input);

	float i = 0;
	try {
		i = std::stof(input);
		_float = i;
		_char = static_cast<float>(i);
		_int = static_cast<float>(i);
		_double = static_cast<float>(i);
		}
	catch (std::out_of_range &range){
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		exit(1);
	}
}

void	ScalarConverter::Impossible(const std::string& input){
	if (TESTS == 1)
		std::cout << "Impossible " << input << std::endl;
	char i = static_cast<char>(0);
	_char = static_cast<float>(i);
	_float = static_cast<float>(i);
	_double = static_cast<float>(i);
}

int ScalarConverter::_type = 0;
char ScalarConverter::_char = 'H';
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
int ScalarConverter::_digits = 0;

void	ScalarConverter::findType(const std::string& input)
{
	if (input.empty()){
		_type = e_impossible;
		return ;
	}
	if (!strcmp(input.c_str(), "inff") || !strcmp(input.c_str(), "nanf") || !strcmp(input.c_str(), "-inff") || !strcmp(input.c_str(), "+inff")){
		_type = e_float;
		return ;
	}
	else if (!strcmp(input.c_str(), "inf") || !strcmp(input.c_str(), "nan") || !strcmp(input.c_str(), "-inf") || !strcmp(input.c_str(), "+inf")){
		_type = e_double;
		return ;
	}
	else if (!input.empty() && (input[0] == '-' || input[0] == '+' || std::isdigit(input[0]) || input[0] == '.' )){
		int i = 0;
		int dotbool = 0;
		int fbool = 0;
		if (input[0] == '-' || input[0] == '+')
			i++;
		while (input[i] != '\0'){
			if ((input[i]) == 'f' && fbool != 1){
				_type = e_float;
				fbool = 1;
			}
			else if ((input[i]) == '.'){
				_type = e_double;
				dotbool++;
			}
			else if (input[i] < '0' || input[i] > '9'){
				_type = e_char;
				return ;
			}
			if ((input[i]) >= '0' && (input[i]) <= '9' && dotbool == 1)
				_digits++;
			if ((input[i]) >= '0' && (input[i]) <= '9' && fbool == 1){
				_type = e_char;
				return ;
			}
			i++;
		}
		if ((i == 1 && !isdigit(input[0])) || fbool > 1 || dotbool > 1){
			_type = e_char;
			return ;
		}
		if (_type == e_float && _digits > 7 && fbool == 0)
			_type = e_double;
	
		else if (_type != e_double && _type != e_float)
			_type = e_int;
		if (fbool > 1 || dotbool == 1){
			return ;
		}
		try {
			int i = stoi(input);
			if (i > 0 && i < 256 && !isdigit(i)){
				_type = e_char;
				return ;
				}
			}
		catch (std::out_of_range &range){
			;}//int
		catch (std::invalid_argument &inv){
			;//double
		}
		
	}
	else {
		for (int i = 0; input[i] != '\0'; i++)
			if (input[i] > 127 && input[i] < 32){
				_type = e_impossible;
				return ;
			}
		_type = e_char;
	}
}

int		ScalarConverter::getType(void ){
	return (_type);
}
