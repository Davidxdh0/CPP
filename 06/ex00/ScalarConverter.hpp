#ifndef SCALAR_HPP
#define SCALAR_HPP
#include <iostream>

class ScalarConverter {
	private:
		char 	_char;
		float	_float;
		int		_int;
		double	_double;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void		converter(const std::string& input);
		static void		convertint(const std::string& input);
		static void 	convertdouble(const std::string& input);
		static void		convertfloat(const std::string& input);
		static void		convertchar(const std::string& input);
			
};

#endif
