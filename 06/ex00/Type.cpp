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

void	ScalarConverter::findType(const std::string& input){
	try{
		if (onlyInt(input) && input.length() > 10){
        	double d = stod(input);
		d++;
		}
	} catch(...){
		_type = e_impossible;
		return ;
	}
	if (input.empty()){
		_type = e_impossible;
	}
	else if (!strcmp(input.c_str(), "inff") || !strcmp(input.c_str(), "nanf") || !strcmp(input.c_str(), "-inff") || !strcmp(input.c_str(), "+inff")){
		_type = e_float;
	}
	else if (!strcmp(input.c_str(), "inf") || !strcmp(input.c_str(), "nan") || !strcmp(input.c_str(), "-inf") || !strcmp(input.c_str(), "+inf")){
		_type = e_double;
	}
	else if (isInt(input)){
		_type = e_int;
	}
	else if (isFloat(input)){
		_type = e_float;
	}
	else if (isChar(input)){
		_type = e_char;
	}
	else if (isDouble(input)){
		_type = e_double;
	}
	else
		_type = 4;
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
	} catch (...){
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
	if (input[i] == '\0')
		return true;
	else
		return false;
}

bool ScalarConverter::isFloat(const std::string& input) {
    try {
		size_t len = input.length();
        double fl = stof(input);
		int dot = -1;
		fl++;
		for (int i = 0; input[i] != '\0'; i++){
			if (input[i] == '.')
				dot = i;
		}
		if (input[len - 1] == 'f' && dot != -1)
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
		int i = 0;
		while (input[i] != '\0'){
			if ((input[0] == '-' || input[0] == '+') && i == 0)
				i++;
			else if (!std::isdigit(input[i]) && input[i] != '.')
				return false;
			else if (input[i] == '.')
				dot++;
			i++;
		}
		if (dot > 1 && i > 1)
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
