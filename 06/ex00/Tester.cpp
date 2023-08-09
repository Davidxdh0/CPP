#include "ScalarConverter.hpp"

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
	ScalarConverter::remove_nl(_pd);
	return(_pd);
}

void ScalarConverter::testValues(const char* input) {
	std::cout << "input " << input << std::endl;
	ScalarConverter::converter(input);
	
	std::string array[4];
	if (!strcmp(input, "1"))
    	array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.0f", array[3] = "Double: 1.0";
	else if (!strcmp(input, "-1"))
		array[0] = "Char: Impossible", array[1] = "Int: -1", array[2] = "Float: -1.0f", array[3] = "Double: -1.0";
	else if (!strcmp(input, "+42"))
		array[0] = "Char: '*'", array[1] = "Int: 42", array[2] = "Float: 42.0f", array[3] = "Double: 42.0";
	else if (!strcmp(input, "2147483647"))
		array[0] = "Char: Not displayable", array[1] = "Int: 2147483647", array[2] = "Float: 2.14748e+09.0f", array[3] = "Double: 2.14748e+09.0";
	else if (!strcmp(input, "-2147483648"))
		array[0] = "Char: Impossible", array[1] = "Int: -2147483648", array[2] = "Float: -2.14748e+09.0f", array[3] = "Double: -2.14748e+09.0";
	else if (!strcmp(input, "1222222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: Impossible", array[3] = "Double: Impossible";
	else if (!strcmp(input, ".1"))
		array[0] = "Char: Not displayable", array[1] = "Int: 0", array[2] = "Float: 0.1f", array[3] = "Double: 0.1";
	else if (!strcmp(input, "-2147483649"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: Impossible", array[3] = "Double: Impossible";
	else if (!strcmp(input, "2147483648"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: Impossible", array[3] = "Double: Impossible";
	else if (!strcmp(input, "1.1"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.1f", array[3] = "Double: 1.1";
	else if (!strcmp(input, "-inff"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "+inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nanf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1.111111111"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.11111f", array[3] = "Double: 1.11111";
	else if (!strcmp(input, "-inff"))
    	array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "+inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nanf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1.111111111"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.11111f", array[3] = "Double: 1.11111";
	else if (!strcmp(input, "-inff"))
    array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "+inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inff"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nanf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1.111111111"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.11111f", array[3] = "Double: 1.11111";
	else if (!strcmp(input, "-inf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "inf"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nan"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1233.00040040404"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1233", array[2] = "Float: 1233f", array[3] = "Double: 1233";
	else if (!strcmp(input, "++1"))
		array[0] = "Char: '+'", array[1] = "Int: 43", array[2] = "Float: 43.0f", array[3] = "Double: 43.0";
	else if (!strcmp(input, "--1"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "-"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "+"))
		array[0] = "Char: '+'", array[1] = "Int: 43", array[2] = "Float: 43.0f", array[3] = "Double: 43.0";
	else if (!strcmp(input, "++"))
		array[0] = "Char: '+'", array[1] = "Int: 43", array[2] = "Float: 43.0f", array[3] = "Double: 43.0";
	else if (!strcmp(input, "--"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "1f1"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, ".f"))
		array[0] = "Char: '.'", array[1] = "Int: 46", array[2] = "Float: 46.0f", array[3] = "Double: 46.0";
	else if (!strcmp(input, "-1.f"))
		array[0] = "Char: Impossible", array[1] = "Int: -1", array[2] = "Float: -1.0f", array[3] = "Double: -1.0";
	else if (!strcmp(input, "-1f"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "-.f"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "f.1"))
		array[0] = "Char: 'f'", array[1] = "Int: 102", array[2] = "Float: 102.0f", array[3] = "Double: 102.0";
	else if (!strcmp(input, "f1."))
		array[0] = "Char: 'f'", array[1] = "Int: 102", array[2] = "Float: 102.0f", array[3] = "Double: 102.0";
	else if (!strcmp(input, "1.1"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.1f", array[3] = "Double: 1.1";
	else if (!strcmp(input, "-1.1"))
    array[0] = "Char: Impossible", array[1] = "Int: -1", array[2] = "Float: -1.1f", array[3] = "Double: -1.1";
	else if (!strcmp(input, "+1.1"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.1f", array[3] = "Double: 1.1";
	else if (!strcmp(input, "--1.1"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "1f1"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, "1ff"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, "1f1"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, ".40545"))
		array[0] = "Char: Not displayable", array[1] = "Int: 0", array[2] = "Float: 0.40545f", array[3] = "Double: 0.40545";
	else if (!strcmp(input, "42.40545464454543434"))
		array[0] = "Char: '*'", array[1] = "Int: 42", array[2] = "Float: 42.4055f", array[3] = "Double: 42.4055";
	else if (!strcmp(input, "1242.0022342"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1242", array[2] = "Float: 1242f", array[3] = "Double: 1242";
	else if (!strcmp(input, "545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03"))
		array[0] = "Char: Not displayable", array[1] = "Int: Impossible", array[2] = "Float: Impossible", array[3] = "Double: 5.45453e+131.0";
	else if (!strcmp(input, "+2147483647"))
		array[0] = "Char: Not displayable", array[1] = "Int: 2147483647", array[2] = "Float: 2.14748e+09.0f", array[3] = "Double: 2.14748e+09.0";
	else
	{
		std::cout << "array not found exiting" << std::endl;
		return ;
	}
	static int i = 0;
	i++;
	try {
		assert(ScalarConverter::get_pc() == array[0] && "PC value mismatch!");
		assert(ScalarConverter::get_pi() == array[1] && "PI value mismatch!");
		assert(ScalarConverter::get_pf() == array[2] && "PF value mismatch!");
		assert(ScalarConverter::get_pd() == array[3] && "PD value mismatch!");
		std::cout << "\033[32m" << "Test "<< i << " PASSED input " << input << std::endl;
		std::cout << "\033[0m" << "-------------------" << std::endl;
	}
	catch(...){
		std::cout << "failed" << std::endl;
	}
}