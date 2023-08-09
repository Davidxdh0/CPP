#include "ScalarConverter.hpp"

int 		ScalarConverter::_type   = 0;
char		ScalarConverter::_char 	 = '0';
int 		ScalarConverter::_int 	 = 0;
float 		ScalarConverter::_float  = 0;
double 		ScalarConverter::_double = 0;
std::string ScalarConverter::_pc 	 = "";
std::string ScalarConverter::_pi 	 = "";
std::string ScalarConverter::_pf 	 = "";
std::string ScalarConverter::_pd 	 = "";

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
/*
Creates a buffer, 
redirect the std::cout to buffer and saves it in prevcoutbuf
then i redirect the std::cout back to normal, 
then i save the buffer in _pf
print the _pf

std::stringstream buffer; 
std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
std::cout.rdbuf(prevcoutbuf);
_pf = buffer.str();
std::cout << _pf;	
*/

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
		if (_int < INT_MIN || _double < INT_MIN || std::isnan(_float) || std::isnan(_double))
			throw std::runtime_error("Impossible");
		if (_int > INT_MAX || _double > INT_MAX)
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
	std::cout.rdbuf(prevcoutbuf);
	_pd = buffer.str();
	std::cout << _pd;	
}

void	ScalarConverter::convertChar(const std::string& input){
	char i = input.front();
	double b = 0;
	try {
		if (isDouble(input) || isFloat(input)){
			b = stod(input);
			if (b >= 0 && b <= 255 )
				i = b;}
		}
		catch (std::out_of_range &range){
			;}
		catch (std::invalid_argument &range){
			;}
	if (TESTS == 1)
		std::cout << "Charconvert = " << i << std::endl <<"b = " << b << std::endl;
	_char = static_cast<char>(i);
	_float = static_cast<char>(i);
	_double = static_cast<char>(i);
	_int = static_cast<char>(i);
}

void	ScalarConverter::convertInt(const std::string& input){
	int result = 0;
	try {
		result = stoi(input);
		if (TESTS == 1)
			std::cout << "convertint: " << result << std::endl;
		_int = result;
		_char = static_cast<int>(result);
		_float = static_cast<int>(result);
		_double = static_cast<int>(result);
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
		_char = static_cast<double>(result);
		_float = static_cast<double>(result);
		_int = static_cast<double>(result);	
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
		_char = static_cast<float>(i);
		_int = static_cast<float>(i);
		_double = static_cast<float>(i);
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

bool	ScalarConverter::isInt(const std::string& input){
	int i = 0;
	try {
		if (input[0] == '+' || input[0] == '-' || std::isdigit(input[i])){
			if (input[0] == '+' || input[0] == '-')
				i++;
		}
		while (input[i] != '\0' && std::isdigit(input[i])){
			if (input[i] == '.')
				return false;
			i++;
		}
		double d = stod(input);
		if (input[i] == '\0' && (i > 1 || (input[0] != '+' && input[0] != '-')) && (d >= INT_MIN && d <= INT_MAX )){
			_type = e_int;
			return true;
		}
		return false;
	}
	catch (...){
		return false;
	}
}

bool	ScalarConverter::isChar(const std::string& input){
	int f = 0;
	int dot = 0;
	try {
			for (int i = 0; input[i] != '\0'; i++){
				if (input[i] == '.')
					dot++;
				else if (input[i] == 'f')
					f++;
				else if (std::isalpha(input[i]) && !isdigit(input[i])){
					return true;
				}
			}
			if (!isDouble(input) && !isFloat(input))
				return true;
			if (dot > 1|| f > 1)
				return true;
			return false;
	}
	catch (...){
		return false;
	}

}
bool ScalarConverter::onlyInt(const std::string& input) {
	int i = 0;
	if (input[0] == '+' || input[0] == '-' || std::isdigit(input[i])){
		if (input[0] == '+' || input[0] == '-')
			i++;
	}
	while (input[i] != '\0' && std::isdigit(input[i])){
		if (input[i] == '.')
			return false;
		i++;
	}
	if (input[i] != '\0')
		return true;
	else
		return false;
}

bool ScalarConverter::isFloat(const std::string& input) {
    try {
		size_t len = input.length();
        float fl = stof(input);
		int dot = -1;
		fl++;
		for (int i = 0; input[i] != '\0'; i++){
			if (input[i] == '.')
				dot = i;
		}
		if (input[len - 1] == 'f' && dot != -1)
			return true;
		double d = std::stod(input);
		if (d >= std::numeric_limits<float>::lowest() && d <= std::numeric_limits<float>::max() && onlyInt(input) && isDouble(input))
			return true;
	}
    catch (...) {
        return false;}
	return false;
}

bool	ScalarConverter::isDouble(const std::string& input){
    try{
        double d = stod(input);
		d++;
		int dot = 0;
		for (int i = 0; input[i] != '\0'; i++){
			if (input[0] == '-' || input[0] == '+')
				i++;
			if (!std::isdigit(input[i]) && input[i] != '.')
				return false;
			if (input[i] == '.')
				dot++;
		}
		if (dot > 1)
			return false;
		return true;
	}
    catch (const std::invalid_argument& e){
        return false;}
    catch (const std::out_of_range& e){
        return false;}
	catch (...) {
        return false;}
}

void	ScalarConverter::findType(const std::string& input){
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
	if (isInt(input)){
		_type = e_int;
		return ;
	}
	if (isFloat(input)){
		_type = e_float;
		return ;
	}
	if (isDouble(input)){
		_type = e_double;
		return ;
	}
	if (isChar(input)){
		_type = e_char;
		return ;
	}
	
	_type = 4;
}

int		ScalarConverter::getType(void ){
	return (_type);
}

void	ScalarConverter::remove_nl(std::string &str) {
    size_t length = str.length();
    if (length > 0 && str[length - 1] == '\n') {
        str.pop_back();
    }
}

std::string  ScalarConverter::get_pc(void){
	ScalarConverter::remove_nl(_pc);
	return(_pc);
}
std::string  ScalarConverter::get_pi(void){
	ScalarConverter::remove_nl(_pi);
	return(_pi);
}
std::string  ScalarConverter::get_pf(void){
	ScalarConverter::remove_nl(_pf);
	return(_pf);
}
std::string  ScalarConverter::get_pd(void){
	// _pd.erase(std::remove(_pd.begin(), _pd.end(), '\n'), _pd.end());
	ScalarConverter::remove_nl(_pd);
	return(_pd);
}