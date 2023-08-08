#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>   // stoi 
#include <sstream>    // stof 
#include <stdexcept>  // exception 
#include <limits.h>   // INT_MIN, INT_MAX 
#include <string.h>   // strcmp 
#include <limits>     // isnan, std::stod 
#include <cmath>      // std::fmod 
#include <cassert>    // assert 
#include <ctype.h>

#ifndef TESTS
#define TESTS 0
#endif
enum enum_type {
	e_char = 0,
	e_float,
	e_int,
	e_double,
	e_impossible
};
#define SET INTERCEPT ON FILE stdout ;
class ScalarConverter {
	private:
		static char 		_char;
		static float		_float;
		static int			_int;
		static double		_double;
		static int			_type;
		static int			_digits;
		static std::string  _pc;
		static std::string  _pi;
		static std::string  _pf;
		static std::string  _pd;
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

		static void testValues(const char* input);
		static std::string  get_pc(void);
		static std::string  get_pi(void);
		static std::string  get_pf(void);
		static std::string  get_pd(void);

		static bool	isDouble(const std::string& input);
		static bool	isChar(const std::string& input);
		static bool isFloat(const std::string& input); 
		static bool isInt(const std::string& input); 
		
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
