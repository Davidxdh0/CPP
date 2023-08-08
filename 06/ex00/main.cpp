#include "ScalarConverter.hpp"



int main(int argc, char *argv[]) {
	if (argc < 2 ){
		std::cout << "Not enough values for " << argv[0] << std::endl;
	}
	//	./tester.sh & normal
	//--------------------------
	if (argv[1])
		ScalarConverter::converter(argv[1]);
	// -------------------------
	// to test the input/output
	// std::string input = "42..0";
	// char		k = .1;
	// char 	k = input.front();
	// int 		k = static_cast<char>("");
	// double 	k = .1;
	// float 	k = 1f.;
	// char 	c = static_cast<char>(k);
	// int 		i = static_cast<int>(k);
	// float 	f = static_cast<float>(k);
	// double 	d = static_cast<double>(k);
	// std::cout << "c = " << c << std::endl << "i = " << i << std::endl << "f = " << f << std::endl << "d = " << d << std::endl;
	//		
	// secondary tester
	// ScalarConverter::testValues("1");
    // ScalarConverter::testValues("-1");
    // ScalarConverter::testValues("+42");
    // ScalarConverter::testValues("2147483647");
    // ScalarConverter::testValues("-2147483648");
	// ScalarConverter::testValues("+2147483647");
	// ScalarConverter::testValues(".1");
    // ScalarConverter::testValues("1.1");
    // ScalarConverter::testValues("-inff");
    // ScalarConverter::testValues("+inff");
    // ScalarConverter::testValues("inff");
    // ScalarConverter::testValues("nanf");
    // ScalarConverter::testValues("1.111111111");
    // ScalarConverter::testValues("inf");
    // ScalarConverter::testValues("-inf");
    // ScalarConverter::testValues("+inf");
    // ScalarConverter::testValues("inf");
    // ScalarConverter::testValues("nan");
    // ScalarConverter::testValues("1233.00040040404");
    // ScalarConverter::testValues("++1");
    // ScalarConverter::testValues("--1");
    // ScalarConverter::testValues("-");
    // ScalarConverter::testValues("1ff");
    // ScalarConverter::testValues("1f1");
    // ScalarConverter::testValues(".40545");
    // ScalarConverter::testValues("42.40545464454543434");
    // ScalarConverter::testValues("1242.0022342");
	// 			these exit
    // ScalarConverter::testValues("545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03");
	// ScalarConverter::testValues("+2147483648");
    // ScalarConverter::testValues("-2147483649");
	// ScalarConverter::testValues("-2147483649");
    // ScalarConverter::testValues("2147483648");
    // ScalarConverter::testValues("12222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333");
    // ScalarConverter::testValues("1222222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222");
	return 1;
}

void ScalarConverter::testValues(const char* input) {
	std::cout << "input " << input << std::endl;
	ScalarConverter::converter(input);
	
	std::string array[4];
	if (!strcmp(input, "1"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.0f", array[3] = "Double: 1.0";
	else if (!strcmp(input, "-1"))
		array[0] = "Char: Impossible", array[1] = "Int: -1", array[2] = "Float: -1.0f", array[3] = "Double: -1.0";
	else if (!strcmp(input, "+3"))
		array[0] = "Char: Not displayable", array[1] = "Int: 3", array[2] = "Float: 3.0f", array[3] = "Double: 3.0";
	else if (!strcmp(input, "2147483647"))
		array[0] = "Char: Impossible", array[1] = "Int: 2147483647", array[2] = "Float: 2.14748e+09.0f", array[3] = "Double: 2.14748e+09.0";
	else if (!strcmp(input, "-2147483648"))
		array[0] = "Char: Impossible", array[1] = "Int: -2147483648", array[2] = "Float: -2.14748e+09.0f", array[3] = "Double: -2.14748e+09.0";
	else if (!strcmp(input, "12222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333"))
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
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inff"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nanf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1.111111111"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.11111f", array[3] = "Double: 1.11111";
	else if (!strcmp(input, "-inff"))
    	array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "+inff"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inff"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nanf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1.111111111"))
		array[0] = "Char: Not displayable", array[1] = "Int: 1", array[2] = "Float: 1.11111f", array[3] = "Double: 1.11111";
	else if (!strcmp(input, "inf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "-inf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: -inff", array[3] = "Double: -inf";
	else if (!strcmp(input, "+inf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "inf"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: inff", array[3] = "Double: inf";
	else if (!strcmp(input, "nan"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: nanf", array[3] = "Double: nan";
	else if (!strcmp(input, "1233.00040040404"))
		array[0] = "Char: Impossible", array[1] = "Int: 1233", array[2] = "Float: 1233f", array[3] = "Double: 1233";
	else if (!strcmp(input, "++1"))
		array[0] = "Char: '+'", array[1] = "Int: 43", array[2] = "Float: 43.0f", array[3] = "Double: 43.0";
	else if (!strcmp(input, "--1"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "-"))
		array[0] = "Char: '-'", array[1] = "Int: 45", array[2] = "Float: 45.0f", array[3] = "Double: 45.0";
	else if (!strcmp(input, "1ff"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, "1f1"))
		array[0] = "Char: '1'", array[1] = "Int: 49", array[2] = "Float: 49.0f", array[3] = "Double: 49.0";
	else if (!strcmp(input, ".40545"))
		array[0] = "Char: Not displayable", array[1] = "Int: 0", array[2] = "Float: 0.40545f", array[3] = "Double: 0.40545";
	else if (!strcmp(input, "42.40545464454543434"))
		array[0] = "Char: '*'", array[1] = "Int: 42", array[2] = "Float: 42.4055f", array[3] = "Double: 42.4055";
	else if (!strcmp(input, "1242.0022342"))
		array[0] = "Char: Impossible", array[1] = "Int: 1242", array[2] = "Float: 1242f", array[3] = "Double: 1242";
	else if (!strcmp(input, "+42"))
    array[0] = "Char: '*'", array[1] = "Int: 42", array[2] = "Float: 42.0f", array[3] = "Double: 42.0";
	else if (!strcmp(input, "545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03"))
		array[0] = "Char: Impossible", array[1] = "Int: Impossible", array[2] = "Float: Impossible", array[3] = "Double: 5.45453e+131.0";
	else if (!strcmp(input, "+2147483647"))
    	array[0] = "Char: Impossible", array[1] = "Int: 2147483647", array[2] = "Float: 2.14748e+09.0f", array[3] = "Double: 2.14748e+09.0";
	else
	{
		std::cout << "array not found exiting" << std::endl;
		exit(1);
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