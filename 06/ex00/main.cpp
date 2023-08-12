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
	// float 340282346638528859811704183484516925440.0
	// float -340282346638528859811704183484516925440.0000000000000000
	// to test the input/output
	// std::string input = "42..0";
	// char		k = .1;
	// char 	k = input.front();
	// float	k = std::numeric_limits<float>::infinity();
	// double 	k = 3333323.622;
	// char 	c = static_cast<char>(k);
	// int 	i = static_cast<int>(k);
	// float 	f = static_cast<float>(k);
	// double 	d = static_cast<double>(k);
	// std::cout << "c = " << c << std::endl << "i = " << i << std::endl << "f = " << f << std::endl << "d = " << d << std::endl;
	//		
	// secondary tester
	ScalarConverter::testValues("1");
    ScalarConverter::testValues("-1");
    ScalarConverter::testValues("+42");
    ScalarConverter::testValues("2147483647");
    ScalarConverter::testValues("-2147483648");
	ScalarConverter::testValues("+2147483647");
	ScalarConverter::testValues(".1");
    ScalarConverter::testValues("1.1");
    ScalarConverter::testValues("-inff");
    ScalarConverter::testValues("+inff");
    ScalarConverter::testValues("inff");
    ScalarConverter::testValues("nanf");
    ScalarConverter::testValues("1.111111111");
    ScalarConverter::testValues("inf");
    ScalarConverter::testValues("-inf");
    ScalarConverter::testValues("+inf");
    ScalarConverter::testValues("inf");
    ScalarConverter::testValues("nan");
    ScalarConverter::testValues("1233.00040040404");
    ScalarConverter::testValues("++1");
    ScalarConverter::testValues("--1");
    ScalarConverter::testValues("-");
    ScalarConverter::testValues("1ff");
    ScalarConverter::testValues("1f1");
    ScalarConverter::testValues(".40545");
    ScalarConverter::testValues("42.40545464454543434");
    ScalarConverter::testValues("1242.0022342");
		
    // ScalarConverter::testValues("545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03");
	// ScalarConverter::testValues("+2147483648");
    // ScalarConverter::testValues("-2147483649");
	// ScalarConverter::testValues("-2147483649");
    // ScalarConverter::testValues("2147483648");
    // ScalarConverter::testValues("12222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222233333333333333333333333333");
    // ScalarConverter::testValues("122222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222");
	return 1;
}
