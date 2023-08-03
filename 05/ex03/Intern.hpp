#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#define TESTS 0

class Form;
class Intern {

	public:
		Intern();
		Intern(const std::string name, const std::string str);
		Intern( const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
	
		AForm*	makeForm(const std::string nameForm, std::string str);
		AForm*	createRobot(std::string str);
		AForm*	createPresident(std::string str);
		AForm*	createShrubbery(std::string str);
};

#endif
