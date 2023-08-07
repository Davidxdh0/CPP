#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits.h>
#include <string.h>
#include <iomanip>
#include <limits>
#include <cmath>

#define TESTS 1

enum enum_type {
	e_char = 0,
	e_float,
	e_int,
	e_double,
	e_impossible
};

class ScalarConverter {
	private:
		static char 		_char;
		static float		_float;
		static int			_int;
		static double		_double;
		static int			_type;
		static int			_digits;
		ScalarConverter();
	public:	
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static int		getType(void );
		static void		findType(const std::string& input);
		static void		converter(const std::string& input);

		static void		Impossible(const std::string& input);
		static void		convertint(const std::string& input);
		static void 	convertdouble(const std::string& input);
		static void		convertfloat(const std::string& input);
		static void		convertchar(const std::string& input);

		static void		printChar(const std::string& input);
		static void		printInt(void);
		static void		printFloat(void);
		static void		printDouble(void);

		class NonDisplayable : public std::exception
		{
		public:
			virtual const char* what() const throw(){
				return ("Non Displayable");
			}
		};

		class Impossible : public std::exception
		{
		public:
			virtual const char* what() const throw(){
				return ("Impossible");
			}
		};

			
};

#endif
