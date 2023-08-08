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

// you have to handle these pseudo literals as well 
// -inf, +inf and nan.

void testValues(const char* input) {
	std::cout << "input " << input << std::endl;
	ScalarConverter::converter(input);
	std::string array[4]; //= {"default", "default", "default", "default"};
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
	else
		exit(1);
	static int i = 0;
	i++;
	assert(ScalarConverter::get_pc() == array[0] && "PC value mismatch!");
    assert(ScalarConverter::get_pi() == array[1] && "PI value mismatch!");
    assert(ScalarConverter::get_pf() == array[2] && "PF value mismatch!");
    assert(ScalarConverter::get_pd() == array[3] && "PD value mismatch!");
	std::cout << "\033[32m" << "Test "<< i << " PASSED input " << input << std::endl;
	std::cout << "\033[0m" << "-------------------" << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc < 2 && argv[0]){
		std::cout << "Not enough values" << std::endl;
		return 1;
	}
	// char k = .1;
	// std::string input = "42..0";
	// char k = input.front();
	// int k = static_cast<char>("");
	// double k = .1;
	// float k = 11.f;

	// char c = static_cast<char>(k);
	// int i = static_cast<int>(k);
	// float f = static_cast<float>(k);
	// double d = static_cast<double>(k);
	// std::cout << "c = " << c << std::endl << "i = " << i << std::endl << "f = " << f << std::endl << "d = " << d << std::endl;
	// -------------------
	// testValues(argv[1]);

	//	tester.sh & normal
	//--------------------------
	//--------------------------
	//--------------------------
	ScalarConverter::converter(argv[1]);
	//--------------------------
    //--------------------------
	//--------------------------
	//		secondary tester
	// testValues("1");
    // testValues("-1");
    // testValues("+3");
    // testValues("2147483647");
    // testValues("-2147483648");
    // testValues("12222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333");
    // testValues("1222222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222");
    // testValues(".1");
    // testValues("-2147483649");
    // testValues("2147483648");
    // testValues("1.1");
    // testValues("-inff");
    // testValues("+inff");
    // testValues("inff");
    // testValues("nanf");
    // testValues("1.111111111");
    // testValues("inf");
    // testValues("-inf");
    // testValues("+inf");
    // testValues("inf");
    // testValues("nan");
    // testValues("1233.00040040404");
    // testValues("++1");
    // testValues("--1");
    // testValues("-");
    // testValues("1ff");
    // testValues("1f1");
    // testValues(".40545");
    // testValues("42.40545464454543434");
    // testValues("1242.0022342");
    // testValues("545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03");

    
	return 1;
}
