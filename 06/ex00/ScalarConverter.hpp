#ifndef SCALAR_HPP
#define SCALAR_HPP
#ifndef TESTS
#define TESTS 0
#endif

#include <iostream>   // stoi 
#include <sstream>    // stof 
#include <stdexcept>  // exception 
#include <limits.h>   // INT_MIN, INT_MAX 
#include <string.h>   // strcmp 
#include <limits>     // isnan, std::stod 
#include <cmath>      // std::fmod 
#include <cassert>    // assert 
#include <ctype.h>	  // isdigit, isalpha

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
		static std::string  _pc; //testing values - captures std::cout
		static std::string  _pi; //testing values - captures std::cout
		static std::string  _pf; //testing values - captures std::cout
		static std::string  _pd; //testing values - captures std::cout
		ScalarConverter();
	public:	
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static int		getType(void );
		static void		findType(const std::string& input);
		static void		converter(const std::string& input);
		static void		testValues(const char* input);

		static void		impossible(const std::string& input);
		static void		convertInt(const std::string& input);
		static void 	convertDouble(const std::string& input);
		static void		convertFloat(const std::string& input);
		static void		convertChar(const std::string& input);

		static void		printChar(const std::string& input);
		static void		printInt(void);
		static void		printFloat(void);
		static void		printDouble(void);
		
		static void			remove_nl(std::string &str);
		static std::string  get_pc(void);
		static std::string  get_pi(void);
		static std::string  get_pf(void);
		static std::string  get_pd(void);

		static bool	isDouble(const std::string& input);
		static bool	isChar(const std::string& input);
		static bool isFloat(const std::string& input); 
		static bool isInt(const std::string& input); 
};

#endif
